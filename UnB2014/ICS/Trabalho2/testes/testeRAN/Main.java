import java.awt.Dimension;

import sintese.*;


public class Main {

	public static void main(String[] args) {
		
		System.out.println("Teste RAN -- start");
		
		Envoltoria env = new Envoltoria();
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0f);
		curva.addPonto(80f, 1000f);
		curva.addPonto(400f, 1000f);
		curva.addPonto(720f, 0f);
		env.setCURVA(curva);

		RAN ran = new RAN();
		ran.setGanho(env);
		ran.setGanho(10);
		ran.setF_ruido(10); 

			
		Oscilador osci = new Oscilador(ran);
		osci.setFrequencia(440);
		osci.setDuracao(5f);

		Som som = new Som(osci);
		som.visualiza();
		
		System.out.println("Teste RAN -- fim");
	}

}
