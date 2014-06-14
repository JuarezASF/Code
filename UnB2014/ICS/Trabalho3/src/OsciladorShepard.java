import sintese.Dispositivo;
import sintese.Multiplicador;
import sintese.Somador;
import sintese.Oscilador;
import sintese.Envoltoria;

public class OsciladorShepard extends Oscilador{
	
	private EnvoltoriaGaussiana gauss_env;
	EnvoltoriaLinearShepard freq_env;
	
	private void set(float freq_media, float gaus_media, float gaus_var,
			float inicio){
		
		gauss_env = new EnvoltoriaGaussiana(gaus_media, gaus_var, 10000);
		gauss_env.setContador(inicio);
		
		freq_env = new EnvoltoriaLinearShepard(freq_media);
		freq_env.setContador(inicio);
		
		setDispositivoAmplitude(gauss_env);
		setDispositivoFrequencia(freq_env);
		setSR(44100);
	}
	
	/**
	 * Gera Oscilador para implementar feito Shepard. O ciclo criado tem duração
	 * padrõa de 1 segundo.
	 * @param freq_media
	 * @param gaus_media
	 * @param gaus_var
	 * @param inicio
	 */
	public OsciladorShepard(float freq_media, float gaus_media, float gaus_var,
			float inicio){
		super();
		set(freq_media, gaus_media, gaus_var, inicio);
		
	}

	/**
	 * Gera Oscilador para implementar feito Shepard. O ciclo criado tem duração
	 * padrõa de 1 segundo. Defasagem padrão de 0%
	 * @param freq_media
	 * @param gaus_media
	 * @param gaus_var
	 */
	public OsciladorShepard(float freq_media, float gaus_media, float gaus_var){
		super();
		set(freq_media, gaus_media, gaus_var, 0f);
		
	}

	
	public void setDuracaoCiclo(float d){
		gauss_env.setDuracaoCiclo(d);
		freq_env.setDuracaoCiclo(d);
	}

	/**
	 * Permite setar a posição do ciclo. Entre 360 para colocar no meio do ciclo
	 * (frequencia central e amplitude máxima)
	 * @param fc
	 */
	public void setFaseCilco(float fc){
		gauss_env.setContador(fc);
		freq_env.setContador(fc);
	}

}
