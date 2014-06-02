package SomJASF.Instrumentos;
import SomJASF.RAN;
import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;

public class Instrumento1 extends Oscilador{
	
	RAN ran;
	Envoltoria env;
	
	
	public Instrumento1(){
		super();
		initialize();

		env.setGanho(10);
		env.setDuracao(1);
		ran.setGanhoDispositivo(env);
		ran.setF_ran(60);
		this.setDispositivoAmplitude(ran);
		this.setFrequencia(440);
	}
	
	/**
	 * Inicializa env com a curva padrão,
	 * ran com o cosntrutor padrão
	 */
	private void initialize(){
		//define envoltoria padrão
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0f);
		curva.addPonto(10f, 100f);
		curva.addPonto(680f, 100f);
		curva.addPonto(720f, 0f);
		env = new Envoltoria();
		env.setCURVA(curva);
		
		ran = new RAN();
	}
	
	public void setGanho(float G){
		env.setGanho(G);
	}
	
	public void setDuracao(float d){
		env.setDuracao(d);
	}
	
	public void setF_Ran(float f_ran){
		ran.setF_ran(f_ran);
	}
	
	
	
	


}
