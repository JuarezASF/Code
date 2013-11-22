package unb.banco.conta;

public class SaldoInsuficienteException extends Exception{
	

	private double saldo;
	
	public SaldoInsuficienteException(){
		super("Saldo Insuficiente");
		setSaldo(-1);
	}
	
	public SaldoInsuficienteException(String msgErro, double saldo){
		super(msgErro);
		setSaldo(saldo);
	}


	public double getSaldo() {
		return saldo;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}

}
