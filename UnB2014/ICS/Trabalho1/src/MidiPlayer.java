import java.awt.Dimension;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.MetaMessage;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiMessage;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Receiver;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;

import com.sun.media.sound.SF2Soundbank;


public class MidiPlayer {

	private File      arqMidi;
	private Sequencer sequenciador;
	private Sequence  sequencia;
	private long tickPosition;
	
	private int volumeATUAL;
	private Receiver receptor;
	

	final int MESSAGEM_ANDAMENTO = 0x51;  
	final int FORMULA_DE_COMPASSO = 0x58;
	final int MENSAGEM_TONALIDADE = 0x59;  

	
	public MidiPlayer(String nomeDoArquivo){
		try{
		arqMidi = new File(nomeDoArquivo);
		//load na sequência
		sequencia = MidiSystem.getSequence(arqMidi);
		
		//prepata o sequenciador
		sequenciador = MidiSystem.getSequencer();
		sequenciador.setSequence(sequencia);
		sequenciador.open();             
		espera(500);
		
		tickPosition = 0;
		
		volumeATUAL  = 75;
		//----Operação crucial para a implementação correta do volume-----
		 receptor = sequenciador.getTransmitters().iterator().next().getReceiver();
		 sequenciador.getTransmitter().setReceiver(receptor);
		
		 //INICIALIZA VOLUME
		 inicializaVolume(volumeATUAL);
		}
		catch(MidiUnavailableException e1) {
			System.out.println(e1+" : Dispositivo midi não disponível.");
		}
		catch(InvalidMidiDataException e2) {
				System.out.println(e2+" : Erro nos dados midi."); 
				}
		catch(IOException e3) { 
			System.out.println(e3+" : O arquivo midi não foi encontrado."); 
                                                     System.out.println("Sintaxe: "+"java TocaMidi arquivo.mid"); 		                                   
		                                   }
		}

	static void espera(int miliseg)
	{  
		try { Thread.sleep(miliseg);
		    }
		catch(InterruptedException e) { }
	}
	
	public long getDuracao(){
		/**
		 * retorna duração sem segundos
		 * */
		long duracao     = sequencia.getMicrosecondLength()/1000000;
		return duracao;
	}
	
	public int getResolucao(){
		int  resolucao   = sequencia.getResolution();
		return resolucao;
	}
	
	public long getTotaltiques(){
		long totaltiques = sequencia.getTickLength();
		return totaltiques;
	}
	
	public float getDuracaoTique(){
		long duracao     = sequencia.getMicrosecondLength()/1000000;
		long totaltiques = sequencia.getTickLength();
		float durtique       = (float)duracao/totaltiques;
		
		return durtique;
	}
	
	public float getDurSeminima(){
		float durTique = getDuracaoTique();
		int resolucao = getResolucao();
		float durseminima    = durTique*resolucao;
		
		return durseminima;
	}
	
	public float getBpm(){
		float durseminima = this.getDurSeminima();
		float bpm            = 60/durseminima;
		
		return bpm;
	}
	
	public int getTotalSeminimas(){
		long duracao = this.getDuracao();
		float durseminima = this.getDurSeminima();
		int   totalseminimas = (int)(duracao/durseminima);
	
		return totalseminimas;
	}

	public String getFileName(){
		String file = arqMidi.getName();
	
		return file;
	}
	
	public void pause(){
		/**
		 * para a exibição e mantém dado da posição em que parou*/
		tickPosition = sequenciador.getTickPosition();
		sequenciador.stop();
	}
	
	public void stop(){
		/**
		 * para a execução e seta a posição para o início*/
		tickPosition = 0;
		sequenciador.stop();
	}

	public void play(){
		/**
		 * dá start no sequenciador. continua de onde tinha parado
		 * se o arquivo acabou de ser aberto, começa do começo.
		 * se o arquivo tiver terminado, não toca(acho)
		 * */
		sequenciador.setTickPosition(tickPosition);
		sequenciador.start();
	}
	
	public void goTo(int segundos){
		/**
		 * passa a música para a posição especificada em segundos
		 * */
		
		//conversão segundos -> tiques
		//pois a classe Java só possui posicionamento em tiques
		long goTo = segundos*(getTotaltiques()/getDuracao());
		
		tickPosition = goTo;
		sequenciador.setTickPosition(tickPosition);
	}
	
	public long getTime(){
		/**
		 * RETORNA O TEMPO DE EXECUÇÃO EM SEGUNDOS
		 * */
		  //long  posicao = sequenciador.getMicrosecondPosition();
			long  posicao = sequenciador.getTickPosition();
		  
		  long   seg     = Math.round(posicao*getDuracaoTique());
	
		  return seg;
	}
	
	void setAndamento(int bpm) throws InvalidMidiDataException{
		/**
		 * set no andamento da música.
		 * recebe argumento em bpm*/
      Track[] trilhas = sequencia.getTracks();

      MetaMessage mensagemDeAndamento = new MetaMessage();
      int microssegundos = (int)(60000000.0 / bpm);

      sequenciador.stop();

      //cria msg
      byte dados[] = new byte[3];
      dados[0] = (byte)(microssegundos >>> 16);
      dados[1] = (byte)(microssegundos >>> 8);
      dados[2] = (byte)(microssegundos);
      mensagemDeAndamento.setMessage(0x51, dados, 3);
      
      //adiciona msg a todas as trilhas
      for(int i=0; i<trilhas.length; i++)
    	  trilhas[i].add(new MidiEvent(mensagemDeAndamento, 0));
     
      sequenciador.start();
    }
	
