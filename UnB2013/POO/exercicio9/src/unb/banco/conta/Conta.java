package unb.banco.conta;

import unb.banco.cliente.Cliente;
import unb.banco.conta.SaldoInsuficienteException;
/**
 * -Exercício 3 de POO
 *   classe conta
 * */

public class Conta
	{
		//--------------------------------------------------
		//----------------ATRIBUTOS-------------------------
		//--------------------------------------------------
		private String number;
		private double saldo;
		private Cliente dono;
		//--------------------------------------------------
		//----------------CONSTRUTORES----------------------
		//--------------------------------------------------
		public Conta(String new_number, Cliente dono)
			{
				setNumber(new_number);
				setDono(dono);
				setSaldo(0);
			}

		public Conta(String new_number, Cliente dono, double saldo_0)
			{
				setNumber(new_number);
				setDono(dono);
				setSaldo(saldo_0);
			}

		public Conta(Conta toCopy)
		{
			setNumber(toCopy.getNumber());
			setDono(toCopy.getDono());
			setSaldo(toCopy.getSaldo());
		}
		
		public Conta()
			{
			}
		//--------------------------------------------------
		//----------------ACESSO----------------------------
		//--------------------------------------------------
		public String getNumber()
			{
				return number;
			}

		public double getSaldo()
			{
				return saldo;
			}

		public Cliente getDono()
			{
				return dono;
			}
		//--------------------------------------------------
		//----------------SETANDO---------------------------
		//--------------------------------------------------
		public void setNumber(String new_number)
			{
				number = new_number;
				return;
			}

		public void setSaldo(double new_saldo)
			{
				saldo = new_saldo;
				return;
			}

		public void setDono(Cliente new_dono)
			{
				dono = new_dono;
				return;
			}
		//--------------------------------------------------
		//----------------OPERAÇOES-------------------------
		//--------------------------------------------------
		public void creditar(double value) throws InvalidValueException
			{
			if(value >= 0)
				this.setSaldo(saldo + value);
			else
				throw new InvalidValueException
				("Valor Inválido! \n Valor entrado deve ser positivo!");
			return;
			}

		public void debitar(double value) 
				throws SaldoInsuficienteException
			{
			if(value <= this.getSaldo())
				this.setSaldo(saldo - value);
			else
				throw new SaldoInsuficienteException();
			
			}

		public void transferir(Conta destino, double value) 
				throws SaldoInsuficienteException,
				InvalidValueException
			{
			this.debitar(value);;
			destino.creditar(value);
			return;
			}
	
	}