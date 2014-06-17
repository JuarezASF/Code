import java.awt.Dimension;

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
		float T0 = 15f;
		float F0 = Fc/4.0f;
		float duracao = 30f;
		
		
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
		ganho.setDuracao(duracao);
		
		Multiplicador mult = new Multiplicador(ganho, sum4);
		
		Som som = new Som(mult, duracao);
		
		som.visualiza();
	}
	
	/**
	 * Testa composição de osciladores com arrays
	 */
	public static void demo5(){
		float var = 0.1f;
		float Fc = 440;
		float T0 = 15f;
		float F0 = Fc/8.0f;
		float duracao = 30f;
		
		
		OsciladorRissetContinuo[] osci = new OsciladorRissetContinuo[7];
		
		for(int i = 0; i < 7; i++){
			float Fi = F0*((float )Math.pow(2.0, i));
			osci[i] = new OsciladorRissetContinuo(Fi, T0, Fc, var);
		}
		
		for(int i = 0; i < 7; i++){
			osci[i].setCrescente(true);
		}
		
		Somador[] sum = new Somador[6];
		sum[0] = new Somador(osci[0], osci[1]);
		for(int i = 1; i < 6; i++){
			sum[i] = new Somador(sum[i-1], osci[i+1]);
		}
		
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0.75);
		curva.addPonto(720f, 0.75);
		
		Envoltoria ganho = new Envoltoria();
		ganho.setCURVA(curva);
		ganho.setDuracao(duracao);
		
		Multiplicador mult = new Multiplicador(ganho, sum[5]);
		
		Som som = new Som(mult, duracao);
		
		som.visualiza();
		
		
	}
	
	/**
	 * Testa interface GUI
	 */
	public static void demo6(){
		GUI gui = new GUI();
		gui.setVisible(true);
		gui.setSize(new Dimension(220, 450));
	}
	
	/**
	 * Testa class efeito Risset Continuo
	 */
	public static void demo7(){
		EfeitoRissetContinuo efeito = new EfeitoRissetContinuo();
		efeito.setT0(5f);
		efeito.setDuracao(10f);
		efeito.setFc(220);
		efeito.setCrescente(true);
		efeito.setVar(0.1f);
		
		Som som = efeito.getSom();
		
		som.visualiza();
	}
	
	public static void demo8(){
		OsciladorRissetContinuo osci = new OsciladorRissetContinuo();
		osci.setFi(880);
		osci.setT0(0.49f);
		
		//OsciladorRissetContinuo osci2 = new OsciladorRissetContinuo();
		//osci2.setFi(440);
		
		//Somador sum = new Somador(osci, osci2);
		
		Som som = new Som(osci, 1);
		som.visualiza();
	}
	
	public static void main(String[] args){
		demo6();
	}

}
