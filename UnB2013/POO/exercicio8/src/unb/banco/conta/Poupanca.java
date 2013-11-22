package unb.banco.conta;

import unb.banco.cliente.Cliente;

public class Poupanca extends Conta{
	
	private double taxa;
	
	public Poupanca(String newNumber, Cliente dono){
		super(newNumber, dono);
		taxa = 0.05;
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
