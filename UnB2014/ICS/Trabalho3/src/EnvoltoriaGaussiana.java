

import sintese.Curva;
import sintese.Envoltoria;

import javax.vecmath.Vector2d;


public class EnvoltoriaGaussiana extends Envoltoria{
	
	private float contador;
	private float duracao_ciclo;
	
	/**
	 * Configura a Envoltoria segundo os parâmetros informados.
	 * @param media
	 * @param variancia
	 * @param amplitude
	 * @param inicio
	 */
	private void set(double media, double variancia, double amplitude, float inicio){
		Curva gaussiana = new Curva(720);
		
		for(int i = 0; i <=720; i++){
			double x = 0.5*media + 1.0*media*i/720.0;
			gaussiana.addPonto(i, amplitude*GaussianaUnitaria(media, variancia, x));
		}
		
		setCURVA(gaussiana);
		
		contador = inicio;
		duracao_ciclo = 1f;
	}
	
	/**
	 * Gera uma envoltória com curva de 720 pontos e forma gaussiana.
	 * A gaussiana é gerada com a média e a variância dada percorrendo o 
	 * intervalo [0.5*media, 1.5*media].
	 * A curva gerada vai de 0 a 1000.
	 * O máximo da gaussiana ocorre em i = 360(posição da tabela)
	 * @param media
	 * @param variancia
	 */
	public EnvoltoriaGaussiana(double media, double variancia){
		super();
		set(media, variancia, 1000.0, 0f);
	}
	
	/**
	 * Gera uma envoltória com curva de 720 pontos e forma gaussiana.
	 * A gaussiana é gerada com a média e a variância dada percorrendo o 
	 * intervalo [0.5*media, 1.5*media].
	 * A curva gerada vai de 0 a amplitude.
	 * * O máximo da gaussiana ocorre em i = 360(posição da tabela)
	 * @param media
	 * @param variancia
	 * @param amplitude
	 */
	public EnvoltoriaGaussiana(double media, double variancia, double amplitude) {
		super();
		set(media, variancia, amplitude, 0f);
	}
	
	/**
	 * Permite setar a defasagem na gaussiana. Para adiantar meio ciclo, entre com 360.
	 * @param media
	 * @param variancia
	 * @param amplitude
	 * @param inicio
	 */
	public EnvoltoriaGaussiana(double media, double variancia, double amplitude, float inicio){
		super();
		set(media, variancia, amplitude, inicio);
	}
	
	/**
	 * Retorna o valor da gaussiana de média e variância informada no ponto x.
	 * @param media
	 * @param variancia
	 * @param x
	 * @return
	 */
	private double GaussianaUnitaria(double media, double variancia, double x){
		double f = 1*Math.exp(-1.0*Math.pow((x - media), 2)/(2*Math.pow(variancia, 2)));
		//f /= variancia*Math.sqrt(2*Math.PI);
		
		return f;
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
	

}
