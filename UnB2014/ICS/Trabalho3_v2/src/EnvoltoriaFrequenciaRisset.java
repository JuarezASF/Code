import sintese.Curva;
import sintese.Envoltoria;
/**
 * Implementa uma envoltória para a entrada de Frequência do OsciladorRisset.
 * 
 * 
 * Utiliza-se para isso a API sintese 
 * 
 * Ver referência teórica para a fórmula utilizada em: http://hebb.mit.edu/courses/9.29/2003/athena/auditory/risset.html
 * @author juarez408
 *
 */
public class EnvoltoriaFrequenciaRisset extends Envoltoria{
	private float fContador, fFi, fT0;
	boolean bCrescente;
	
	/**
	 * Define a envoltória decrescente de frequência dada por:
	 * 		theta(t) = (Fi*T0/ln2)*(1 - 2^(-t/t0))
	 * 
	 * theta é tal que :
	 * 		d/dt theta(t) = Fi*2^(-t/t0)
	 * @param Fi
	 * @param T0
	 */
	public EnvoltoriaFrequenciaRisset(float Fi, float T0) {
		super();
		set(Fi, T0, false);
	}
	
	/**
	 * Cria EnvoltoriaFrequenciaRisset decrescente padrão com Fi=880 e T0 = 1
	 */
	public EnvoltoriaFrequenciaRisset() {
		super();
		set(880, 1, false);
	}
	
	/**
	 * Configura completamente envoltória
	 * @param Fi
	 * @param T0
	 */
	private void set(float Fi, float T0, boolean crescente){
		Curva curva = new Curva(720);
		for(int i = 0; i<= 720; i++){
			double t = T0*i/720.0;
			//double f = Fi*T0/Math.log10(2)*(1.0 - Math.pow(2, -1.0*t/T0)); 
			double f;
			if(crescente == false)
				f = Fi*Math.pow(2, -1.0*t/T0);
			else
				f = Fi*Math.pow(2, +1.0*t/T0);
			
			curva.addPonto(i, f);
		}
		
		setCURVA(curva);
		setSR(44100);
		
		fFi = Fi;
		fT0 = T0;
		fContador = 0;
		
		if(crescente == false)
			bCrescente = false;
		else
			bCrescente = true;
	}

	/**
	 * Reescrevemos o método para controlar a saída e permitir uma envoltória 
	 * cíclica de período T0.
	 */
	public void clock(){
		super.clock();
		
		fContador += 721.0/(fT0*44100.0);		
	}

	/**
	 * Reescrevemos o método para controlar a saída e permitir uma envoltória 
	 * cíclica de período T0.
	 */
	public float getSaida(){
		if(fContador > 720.0)
			fContador -= 720;
		
		float saida = getCURVA().getValorNoIndice(fContador);
		
		return saida;
	}

	/**
	 * Redefine a envoltória para o novo T0
	 * @param T0
	 */
	public void setT0(float T0){
		set(fFi, T0, bCrescente);
	}
	
	/**
	 * Redefine a envoltória para o novo Fi
	 * @param Fi
	 */
	public void setFi(float Fi){
		set(Fi, fT0, bCrescente);
	}
	
	/**
	 * Redefine a envoltória para o novo modo de crescimento
	 * @param crescente
	 */
	public void setCrescente(boolean crescente){
		set(fFi, fT0, crescente);
	}
}
