package SomJASF;

import sintese.*;

public class RAN extends Envoltoria{
	
	private float a, f_ran;
	private int tamanho_curva;
	

	//----------------------------------
	//--------Getters and setters-------
	//----------------------------------
	public int getTamanho_curva() {
		return tamanho_curva;
	}

	public void setTamanho_curva(int tamanho_curva) {
		this.tamanho_curva = tamanho_curva;
	}
	
	public float getA() {
		return a;
	}

	public void setA(float a) {
		this.a = a;
	}

	public float getF_ran() {
		return f_ran;
	}

	public void setF_ran(float f_ran) {
		this.f_ran = f_ran;
	}
	//----------------------------------
	//--------Construtores--------------
	//----------------------------------
	/**
	 * Cria Envoltória aleatório entre +A e -A com frequência de pontos de quebra
	 * determinada por f_ran. O tamanho da curva é setado para 720
	 * @param new_a
	 * @param new_f_ran
	 */
	public RAN(float new_a, float new_f_ran){
		setParameters(new_a, new_f_ran, 720);
	}
	
	/**
	 * Cria Envoltória aleatório entre +A e -A com frequência de pontos de quebra
	 * determinada por f_ran e tamanho da curva especificado
	 * @param new_a
	 * @param new_f_ran
	 * @param tamanho_curva
	 */	
	
	public RAN(float new_a, float new_f_ran, int tamanho_curva){
		setParameters(new_a, new_f_ran, tamanho_curva);
	}
	
	/**
	 * seta os 3 parâmetros da classe e regera a Envoltória
	 * @param new_a
	 * @param new_f_ran
	 * @param tamanho_curva
	 */
	public void setParameters(float new_a, float new_f_ran, int tamanho_curva){
		setA(new_a);
		setF_ran(new_f_ran);
		setTamanho_curva(tamanho_curva);
		generateEnvoltoria();
	}
	
	//----------------------------------
	//--------Métodos-------------------
	//----------------------------------
	/**
	 * Gera um número pseudoaleatório entre -A e +A
	 * @param amplitude
	 * @return
	 */
	private float getRandomNumber(float amplitude){
		float random = 2f*amplitude*((float)Math.random()) - amplitude;
		
		return random;
	}
	
	/**
	 * Gera uma nova envoltória com os parâmetros já especificados
	 */
	public void generateEnvoltoria(){
		Curva curv = new Curva(getTamanho_curva());
		float amplitude = getA();
		for(float x = 0; x <= tamanho_curva; x+= tamanho_curva/f_ran){
			curv.addPonto(x, getRandomNumber(amplitude));
		}
		
		this.setCURVA(curv);
	}
	

}
