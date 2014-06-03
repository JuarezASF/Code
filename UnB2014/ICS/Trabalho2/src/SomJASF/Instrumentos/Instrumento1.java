package SomJASF.Instrumentos;
import SomJASF.RAN;
import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.UnidadeH;

public class Instrumento1 extends UnidadeH implements Instrumento{
	
	private RAN ran;
	private Envoltoria env;
	private Oscilador osci;
	
	/**
	 * Cria Instrumento1 padrão: 
	 * f = 440HZ
	 * f_ran = 60
	 * d = 5
	 * a = 2f
	 */
	public Instrumento1(){
		super();
		initialize();

		setH(1.0f);
		setGanho(1f);
		setLambda(0.5f);
		
		ran.setGanho(env);
		ran.setGanho(10);
		ran.setF_ruido(60);
		osci.setDispositivoAmplitude(ran);
		osci.setFrequencia(440);
		osci.setDuracao(5f);
	}
	
	/**
	 * Inicializa env com a curva padrão,
	 * ran com o cosntrutor padrão
	 */
	private void initialize(){
		//define envoltoria padrão
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0f);
		curva.addPonto(60f, 1000f);
		curva.addPonto(450f, 1000f);
		curva.addPonto(720f, 0f);
		env = new Envoltoria();
		env.setCURVA(curva);
		
		ran = new RAN();
		osci = getOscilador();
	}
	
	public void setGanhoRuido(float G){
		ran.setGanho(G);
	}
	
	public void setF_ruido(float f_ruido){
		ran.setF_ruido(f_ruido);
	}
	
	public void setFrequencia(float f){
		osci.setFrequencia(f);
	}
	
	public void setDuracao(float d){
		this.duracao = d;
		osci.setDuracao(d);
	}
	
	public void setGanho(float g_ruido){}
	
	public void setOsciFrequenciaA(float g){}
	
	public void setOsciFrequenciaF(float f){}

	public void reset(){
		if(osci != null)this.osci.reset();
	}

}
