import sintese.Oscilador;

/**
 * Implementa Oscilador básico para gerar efeito Risset Contínuo utilizando-se da API sintese
 * 
 * 
 * Ver referência teórica em: http://hebb.mit.edu/courses/9.29/2003/athena/auditory/risset.html
 * @author juarez408
 *
 */
public class OsciladorRissetContinuo extends Oscilador{
	EnvoltoriaAmplitudeRisset amp_env;
	EnvoltoriaFrequenciaRisset freq_env;
	
	private float fFi, fT0, fFc, fVar;
	private boolean bCrescente;
	
	/**
	 * Cria OsciladorRissetContinuo com os parâmetros especificados.
	 * @param Fi
	 * @param T0
	 * @param Fc
	 * @param var
	 */
	public OsciladorRissetContinuo(float Fi, float T0, float Fc, float var) {
		super();
		set(Fi, T0, Fc, var);
		bCrescente = false;
	}
	
	/**
	 * Cria OsciladorRissetContinuo padrão com
	 * Fi=880, T0=1, Fc=440 e var=0.25
	 */
	public OsciladorRissetContinuo() {
		super();
		set(880, 1, 440, 0.25f);
		bCrescente = false;
	}
	
	private void set(float Fi, float T0, float Fc, float var){
		amp_env = new EnvoltoriaAmplitudeRisset(Fi, T0, Fc, var);
		freq_env = new EnvoltoriaFrequenciaRisset(Fi, T0);
		
		setDispositivoAmplitude(amp_env);
		setDispositivoFrequencia(freq_env);
		
		fFi = Fi;
		fT0 = T0;
		fFc = Fc;
		fVar = var;
	}
	
	/**
	 * Define T0 e recalcula o Oscilador.
	 * @param T0
	 */
	public void setT0(float T0){
		amp_env.setT0(T0);
		freq_env.setT0(T0);
	}
	
	/**
	 * Redefine Oscilador com novo parâmetro
	 * @param Fi
	 */
	public void setFi(float Fi){
		amp_env.setFi(Fi);
		freq_env.setFi(Fi);
	}

	/**
	 * Redefine Oscilador com novo parâmetro
	 * @param Fc
	 */
	public void setFc(float Fc){
		amp_env.setFc(Fc);
	}
	
	/**
	 * Redefine Oscilador com novo parâmetro
	 * @param Var
	 */
	public void setVar(float Var){
		amp_env.setVar(Var);
	}
	
	public void setCrescente(boolean crescente){
		bCrescente = crescente;
		amp_env.setCrescente(crescente);
		freq_env.setCrescente(crescente);
	}
	
}
