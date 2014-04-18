import java.io.File;
import java.io.IOException;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;


public class MidiPlayer {

	private File      arqMidi;
	private Sequencer sequenciador;
	private Sequence  sequencia;
	long tickPosition;
	
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
		tickPosition = sequenciador.getTickPosition();
		sequenciador.stop();
	}
	
	public void stop(){
		tickPosition = 0;
		sequenciador.stop();
	}

	public void play(){
		sequenciador.setTickPosition(tickPosition);
		sequenciador.start();
	}
	
	public void goTo(int segundos){
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
	
	
}
