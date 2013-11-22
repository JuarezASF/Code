package unb.banco.conta;

import unb.banco.cliente.Cliente;

public class Poupanca extends Conta{
	
	private double taxa;
	
	public Poupanca(String newNumber, Cliente dono){
		super(newNumber, dono);
		taxa = 0.05;
	}

	public Poupanca(String newNumber, Cliente dono, double saldo){
		super(newNumber, dono, saldo);
		taxa = 0.05;
	}
	
	public double getTaxa() {
		return taxa;
	}

	public Poupanca(Poupanca toCopy){
		super(toCopy);
		taxa = toCopy.getTaxa();
	}
	
	public void setTaxa(double newTaxa){
		this.taxa = newTaxa;
	}
	
	public void renderJuros(){
		double saldoAtual = this.getSaldo();
		double juros = saldoAtual*this.taxa;
		this.setSaldo(saldoAtual + juros);
	}
	
}
