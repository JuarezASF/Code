import sintese.*;
import SomJASF.RAN;
import SomJASF.Instrumentos.Instrumento1;
import SomJASF.Instrumentos.Instrumento2;
import SomJASF.Instrumentos.Instrumento3;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Teste RAN -- start");
		
		Instrumento2 ins = new Instrumento2();
//		ins.setGanho(50f);
		ins.setFRuido(60);
		ins.setGanhoRuido(100);
			
		Som som = new Som(ins);
		som.visualiza();
		
		System.out.println("Teste RAN -- fim");
	}

}
