import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Somador;
import sintese.UnidadeH;


public class Instrumento2 extends UnidadeH{
	
	private RAN ran;
	private Oscilador osci;
	private Somador sum;
	private float f_medio;
	private Envoltoria f_medio_env, ganhoEnv;
	
	public Instrumento2(){
		super();
		setLambda(0.5f);
		ran = new RAN(20f, 10);
		f_medio = 440;
		f_medio_env = constantEnvoltoria(f_medio);
		sum = new Somador(f_medio_env, ran);

		//define envoltoria padrão
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0f);
		curva.addPonto(60f, 1000f);
		curva.addPonto(450f, 1000f);
		curva.addPonto(720f, 0f);
		ganhoEnv = new Envoltoria();
		ganhoEnv.setCURVA(curva);

		
		osci = getOscilador();
		osci.setDispositivoAmplitude(ganhoEnv);
		osci.setDispositivoFrequencia(sum);
		
		
		
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
		osci.setDuracao(d);
	}
	
	public void setFrequencia(float f){
		f_medio = f;
		f_medio_env = constantEnvoltoria(f_medio);
		f_medio_env.setDuracao(this.duracao);

		osci = getOscilador();
		sum = new Somador(f_medio_env, ran);
		osci.setDispositivoFrequencia(sum);	
	}
	
	public void setGanhoRuido(float g){
		ran.setGanho(g);
	}
	
	public void setFrequenciaRuido(float f){
		ran.setF_ruido(f);
	}
	
}
