import sintese.Envoltoria;
import sintese.Curva;

public class EnvoltoriaAmplitudeShepard extends Envoltoria{

	float fContador, fFi, fT0, fFc, fVar;
	
	/**
	 * Define a curva:
	 * 		Ai(t) = exp(-(log(Fi*2^(-t/t0) - log(Fc))^2/(2*var^2)))
	 * @param Fi
	 * @param T0
	 * @param Fc
	 * @param var
	 */
	public EnvoltoriaAmplitudeShepard(float Fi, float T0, float Fc, float var) {
		super();
		fContador = 0;
		
		Curva curva = new Curva(720);
		for(int i = 0; i<= 720; i++){
			double t = T0*i/720.0;
			double a = 10000*Math.exp(-1.0*Math.pow(Math.log10(Fi*Math.pow(2, -1*t/T0))  - Math.log10(Fc), 2)/(2*var*var)); 
			
			curva.addPonto(i, a);
		}
		
		setCURVA(curva);
		
		setSR(44100);
		
		fFi = Fi;
		fT0 = T0;
		fFc = Fc;
		fVar = var;
	}
 
	public void clock(){
		super.clock();
		
		fContador += 721.0/(fT0*44100.0);		
	}
	
	public float getSaida(){
		float saida = getCURVA().getValorNoIndice(fContador);
		if(fContador >= 720.0)
			fContador = 0;
		
		return saida;
	}
}
