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
		public Conta(String new_number, Cliente new_dono)
			{
				setNumber(new_number);
				setDono(new_dono);
				setSaldo(0);
			}

		public Conta(String new_number, Cliente new_dono, double saldo_0)
			{
				setNumber(new_number);
				setDono(new_dono);
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

		public void print(boolean option)
		/**
		* true para imprimir com saldo e false para não imprimir saldo
		*/
			{
				System.out.println("Cliente :\t" + dono.getName());
				System.out.println("número da conta :\t" + number);	
				if(option == true)
					System.out.println("saldo:\t" + saldo);
				return;
			}

		public void print()
			{
				print(false);
				return;	
			}

		public void print_ws()
		/**
		*ws = with saldo
		*imprime dados da conta incluindo o saldo
		*/
			{
				print(true);
				return;	
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
				if(value > 0.0)
					this.setSaldo(saldo + value);
				else
				System.out.println("Valor incoerente! Por favor use 'debitar'" +
														 "para subtrair um valor! ");

				return;
			}

		public void debitar(double value)
			{
				if(value < 0)
					System.out.println("Valor incoerente! Por favor use 'creditar'" +
														" para adicionar um valor! ");

				else if(saldo - value >= 0)
					this.setSaldo(saldo - value);
					else
					System.out.println("Valor não pode ser debitado!");
				
				return;
			}

		public void transferir(Conta destino, double value)
			{
				if(value >= 0)
					{
						if(saldo > value)
							{	
								this.saldo -= value;
								destino.creditar(value);
								
								System.out.println("\n\n\n\nTransferência efetuada com sucesso\n\n");
								
								System.out.println("Origem:\n");
								this.print();

								System.out.println("\nDestino:\n");
								destino.print();
							}

						else
							System.out.println("Valor não pode ser transferido! Saldo insuficiente.");		
					
					}
				else 
					System.out.println("Valor negativo não pode der transferido!");
			
				return;
			}
	
	}