import java.awt.Dimension;

import sintese.*;
import GUI.GUI;
import SomJASF.RAN;
import SomJASF.Instrumentos.Instrumento1;
import SomJASF.Instrumentos.Instrumento2;
import SomJASF.Instrumentos.Instrumento3;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*stem.out.println("Teste RAN -- start");
		
		Instrumento3 ins = new Instrumento3();
//		ins.setGanho(50f);
		ins.setFRuido(60);
		ins.setGanhoRuido(100);
			
		Som som = new Som(ins);
		som.visualiza();
		
		System.out.println("Teste RAN -- fim");
		*/
		
		GUI myGui = new GUI();
		myGui.setSize(new Dimension(240, 320));
		myGui.show();
	}

}
