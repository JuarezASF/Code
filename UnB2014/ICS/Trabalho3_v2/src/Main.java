import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Somador;
import sintese.Som;
import sintese.Multiplicador;

public class Main {
	
	/**
	 * Testa o OsciladorRissetContinuo.
	 * Tudo parece funcionar como esperado!
	 */
	public static void demo1(){
		
		float var = 0.2f;
		float Fc = 440;
		float T0 = 2;
		OsciladorRissetContinuo osci1 = new OsciladorRissetContinuo(440, T0, Fc, var);
		osci1.setCrescente(true);
		Som som = new Som(osci1, 10);
		
		som.visualiza();
	}
	
	/**
	 * Testa a classe EnvoltoriaAmplitudeRisset.
	 * Está funcionando!
	 */
	public static void demo2(){
		EnvoltoriaAmplitudeRisset amp = new EnvoltoriaAmplitudeRisset(400, 2, 440, 0.2f);
		Oscilador osci = new Oscilador();
		
		osci.setDispositivoAmplitude(amp);
		osci.setFrequencia(440);
		osci.setSR(44100);
		
		Som som = new Som(osci, 5);
		
		som.visualiza();
	}
	
	/**
	 * Testa a classe EnvoltoriaFrequenciaRisset.
	 * Acho que está funcionando bem. 
	 */
	public static void demo3(){
		EnvoltoriaFrequenciaRisset amp = new EnvoltoriaFrequenciaRisset(880, 2);
		Oscilador osci = new Oscilador();
		
		osci.setDispositivoAmplitude(amp);
		osci.setFrequencia(440);
		osci.setSR(44100);
		osci.setGanho(100);
		
		Som som = new Som(osci, 5);
		
		som.visualiza();
		
	}
	
	/**
	 * Testa composição de OsciladorRissetContinuo
	 */
	public static void demo4(){
		float var = 0.1f;
		float Fc = 440;
		float T0 = 5;
		float F0 = Fc/4.0f;
		
		
		OsciladorRissetContinuo osci1 = new OsciladorRissetContinuo(F0, T0, Fc, var);
		OsciladorRissetContinuo osci2 = new OsciladorRissetContinuo(2*F0, T0, Fc, var);
		OsciladorRissetContinuo osci3 = new OsciladorRissetContinuo(4*F0, T0, Fc, var);
		OsciladorRissetContinuo osci4 = new OsciladorRissetContinuo(8*F0, T0, Fc, var);
		OsciladorRissetContinuo osci5 = new OsciladorRissetContinuo(16*F0, T0, Fc, var);
			
		Somador sum1 = new Somador(osci1, osci2);
		Somador sum2 = new Somador(osci3, osci4);
		Somador sum3 = new Somador(sum2, osci5);
		Somador sum4 = new Somador(sum3, sum1);
		
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0.75);
		curva.addPonto(720f, 0.75);
		
		Envoltoria ganho = new Envoltoria();
		ganho.setCURVA(curva);
		ganho.setDuracao(10);
		
		Multiplicador mult = new Multiplicador(ganho, sum4);
		
		Som som = new Som(mult, 10);
		
		som.visualiza();
	}
	
	public static void main(String[] args){
		demo4();
	}

}
