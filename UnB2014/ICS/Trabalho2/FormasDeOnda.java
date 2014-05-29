import sintese.*;

/**
 * Usado para obter as formas de ondas necessárias no Trabalho 2
 * @author Juarez Aires Sampaio Filho 
 *
 */
public class FormasDeOnda{
	
	/**
	 * Retorna forma de onda trapesoidal 
	 * 
	 * @return forma de onda trapesoidal
	 */
	public static Dispositivo getF1(){
		
		//constroi a curva
		Curva curva1 = new Curva(720);
		curva1.addPonto(0f, 0f);
		curva1.addPonto(30f, 1000f);
		curva1.addPonto(690f, 1000f);
		curva1.addPonto(720f, 0f);
		
		//constroi a envoltoria com a curva anterior
		Envoltoria F1 = new Envoltoria();
		F1.setCURVA(curva1);
		
		return F1;
	}
	
	/**
	 * Retorna forma de onda senoidal
	 * @return
	 */
	public static Dispositivo getF2(){
		Oscilador F2 = new Oscilador(1f, 440f, 0f);
		
		return F2;
	}

	public static Dispositivo getF3(){
	Oscilador F3 = new Oscilador(1f, 440f, 0f);
	
	return F3;
	
}
	

}