import sintese.Envoltoria;
import sintese.Curva;

import javax.vecmath.Vector2d;

public class EnvoltoriaLinearShepard extends Envoltoria{
	
	private float contador;
	private float duracao_ciclo;
	
	private void set(double freq_central, float inicio){
		double f_inicial = 1f/4f*freq_central;
		double f_final   = 4*freq_central;
		
		Curva curva = new Curva(720);
		for(int i = 0; i <=720; i++){
			double f = f_final*i/720.0 + f_inicial*(1 - i/720.0);
			curva.addPonto(i, f);
		}
		
		setCURVA(curva);
		
		contador = inicio;
		duracao_ciclo = 1.0f;

	}
	
	/**
	 * Gera uma envoltória de 720 pontos que passa em 
	 * (0f, 0.5*freq_central), (360, freq_central) e (720, 2*freq_central)
	 * @param freq_central
	 */
	public EnvoltoriaLinearShepard(double freq_central) {
		super();
		set(freq_central, 0.0f);
	}
	
	public void clock(){
		super.clock();
		
		contador += 721.0/(duracao_ciclo*44100.0);		
	}
	
	public float getSaida(){
		float saida = getCURVA().getValorNoIndice(contador);
		if(contador >= 720.0)
			contador = 0;
		
		return saida;
	}
	
	public void setDuracaoCiclo(float d){
		duracao_ciclo = d;
	}
	
	/**
	 * Permite setar o contador. O contador é a variável que determina a saída.
	 * Para colocar a saída no final da tabela entre 720, para colocá-la no meio(
	 * valor máximo) entre 360.
	 * @param c
	 */
	public void setContador(float c){
		contador = c;
	}
	
	/**
	 * Retorna a dupla (contador, saída).
	 * Isto é, retorna o ponto do gráfico em que estamos.
	 * @return
	 */
	public Vector2d getSaidaData(){
		double x = contador;
		double y = getSaida();
		
		Vector2d v = new Vector2d(x, y);
	
		return v;
	}

}
