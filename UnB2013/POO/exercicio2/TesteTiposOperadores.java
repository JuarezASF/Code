/**
 * Fatorial
 * 
 * -Exercício 2 de POO
 *   TESTAR algumas propriedades de tipos e conversões
 * */
 
 public class TesteTiposOperadores
	{
		public static void main(String[] args)
			{
			 int a = 2; int b = a++; System.out.println(b);//2

			 int c = 2; int d = (++c); System.out.println(d);//3

			 int e = 0; boolean bol1 = (2<0) && (++e<3); System.out.println(e);//0

			 int f = 1; boolean bol2 = (2<1) & (f++>4); System.out.println(f);//2

			 int g = 3; int h= (g++== 4) ? 2:1; System.out.println(h);//1
			}
			
	}
