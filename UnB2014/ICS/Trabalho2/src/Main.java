import sintese.*;
import SomJASF.RAN;
import SomJASF.Instrumentos.Instrumento1;
import SomJASF.Instrumentos.Instrumento2;
import SomJASF.Instrumentos.Instrumento3;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Teste RAN -- start");
		
		RAN rand = new RAN();
		
		rand.visualiza();
		
		try {
		    Thread.sleep(3000);
		} catch(InterruptedException ex) {
		    Thread.currentThread().interrupt();
		}
		
		rand.setA(10f);
		rand.setF_ran(2);
		rand.generateEnvoltoria();
		rand.visualiza();
		
		System.out.println("Teste RAN -- fim");
	}

}
