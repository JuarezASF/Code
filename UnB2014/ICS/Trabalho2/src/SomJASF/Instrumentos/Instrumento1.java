package SomJASF.Instrumentos;
import SomJASF.RAN;
import sintese.Envoltoria;
import sintese.Oscilador;

public class Instrumento1{
	
	RAN ran;
	Envoltoria env;
	Oscilador osci;
	
	float a, d, f_ran, f;
	
	
	public Instrumento1(){
		initialize();
		env.setDuracao(d);
		env.setGanho(a);
	}
	
	/**
	 * Inicializa os parâmetros objetos dos pacotes SomA e SomJASF
	 */
	private void initialize(){
		env = new Envoltoria();
		ran = new RAN();
		osci = new Oscilador();
	}

}
