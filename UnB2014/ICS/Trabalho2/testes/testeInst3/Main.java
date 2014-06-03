import java.awt.Dimension;

import sintese.*;


public class Main {

	public static void main(String[] args) {
		
		System.out.println("Teste Instrumento3.java -- start");

		Instrumento3 inst3 = new Instrumento3();	
		inst3.setDuracao(5f);
		inst3.setGanho(10);
		inst3.setFrequencia(1660f);
		inst3.setOsciFrequenciaF(1f);
		inst3.setOsciFrequenciaA(10);//parece não funcionar
		inst3.setGanhoRuido(100);
		inst3.setFRuido(10);
		
		

		Som som = new Som(inst3);
		som.salvawave();
		som.tocawave();
		
		System.out.println("Teste Instrumento3.java -- fim");
	}

}
