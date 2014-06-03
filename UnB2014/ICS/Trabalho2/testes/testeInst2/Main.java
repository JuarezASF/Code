import java.awt.Dimension;

import sintese.*;


public class Main {

	public static void main(String[] args) {
		
		System.out.println("Teste Instrumento1.java -- start");

		Instrumento2 inst2 = new Instrumento2();	
		inst2.setGanho(10);
		inst2.setDuracao(5f);	
		inst2.setFrequencia(660f);
		
		

		Som som = new Som(inst2);
		som.visualiza();
		
		System.out.println("Teste Instrumento1.java -- fim");
	}

}
