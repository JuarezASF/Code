import sintese.Oscilador;

public class OsciladorShepard extends Oscilador{
	EnvoltoriaAmplitudeShepard amp_env;
	EnvoltoriaFrequenciaShepard freq_env;
	
	public OsciladorShepard(float Fi, float T0, float Fc, float var) {
		super();
		
		amp_env = new EnvoltoriaAmplitudeShepard(Fi, T0, Fc, var);
		freq_env = new EnvoltoriaFrequenciaShepard(Fi, T0);
		
		setDispositivoAmplitude(amp_env);
		setDispositivoFrequencia(freq_env);
	}
	
	
}
