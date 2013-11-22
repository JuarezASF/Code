/**
 * SwitchJava:
 * 
 * Exercício 2 de POO :
 * 	-testar a construção com switch com e sem break
 * 
 * */
public class SwitchTest
	{
		public static void main(String[] args)
			{
			int i = 3;
			
			System.out.println("Teste de switch com break");
			switch(i)
				{
				case 1:
					System.out.println("1");
					break;
				case 2:
					System.out.println("2");
					break;
				case 3:
					System.out.println("3");
					break;
				case 4:
					System.out.println("4");
					break;
				default:
					break;
				}
			
			System.out.println("Teste de switch sem break");
			switch(i)
				{
				case 1:
					System.out.println("1");
					
				case 2:
					System.out.println("2");
					
				case 3:
					System.out.println("3");
					
				case 4:
					System.out.println("4");
					
				default:
					
				}
			
			
			}
	}
