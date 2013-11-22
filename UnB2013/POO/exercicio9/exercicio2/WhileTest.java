/**
 *AloMundo 
 * parte do Exercício 2 de POO
 *	escrever uma função que escreva os números de 0 -> 10
 * usando um while e um doWhile	
 * */
 
 public class WhileTest
	{
			public static void main(String[] args)	
				{
				int i = 0;
				
				System.out.println("\n Teste com while");
				while(i<=10)
					{
					System.out.println(i++);
					}

				System.out.println("\n Teste com do-while");
				i = 0;
				do
					{
					System.out.println(i++);
					}while(i<=10);
				return;
				}
		
	}

