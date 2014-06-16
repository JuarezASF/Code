import sintese.Curva;
import sintese.Envoltoria;

public class EnvoltoriaFrequenciaShepard extends Envoltoria{
	float contador, Fi, T0;
	
	
	public EnvoltoriaFrequenciaShepard(float Fi, float T0) {
		super();
		contador = 0;
		
		Curva curva = new Curva(720);
		for(int i = 0; i<= 720; i++){
			double t = T0*i/720.0;
			double f = Fi*T0/Math.log10(2)*(1.0 - Math.pow(2, -1.0*t/T0)); 
			
			curva.addPonto(t, f);
		}
		
		setCURVA(curva);
		
		setSR(44100);
		
		this.Fi = Fi;
		this.T0 = T0;
		}

	public void clock(){
		super.clock();
		
		contador += 721.0/(T0*44100.0);		
	}
	/*
	public float getSaida(){
		float saida = getCURVA().getValorNoIndice(contador);
		if(contador >= 720.0)
			contador = 0;
		
		return saida;
	}*/
}
