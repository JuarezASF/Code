
public class StringClass
{
	public static void main(String args[])
		{
		System.out.println("\n\n\n Testamos agora com inicialização direta!");
		String  s1 = "Juarez";
		String  s2 = "Juarez";

		System.out.println("A soma dos comprimentos de "+
			"s1 com s2 é : " + (s1.length() + s2.length()) );

		if(s1.equals(s2))
			{
			System.out.println("O conteúdo dos dois strings é igual!");
			}
		if(s1 == s2)
			{
			System.out.println("Os dois objetos são os mesmos!");
			}

		System.out.println("\n\n\n Testamos agora com alocação com construtor!");

		String  s3 = new String("Juarez");
		String  s4 = new String("Juarez");

		System.out.println("A soma dos comprimentos de "+
		"s3 com s4 é : " + (s3.length() + s4.length()) );


		if(s3.equals(s4))
			{
			System.out.println("O conteúdo dos dois strings é igual!");
			}//os dois objetos possuem o mesmo conteúdo
		if(s3 == s4)
			{
			System.out.println("Os dois objetos são os mesmos!");
			}//vê-se que os dois objetos são diferentes
		}

}