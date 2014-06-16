import sintese.Oscilador;
import sintese.Somador;
import sintese.Som;

public class Main {
	
	public static void meuDemo1(){
		
		float var = 20;
		float Fc = 440;
		float T0 = 2;
		
		
		OsciladorShepard osci1 = new OsciladorShepard(220, T0, Fc, var);
		OsciladorShepard osci2 = new OsciladorShepard(440, T0, Fc, var);
		OsciladorShepard osci3 = new OsciladorShepard(880, T0, Fc, var);
		
		Somador sum1 = new Somador(osci1, osci2);
		Somador sum2 = new Somador(sum1, osci3);
		
		Som som = new Som(sum2, 10);
		
		som.visualiza();
	}
	
	public static void meuDemo2(){
		
		EnvoltoriaAmplitudeShepard amp = new EnvoltoriaAmplitudeShepard(880, 2, 440, 0.1f);
		Oscilador osci = new Oscilador();
		
		osci.setDispositivoAmplitude(amp);
		osci.setFrequencia(440);
		osci.setSR(44100);
		
		Som som = new Som(osci, 5);
		
		som.visualiza();
	}
	
	public static void main(String[] args){
		meuDemo2();
	}

}
