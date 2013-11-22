/**
 * -Exercício 3 de POO
 *   classe cliente
 * */

public class Cliente
	{
		//--------------------------------------------------
		//----------------ATRIBUTOS-------------------------
		//--------------------------------------------------
		private String name;
		private String cpf;
		/*poderia ser declarado na mesma linha mas dessa forma
		                          melhoramos a visibilidade*/

		//--------------------------------------------------
		//----------------CONSTRUTORES----------------------
		//---contrutores não são necessários mais faciliam--
		//---a inicialização de classes---------------------
		//--------------------------------------------------
		Cliente(String new_name, String new_cpf)
			{
				setName(new_name);
				setCpf(new_cpf);
				/*
				convenção maneira:
					atribuir os argumentos na ordem em que são 
					declarados na assinatura do método.
				*/
			}

		Cliente()//construtor default
			{
			name = null;
			cpf  = null;				
			}
		/*não faz sentido oferecer um construtor padrão!
		  provavelmente o banco não quer um cliente sem nome
		  ou cpf.
		  colocamos aqui somente como exercício*/


		//--------------------------------------------------
		//----------------ACESSO----------------------------
		//--------------------------------------------------
			/*
			É importante tornar os atributos privados e 
			adicionar métodos que permitam o acesso indiretamente.
			dessa forma protegemos os dados e facilitamos a manutenção.
			*/
		public String getName()
			{
				return name;	
			}
		public String getCpf()
			{
				return cpf;
			}
		//--------------------------------------------------
		//----------------SETANDO---------------------------
		//--------------------------------------------------
		public void setName(String new_name)
			{
				name = new_name; 
			}	

		public void setCpf(String new_cpf)
			{
				cpf = new_cpf;
			}

		public void print(boolean option)
		/**
		* true para imprimir com saldo e false para não imprimir saldo
		*/
			{
				System.out.println("Cliente :\t" + this.getName());
				System.out.println("CPF :\t" + getCpf());	
				if(option == true)
					System.out.println("ISSO N DEVE SER IMPRESSO:\t" );
				return;
			}

		public void print()
			{
				print(false);
				return;	
			}

		private void print_ws()
		/**
		*ws = with saldo
		*imprime dados da conta incluindo o saldo
		*/
			{
				print(true);
				return;	
			}
	}