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
	
	/**
	 * Confiura o efeito com todos os parâmetros necessários
	 * @param T0
	 * @param Fc
	 * @param var
	 * @param duracao
	 * @param crescente
	 */
	private void set(float T0, float Fc, float var, float duracao, boolean crescente){
		fVar = var;
		fFc = Fc;
		fT0 = T0;
		fF0 = fFc/16.0f;
		fDuracao = duracao;
		bCrescente = crescente;
		
		for(int i = 0; i < 9; i++){
			float Fi = fF0*((float )Math.pow(2.0, i));
			osci[i] = new OsciladorRissetContinuo(Fi, fT0, fFc, fVar);
		}
		
		for(int i = 0; i < 9; i++){
			osci[i].setCrescente(bCrescente);
		}
		
		
		sum[0] = new Somador(osci[0], osci[1]);
		for(int i = 1; i < 8; i++){
			sum[i] = new Somador(sum[i-1], osci[i+1]);
		}
		
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0.0);
		curva.addPonto(50f, 0.75);
		curva.addPonto(680f, 0.75);
		curva.addPonto(720f, 0);
		
		ganho.setCURVA(curva);
		ganho.setDuracao(fDuracao);
		
		efeito_final = new Multiplicador(ganho, sum[7]);
	}
	
	/**
	 * Constroi efeito Risset Padrão
	 * (T0, Fc, var, duracao, crescente) = (15, 440, 0.25f,30f, false)
	 */
	public EfeitoRissetContinuo(){
		osci = new OsciladorRissetContinuo[9];
		sum = new Somador[8];
		ganho = new Envoltoria();
		
		set(15, 440, 0.1f,30f, false);
	}

	/**
	 * Constroi efeito Risset com parâmetros especificados
	 * @param T0
	 * @param Fc
	 * @param var
	 * @param duracao
	 * @param crescente
	 */
	public EfeitoRissetContinuo(float T0, float Fc, float var, float duracao, boolean crescente){
		osci = new OsciladorRissetContinuo[9];
		sum = new Somador[8];
		ganho = new Envoltoria();
		
		set(T0, Fc, var, duracao, crescente);
	}
	
	public void setGanho(float g){
		Curva curva = new Curva(720);
		curva.addPonto(0f, 0.0);
		curva.addPonto(50f, g);
		curva.addPonto(680f, g);
		curva.addPonto(720f, g);
		
		ganho.setCURVA(curva);
		ganho.setDuracao(fDuracao);
		
		efeito_final = new Multiplicador(ganho, sum[7]);
	}
	
	public void setT0(float T0){
		set(T0, fFc, fVar, fDuracao, bCrescente);
	}
	
	public void setFc(float Fc){
		set(fT0, Fc, fVar, fDuracao, bCrescente);
	}
	
	public void setVar(float Var){
		set(fT0, fFc, Var, fDuracao, bCrescente);
	}
	
	public void setCrescente(boolean crescente){
		set(fT0, fFc, fVar, fDuracao, crescente);
		}
	
	private void setF0(){
		fF0 = fFc/16.0f;
		for(int i = 0; i < 9; i++){
			float Fi = fF0*((float )Math.pow(2.0, i));
			osci[i].setFi(Fi);
		}
	}
	
	public void setDuracao(float duracao){
		fDuracao = duracao;
		ganho.setDuracao(fDuracao);
	}
	
	/**
	 * Configura nova duração e retorna som
	 * @param duracao
	 * @return
	 */
	public Som getSom(float duracao){
		setDuracao(duracao);
		Som som = new Som(efeito_final, duracao);
		
		return som;
	}

	/**
	 * Retorna som com os parâmetros anteriormente definidos
	 * @return
	 */
	public Som getSom(){
		Som som = new Som(efeito_final, fDuracao);
		
		return som;
	}

	public OsciladorRissetContinuo[] getOsci() {
		return osci;
	}

	public Somador[] getSum() {
		return sum;
	}

	public Multiplicador getEfeito_final() {
		return efeito_final;
	}

	public float getfVar() {
		return fVar;
	}

	public float getfFc() {
		return fFc;
	}

	public float getfT0() {
		return fT0;
	}

	public float getfF0() {
		return fF0;
	}

	public float getfDuracao() {
		return fDuracao;
	}

	public boolean isbCrescente() {
		return bCrescente;
	}

	
}
