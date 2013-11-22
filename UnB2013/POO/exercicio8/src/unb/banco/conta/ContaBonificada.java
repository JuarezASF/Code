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
