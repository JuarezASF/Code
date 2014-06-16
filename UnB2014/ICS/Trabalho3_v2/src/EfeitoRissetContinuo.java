import sintese.Curva;
import sintese.Envoltoria;
import sintese.Oscilador;
import sintese.Somador;
import sintese.Som;
import sintese.Multiplicador;

public class EfeitoRissetContinuo {
	
	private OsciladorRissetContinuo[] osci;
	private Somador[] sum;
	private Envoltoria ganho;
	private Multiplicador efeito_final;
	private float fVar, fFc, fT0, fF0, fDuracao;
	private boolean bCrescente;
	
	private void set(float T0, float Fc, float var, float duracao, boolean crescente){
		fVar = var;
		fFc = Fc;
		fT0 = T0;
		fF0 = fFc/8.0f;
		fDuracao = duracao;
		bCrescente = crescente;
		
		for(int i = 0; i < 7; i++){
			float Fi = fF0*((float )Math.pow(2.0, i));
			osci[i] = new OsciladorRissetContinuo(Fi, fT0, fFc, fVar);
		}
		
		for(int i = 0; i < 7; i++){
			osci[i].setCrescente(bCrescente);
		}
		
		
		sum[0] = new Somador(osci[0], osci[1]);
		for(int i = 1; i < 6; i++){
			sum[i] = new Somador(sum[i-1], osci[i+1]);
		}
		
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0.75);
		curva.addPonto(720f, 0.75);
		
		ganho.setCURVA(curva);
		ganho.setDuracao(fDuracao);
		
		efeito_final = new Multiplicador(ganho, sum[5]);
	}
	
	public EfeitoRissetContinuo(){
		osci = new OsciladorRissetContinuo[7];
		sum = new Somador[6];
		ganho = new Envoltoria();
		
		set(15, 440, 0.25f,30f, false);
		
	}
	
	public void setT0(float T0){
		fT0 = T0;
		for(int i = 0; i < 7; i++){
			osci[i].setT0(T0);
		}
	}
	
	public void setFc(float Fc){
		fFc = Fc;
		for(int i = 0; i < 7; i++){
			osci[i].setFc(Fc);
		}
	}
	
	public void setVar(float Var){
		fVar = Var;
		for(int i = 0; i < 7; i++){
			osci[i].setVar(Var);
		}
	}
	
	public void setCrescente(boolean crescente){
		bCrescente = crescente;
		for(int i = 0; i < 7; i++){
			osci[i].setCrescente(crescente);
			}	
		}
	
	public void setF0(float F0){
		fF0 = F0;
		for(int i = 0; i < 7; i++){
			float Fi = fF0*((float )Math.pow(2.0, i));
			osci[i].setFi(Fi);
		}
	}
	
	public void setDuracao(float duracao){
		fDuracao = duracao;
	}
	
	public Som getSom(float duracao){
		fDuracao = duracao;
		ganho.setDuracao(fDuracao);
		Som som = new Som(efeito_final, duracao);
		
		return som;
	}

	public Som getSom(){
		ganho.setDuracao(fDuracao);
		Som som = new Som(efeito_final, fDuracao);
		
		return som;
	}

	
}
