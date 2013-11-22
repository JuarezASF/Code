/**
*	Exerício 3 de POO
*	rotina main para testar as classes 'Conta' e 'Cliente'
*/

public class Test
	{
		public static void main(String args[])
			{

				Cliente Cl1 = new Cliente("Juarez", "037.691.551-06");
				Cliente Cl2 = new Cliente("Isabela", "012.345.678-90");

				Conta 	Co1 = new Conta("123-x", Cl1, 100);
				Conta 	Co2 = new Conta("456-x", Cl2, 0 );

				Cliente Cl3;
				Conta 	Co3 = new Conta("123-x", Cl3 = new Cliente("Romão", "1234134134") , 100);


				System.out.println("Os saldos iniciais são: " + Co1.getSaldo() +
							" e " + Co2.getSaldo());
			
				System.out.println("Vamos debitar 10 reais da conta 1"+
							" e creditar 10 na conta 2");
				Co1.debitar(10);
				Co2.creditar(10);

				System.out.println("Os saldos são: " + Co1.getSaldo() +
							" e " + Co2.getSaldo());

				System.out.println("Vamos transferir 20 reais da conta 1"+
									" para a conta 2");
				Co1.transferir(Co2, 20);

				System.out.println("Os saldos são: " + Co1.getSaldo() +
							" e " + Co2.getSaldo());

				System.out.println("Vamos transferir -20 reais da conta 1"+
									" para a conta 2");
				Co1.transferir(Co2, -20);

				System.out.println("Os saldos são: " + Co1.getSaldo() +
							" e " + Co2.getSaldo());

			}
	}