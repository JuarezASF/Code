import java.util.Scanner;
import java.util.Locale;

public class UserInterface
{
	public static void main(String[] args)
		{
			Scanner sc = new Scanner(System.in);
			sc.useLocale(Locale.US);
			//espera-se que os valores sejam entrados com pontos: 5.3 e não 5,3

			RepositorioClienteArray clientes = new RepositorioClienteArray();
			RepositorioContasArray  contas = new RepositorioContasArray();
			Menu mainMenu = new Menu(clientes, contas);	
			
			while(true)
				{
					mainMenu.cleanScreen();
					display(mainMenu);
					System.out.println("\n\nFavor escolher uma opção: ");
					int action = sc.nextInt();
					if( action == mainMenu.exit())
						{
						mainMenu.cleanScreen();
						System.out.println("\n\n\nFim da rotina\n\n\n");
						return;
						}
					else
						mainMenu.operation(action, clientes, contas);
				}//end loop while

		}//end function main

 	static	public void display(Menu mainMenu)
		{
			for(int i = 0; i < mainMenu.getNoptions(); i++)
				{
					System.out.println(i+1 + "- " + mainMenu.option(i));
					
				}//end for
		}//end function display
}//end class UserInterface