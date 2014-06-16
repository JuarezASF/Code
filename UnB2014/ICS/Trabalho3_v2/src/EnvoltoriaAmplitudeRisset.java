import sintese.Envoltoria;
import sintese.Curva;

/**
 * Implementa uma curva de amplitude gaussiana para gerar o efeito Risset contínuo
 * com a classe Envoltória da API sintese.
 * Ver referência teórica para a fórmula utilizada em: http://hebb.mit.edu/courses/9.29/2003/athena/auditory/risset.html
 * @author Juarez Aires Sampaio Filho
 *
 */
public class EnvoltoriaAmplitudeRisset extends Envoltoria{

	private float fContador, fFi, fT0, fFc, fVar;
	private boolean bCrescente;
	
	/**
	 * Define a curva:
	 * 		Ai(t) = exp(-(log(Fi*2^(-t/t0) - log(Fc))^2/(2*var^2)))
	 * Para implementar o efeito os parâmetros devem ser adequados
	 * @param Fi : dado por F0*2^i (uma potência de 2 da frequência mais baixa)
	 * @param T0 : tempo de meia vida de Fi(t) 
	 * @param Fc : frequência central da gaussiana, você deve centrar a gaussiana simetricamente
	 * em relação a faixa de frequência utilizada
	 * @param var : variância da Gaussiana. Funciona melhor com pequenos valores(=~ 0.5)
	 */
	public EnvoltoriaAmplitudeRisset(float Fi, float T0, float Fc, float var) {
		super();
		set(Fi, T0, Fc, var, false);
	}
 
	/**
	 * Configura EnvoltoriaAmplitudeRisset padrão com
	 * Fi=880, T0=1, Fc=440 e var=0.25
	 */
	public EnvoltoriaAmplitudeRisset() {
		super();
		set(880f, 1f, 440f, 0.25f, false);
	}
	
	private void set(float Fi, float T0, float Fc, float var, boolean crescente){
		Curva curva = new Curva(720);
		for(int i = 0; i<= 720; i++){
			double t = T0*i/720.0;
			double a;
			if(crescente == false)
				a = 10000*Math.exp(-1.0*Math.pow(Math.log10(Fi*Math.pow(2, -1*t/T0))  - Math.log10(Fc), 2)/(2*var*var)); 
			else
				a = 10000*Math.exp(-1.0*Math.pow(Math.log10(Fi*Math.pow(2, +1*t/T0))  - Math.log10(Fc), 2)/(2*var*var));
			
			curva.addPonto(i, a);
		}
		
		setCURVA(curva);
		setSR(44100);
		
		fContador = 0;
		fFi = Fi;
		fT0 = T0;
		fFc = Fc;
		fVar = var;
		
		if(crescente == false)
			bCrescente = false;
		else
			bCrescente = true;

	}
	
	/**
	 * Reescrevemos o método para controlar a saída e permitir uma envoltória cíclica.
	 */
	public void clock(){
		super.clock();
		
		fContador += 721.0/(fT0*44100.0);		
	}

	/**
	 * Reescrevemos o método para permitir uma envoltória de periodo definido por T0.
	 */
	public float getSaida(){
		float saida = getCURVA().getValorNoIndice(fContador);
		if(fContador >= 720.0)
			fContador = 0;
		
		return saida;
	}
	
	/**
	 * Define T0 e recalcula a envoltória.
	 * @param T0
	 */
	public void setT0(float T0){
		set(fFi, T0, fFc, fVar, bCrescente);
	}
	
	/**
	 * Redefine envoltória com novo parâmetro
	 * @param Fi
	 */
	public void setFi(float Fi){
		set(Fi, fT0, fFc, fVar, bCrescente);
	}

	/**
	 * Redefine envoltória com novo parâmetro
	 * @param Fc
	 */
	public void setFc(float Fc){
		set(fFi, fT0, Fc, fVar, bCrescente);
	}
	
	/**
	 * Redefine envoltória com novo parâmetro
	 * @param Var
	 */
	public void setVar(float Var){
		set(fFi, fT0, fFc, Var, bCrescente);
	}
	
	/**
	 * Seta novo modo de crescimento.
	 * @param crescente
	 */
	public void setCrescente(boolean crescente){
		set(fFi, fT0, fFc, fVar, crescente);
	}
	
	
}
