package SomJASF.Instrumentos;
import SomJASF.RAN;
import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.UnidadeH;

public class Instrumento1 extends UnidadeH{
	
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
		
		env.setGanho(10);
		env.setDuracao(1);
		ran.setGanhoDispositivo(env);
		ran.setF_ran(60);
		osci.setDispositivoAmplitude(ran);
		osci.setFrequencia(440);
		

		
	}
	
	/**
	 * Inicializa env com a curva padrão,
	 * ran com o cosntrutor padrão
	 */
	private void initialize(){
		//define envoltoria padrão
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0f);
		curva.addPonto(10f, 1000f);
		curva.addPonto(680f, 1000f);
		curva.addPonto(720f, 0f);
		env = new Envoltoria();
		env.setCURVA(curva);
		
		ran = new RAN();
		osci = getOscilador();
	}
	
	public void setGanho(float G){
		env.setGanho(G);
	}
	
	public void setF_Ran(float f_ran){
		ran.setF_ran(f_ran);
	}
	
	
	
	


}
