package classasBasicas;

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
		public void creditar(double value)
			{
			this.setSaldo(saldo + value);
			return;
			}

		public void debitar(double value)
			{
			this.setSaldo(saldo - value);
			return;
			}

		public void transferir(Conta destino, double value)
			{
			this.saldo -= value;
			destino.creditar(value);
			return;
			}
	
	}