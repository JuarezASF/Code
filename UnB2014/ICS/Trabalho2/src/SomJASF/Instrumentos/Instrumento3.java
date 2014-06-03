package SomJASF.Instrumentos;

import SomJASF.RAN;
import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Somador;
import sintese.UnidadeH;


public class Instrumento3 extends UnidadeH implements Instrumento{
	
	private RAN ran;
	private Oscilador osci_out, osciF;
	private Somador sum1, sum2;
	private float f_medio;
	private Envoltoria f_medio_env, ganhoEnv;
	
	public Instrumento3(){
		//propriedades da unidadeH
		super();
		setLambda(0.5f);
		
		//RAN
		ran = new RAN(100f, 10);//RAN(float amplitude, float new_f_ran)
		
		//Frequência média
		f_medio = 440;
		f_medio_env = constantEnvoltoria(f_medio);
		
		//F medio + RAN
		sum1 = new Somador(f_medio_env, ran);
		

		osciF = new Oscilador(1, 1, 0); //Oscilador(float a, float f, float p) 
		sum2 = new Somador(sum1, osciF);

		//define envoltoria padrão
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0f);
		curva.addPonto(60f, 1000f);
		curva.addPonto(450f, 1000f);
		curva.addPonto(720f, 0f);
		ganhoEnv = new Envoltoria();
		ganhoEnv.setCURVA(curva);

		
		osci_out = getOscilador();
		osci_out.setDispositivoAmplitude(ganhoEnv);
		osci_out.setDispositivoFrequencia(sum2);
		
		
	}
	
	private Envoltoria constantEnvoltoria(float X){
		Curva curva = new Curva(720);
		curva.addPonto(0f, X);
		curva.addPonto(720f, X);
		Envoltoria env = new Envoltoria();
		env.setCURVA(curva);
		
		return env;
	}
	
	public void setGanho(float g){
		ganhoEnv.setGanho(g);
	}

	public void setDuracao(float d){
		this.duracao = d;
		osci_out.setDuracao(d);
	}
	
	public void setOsciFrequenciaF(float f){
		osciF.setFrequencia(f);
	}
	

	public void setOsciFrequenciaA(float g){
		osciF.setGanho(g);
	}


	public void setFrequencia(float f){
		f_medio = f;
		f_medio_env = constantEnvoltoria(f_medio);
		f_medio_env.setDuracao(this.duracao);
		sum1 = new Somador(f_medio_env, ran);
		sum2 = new Somador(sum1, osciF);
		osci_out = getOscilador();
		osci_out.setDispositivoFrequencia(sum2);
	}
	
	public void setGanhoRuido(float g){
		ran.setGanho(g);
	}
	
	public void setF_ruido(float f){
		ran.setF_ruido(f);
	}
	
}
