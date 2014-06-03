import java.awt.Dimension;

import sintese.*;


public class Main {

	public static void main(String[] args) {
		
		System.out.println("Teste Instrumento1.java -- start");

		Instrumento1 inst1 = new Instrumento1();		
		
		inst1.setDuracao(5f);
		inst1.setF_ruido(600);
		inst1.setFrequencia(660);
		inst1.setGanho(50);
		
		

		Som som = new Som(inst1);
		som.visualiza();
		
		System.out.println("Teste Instrumento1.java -- fim");
	}

}
