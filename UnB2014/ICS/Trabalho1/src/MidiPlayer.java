import java.awt.Dimension;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.MetaMessage;
import javax.sound.midi.MidiDevice;
import javax.sound.midi.MidiDevice.Info;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiMessage;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Receiver;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Soundbank;
import javax.sound.midi.Synthesizer;
import javax.sound.midi.Track;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.Line;
import javax.sound.sampled.Mixer;
import javax.sound.sampled.SourceDataLine;
import javax.swing.SwingUtilities;

import com.sun.media.sound.AudioSynthesizer;
import com.sun.media.sound.SF2Soundbank;


public class MidiPlayer {

	private File      arqMidi;
	private Sequencer sequenciador;
	private Sequence  sequencia;
	private long tickPosition;
	
	private Soundbank banco;
	
	private int volumeATUAL;
	private Receiver receptor;
	Synthesizer softsynth;
	

	final int MESSAGEM_ANDAMENTO = 0x51;  
	final int FORMULA_DE_COMPASSO = 0x58;
	final int MENSAGEM_TONALIDADE = 0x59;  

	AudioFormat format;
	Mixer synthmixer = null;
	SourceDataLine line = null;
	boolean synth_loaded = false;
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
		 
		 banco = MidiSystem.getSynthesizer().getDefaultSoundbank();
		 softsynth = findAudioSynthesizer();
		 final AudioSynthesizer synth = findAudioSynthesizer();

			Properties p = getConfig();
			Map<String, Object> ainfo = new HashMap<String, Object>();

			try {

				format = new AudioFormat(Float.parseFloat(p
						.getProperty("samplerate", "44100")), Integer
						.parseInt(p.getProperty("bits", "16")), Integer
						.parseInt(p.getProperty("channels", "2")), true, false);
				
				int latency = Integer.parseInt(p.getProperty("latency", "200")) * 1000;
				
				String devname = p.getProperty("devicename");
				if (devname != null) {
					Mixer.Info selinfo = null;
					for (Mixer.Info info : AudioSystem.getMixerInfo()) {
						Mixer mixer = AudioSystem.getMixer(info);
						boolean hassrcline = false;
						for (Line.Info linfo : mixer.getSourceLineInfo())
							if (linfo instanceof javax.sound.sampled.DataLine.Info)
								hassrcline = true;
						if (hassrcline) {
							if (info.getName().equals(devname)) {
								selinfo = info;
								break;
							}
						}
					}
					if (selinfo != null) {
						synthmixer = AudioSystem.getMixer(selinfo);
						try {
							synthmixer.open();
							
							int bufferSize = (int)							
								(format.getFrameSize() * format.getFrameRate() 
								* latency / 1000000f);
							if(bufferSize < 500) bufferSize = 500;
								
							DataLine.Info dataLineInfo = new DataLine.Info(
									SourceDataLine.class, format, bufferSize);
							if (synthmixer.isLineSupported(dataLineInfo))
								line = (SourceDataLine) synthmixer
										.getLine(dataLineInfo);
														
							line.open(format, bufferSize);
							line.start();
																					
						} catch (Throwable t) {
							t.printStackTrace();
							synthmixer = null;
						}
					}//end if selinf0 == null
				}
				
				//ainfo.put("multi threading", true);
				ainfo.put("format", format);
				ainfo.put("max polyphony", Integer.parseInt(p.getProperty(
						"polyphony", "64")));				
				ainfo.put("latency", Long.parseLong(p.getProperty("latency",
						"200")) * 1000L);

				ainfo.put("interpolation", p.getProperty("interpolation"));                
             String largemode = p.getProperty("largemode");
             if(largemode == null) largemode = "false";
             ainfo.put("large mode", largemode.equalsIgnoreCase("true"));

			} catch (Throwable t) {
				t.printStackTrace();
			}
         
			synth.open(line, ainfo);
			softsynth = synth;
			sequenciador.getTransmitter().setReceiver(
					softsynth.getReceiver());
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}


	
	public AudioSynthesizer findAudioSynthesizer()
			throws MidiUnavailableException {
		// First check if default synthesizer is AudioSynthesizer.
		Synthesizer synth = MidiSystem.getSynthesizer();
		if (synth instanceof AudioSynthesizer)
			return (AudioSynthesizer) synth;

		// If default synhtesizer is not AudioSynthesizer, check others.
		Info[] infos = MidiSystem.getMidiDeviceInfo();
		for (int i = 0; i < infos.length; i++) {
			MidiDevice dev = MidiSystem.getMidiDevice(infos[i]);
			if (dev instanceof AudioSynthesizer)
				return (AudioSynthesizer) dev;
		}

		// No AudioSynthesizer was found, return null.
		return null;
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
	  
	  public void loadSoundbank(File newsbkfile) {
			try {

				Soundbank newsbk = MidiSystem.getSoundbank(newsbkfile);
				
				softsynth.unloadAllInstruments(banco);
				banco = newsbk;
				softsynth.loadAllInstruments(banco);
			} catch (Throwable e1) {
				System.out.println(e1.getMessage());
			}

		}

	  private static File userDir = new File(".");
	  private static String CONFIG_FILE_NAME = "SimpleMidiPlayer.xml";
	  private static File configFile = new File(userDir, CONFIG_FILE_NAME);
	  private static Properties configp = null;

	  public static Properties getConfig() {
			synchronized (configFile) {

				if (configp != null) {
					Properties p = new Properties();
					p.putAll(configp);
					return p;
				}
				Properties p = new Properties();
				if (configFile.exists()) {
					FileInputStream fis;
					try {
						fis = new FileInputStream(configFile);
						try {
							p.loadFromXML(fis);
						} finally {
							fis.close();
						}
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
				return p;

			}
		}
}//fim da classe
