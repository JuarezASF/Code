import sintese.*;
import SomJASF.RAN;
import SomJASF.Instrumentos.Instrumento1;
import SomJASF.Instrumentos.Instrumento2;
import SomJASF.Instrumentos.Instrumento3;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Teste RAN -- start");
		
		Instrumento1 ins = new Instrumento1();
		ins.setGanho(50);
		
		Som som = new Som(ins);
		som.visualiza();
		
		System.out.println("Teste RAN -- fim");
	}

}