	private String getTonalidade(Track trilha) 
    {    
		String stonalidade = "Não Encontrada!";
		for(int i = 0; i < trilha.size(); i++){
	       MidiMessage mensagem = trilha.get(i).getMessage();
	              
	       if(((MetaMessage)mensagem).getType() == MENSAGEM_TONALIDADE)    
		       {
		            MetaMessage mm        = (MetaMessage)mensagem;
		            byte[]     data       = mm.getData();
		            byte       tonalidade = data[0];
		            byte       maior      = data[1];
		
		            String       smaior = "Maior";
		            if(maior==1) smaior = "Menor";

		            if(smaior.equalsIgnoreCase("Maior"))
		            {
		                switch (tonalidade)
		                {
		                    case -7: stonalidade = "Dób Maior"; break;
		                    case -6: stonalidade = "Solb Maior"; break;
		                    case -5: stonalidade = "Réb Maior"; break;
		                    case -4: stonalidade = "Láb Maior"; break;
		                    case -3: stonalidade = "Mib Maior"; break;
		                    case -2: stonalidade = "Sib Maior"; break;
		                    case -1: stonalidade = "Fá Maior"; break;
		                    case  0: stonalidade = "Dó Maior"; break;
		                    case  1: stonalidade = "Sol Maior"; break;
		                    case  2: stonalidade = "Ré Maior"; break;
		                    case  3: stonalidade = "Lá Maior"; break;
		                    case  4: stonalidade = "Mi Maior"; break;
		                    case  5: stonalidade = "Si Maior"; break;
		                    case  6: stonalidade = "Fá# Maior"; break;
		                    case  7: stonalidade = "Dó# Maior"; break;
		                }
		            }//fim maior

            else if(smaior.equalsIgnoreCase("Menor"))
            	{
                switch (tonalidade)
                	{
                    case -7: stonalidade = "Láb Menor"; break;
                    case -6: stonalidade = "Mib Menor"; break;
                    case -5: stonalidade = "Sib Menor"; break;
                    case -4: stonalidade = "Fá Menor"; break;
                    case -3: stonalidade = "Dó Menor"; break;
                    case -2: stonalidade = "Sol Menor"; break;
                    case -1: stonalidade = "Ré Menor"; break;
                    case  0: stonalidade = "Lá Menor"; break;
                    case  1: stonalidade = "Mi Menor"; break;
                    case  2: stonalidade = "Si Menor"; break;
                    case  3: stonalidade = "Fá# Menor"; break;
                    case  4: stonalidade = "Dó# Menor"; break;
                    case  5: stonalidade = "Sol# Menor"; break;
                    case  6: stonalidade = "Ré# Menor"; break;
                    case  7: stonalidade = "Lá# Menor"; break;
                	}//fim switch
            	}//fim menor
		       }//fim do if MSG_TONALIDADE
			}//fim do for
		
		return stonalidade;
		}//fim da rotina
	
	public String getTonalidade() {
		/**retorna tonalidade em String. 
		 * se nenhuma mensagem de tonalidade for encontrada,
		 * retorna String "Não encontrado"*/
		Track[] trilhas = sequencia.getTracks();
		String tonalidade = "";
		
		tonalidade = getTonalidade(trilhas[0]);
		
		return tonalidade;
		
	}
	
	private String getFormulaDeCompasso(Track trilha)
    {   int p=1;
        int q=1;
        String formula = "?/?";

        for(int i=0; i<trilha.size(); i++)
        {
          MidiMessage m = trilha.get(i).getMessage();
          if(m instanceof MetaMessage) 
          {
            if(((MetaMessage)m).getType()==FORMULA_DE_COMPASSO)
            {
                MetaMessage mm = (MetaMessage)m;
                byte[] data = mm.getData();
                p = data[0];
                q = (int) Math.pow(2, data[1]);
                formula = p + "/" + q;
                return formula;
            }
          }
        }
        return formula;
    }
	
	public String getFormulaDeCompasso(){
		/**
		 * retorna fórmula de compasso na forma pronta String p/q
		 */
	 
		Track[] trilhas = sequencia.getTracks();
		return getFormulaDeCompasso(trilhas[0]);
	}
	
	//---- Método para atribuir um valor inicial ao volume -------	
	  private void inicializaVolume(int valor)
	  {
	      ShortMessage mensagemDeVolume = new ShortMessage();
	      for(int i=0; i<16; i++)
	      {
             try { mensagemDeVolume.setMessage(ShortMessage.CONTROL_CHANGE, i, 7, valor);
                   receptor.send(mensagemDeVolume, -1);
                 }
             catch (InvalidMidiDataException e1) {}
	      }
	  } 
	  
	  public void setVolume(int valor){
		  /**
		   * Estamos usando 7 bits para o volume.
		   * 0: sem som
		   * 127: som com intensidade máxima
		   * */
		  ShortMessage mensagemDeVolume = new ShortMessage();
          for(int i=0; i<16; i++)
          {
              try { 
            	  mensagemDeVolume.setMessage(ShortMessage.CONTROL_CHANGE, i, 7, valor);
                  receptor.send(mensagemDeVolume, -1);
                  }
              catch (InvalidMidiDataException e1) {}
          }
          volumeATUAL = valor;
	  }
	  
	  public int getVolume(){
		  return volumeATUAL;
	  }
	  
}//fim da classe
