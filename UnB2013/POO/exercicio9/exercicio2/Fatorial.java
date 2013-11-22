/**
 * Fatorial
 * 
 * -Exercício 2 de POO
 *   calcular o fatorial de uma variável inteira e imprimir na tela
 * */
 
 public class Fatorial
	{
		public static void main(String[] args)
			{
				int d = 5;
				int d_fat, aux;
				
				System.out.println("Calculando fatorial com while!");
				d_fat = 1;
				aux = d;
				while(aux > 1)
						d_fat *= aux--;
				System.out.println("O fatorial calculado de " + d + " é: " + d_fat+ "\n\n");
		
				System.out.println("Calculando fatorial com for!");
				d_fat = 1;
				for(aux = 1; aux <=d; aux++)
					d_fat*=aux;
				System.out.println("O fatorial calculado de  " + d + "  é: " + d_fat + "\n\n");
			
			
			}
		
	}
