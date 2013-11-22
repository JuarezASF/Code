package unb.banco.conta;

import unb.banco.cliente.Cliente;

public class ContaBonificada extends Conta {
	
	private double taxaBonus;
	private double bonus;
	
	public ContaBonificada(String newNumber, Cliente dono)
	{
		super(newNumber, dono);
		this.taxaBonus = 0.005;
		this.bonus = 0;
	}

	public ContaBonificada(ContaBonificada toCopy)
	{
		super(toCopy);
		this.taxaBonus = toCopy.getTaxaBonus();
		this.bonus = toCopy.getBonus();
	}
	
	public double getTaxaBonus() {
		return taxaBonus;
	}

	public void setTaxaBonus(double taxaBonus) {
		this.taxaBonus = taxaBonus;
	}

	public void setBonus(double bonus) {
		this.bonus = bonus;
	}

	public ContaBonificada(String newNumber, Cliente dono, double saldo)
	{
		super(newNumber, dono, saldo);
		this.taxaBonus = 0.005;
		this.bonus = 0;
	}

	public ContaBonificada(String newNumber, Cliente dono, double saldo, double bonus)
	{
		super(newNumber, dono, saldo);
		this.taxaBonus = 0.005;
		this.bonus = bonus;
	}

	
	public void creditar(double value)
		throws InvalidValueException
	{
		bonus += value*taxaBonus;
		super.creditar(value);
	}
	
	public void renderBonus()
	{
		try{
		this.creditar(bonus);
		bonus = 0.0;
		}
		catch(InvalidValueException e){}
	}
	
	public double getBonus()
		{
			return this.bonus;
		}
	
	
}
