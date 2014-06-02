package SomJASF.Instrumentos;

import SomJASF.RAN;
import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Somador;
import sintese.UnidadeH;


public class Instrumento2 extends UnidadeH{
	
	private RAN ran;
	private Oscilador osci_out, osciA;
	private Somador sum;
	private float f_medio;
	private Envoltoria f_medio_env;
	
	public Instrumento2(){
		super();
		setLambda(0.5f);
		ran = new RAN(1.f, 60);
		f_medio = 440;
		f_medio_env = constantEnvoltoria(f_medio);
		sum = new Somador(f_medio_env, ran);
		
		osciA = new Oscilador(10, 1, 0);
		osci_out = getOscilador();
		osci_out.setDispositivoAmplitude(osciA);
		osci_out.setDispositivoFrequencia(sum);
		
		
	}
	
	private Envoltoria constantEnvoltoria(float constant){
		Curva curva = new Curva(720);
		curva.addPonto(0f, constant);
		curva.addPonto(720f, constant);
		Envoltoria env = new Envoltoria();
		env.setCURVA(curva);
		
		return env;
	}
	
	public void setGanho(float g){
		osciA.setGanho(g);
	}
	
	public void setFrequenciaAmplitude(float f){
		osciA.setFrequencia(f);
	}
	
	public void setfrequencia(float f){
		f_medio = f;
		f_medio_env = constantEnvoltoria(f_medio);
		sum = new Somador(f_medio_env, ran);
		osci_out.setDispositivoFrequencia(sum);	
	}
	
	public void setGanhoRuido(float g){
		ran.setGanho(g);
	}
	
	public void setFRuido(float f){
		ran.setF_ran(f);
	}
	
}
