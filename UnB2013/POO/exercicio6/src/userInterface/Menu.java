package userInterface;

import listas.*;
import cadastros.*;
import classasBasicas.*;


public class Menu
{
	private static Menu instanciaMenu;
	private static fachada myFachada; 
	private String[] mainOption;
	private static final int nOptions = 17;
	private int exitOption;

	
	
	private void init()
		{
			mainOption = new String[nOptions];
			mainOption[0]  = "Criar Cliente";
			mainOption[1]  = "Consultar Cliente";
			mainOption[2]  = "Atualizar Cliente";
			mainOption[3]  = "Remover Cliente";
			mainOption[4]  = "Criar Conta";
			mainOption[5]  = "Consultar Conta";
			mainOption[6]  = "Atualizar Conta";
			mainOption[7]  = "Remover Conta";
			mainOption[8]  = "Creditar em Conta";
			mainOption[9]  = "Debitar de Conta";
			mainOption[10] = "Transferir entre contas";
			mainOption[11] = "Exibir dados de uma conta de um cliente";
			mainOption[12] = "Exibir os dados de todas as contas";
			mainOption[13] = "Exibir dados de todos os clientes";
			mainOption[14] = "Render bonus";
			mainOption[15] = "Render Juros";
			mainOption[16] = "Sair da aplicação"; 
			exitOption		= nOptions + 1;
			myFachada = fachada.obterInstancia();
		}
	private Menu(){
		this.init();
	}
	
	public static Menu obterInstancia(){
		if(instanciaMenu == null)
			instanciaMenu = new Menu();
		return instanciaMenu;
	}


	public int getNoptions()
		{
			return nOptions;
		}

	public String option(int number)
		{
			if(number <= nOptions)
				return mainOption[number - 1];
			else
				return "Opção não definida!";
		}

	public int exit()
		{
			return (exitOption);
		}

	public void operation(int action)
		{
			this.cleanScreen();
			System.out.println("A opção escolhida foi :" + option(action) + "\n\n");
			switch(action)
						{
							case(1) :
								mainAction1();
								break;							
							case(2) : 
								mainAction2();
								break;
							case(3) : 
								mainAction3();
								break;
							case(4) : 
								mainAction4();
								break;
							case(5) : 
								mainAction5();
								break;
							case(6) : 
								mainAction6();
								break;
							case(7) : 
								mainAction7();
								break;
							case(8) : 
								mainAction8();
								break;
							case(9) : 
								mainAction9();
								break;
							case(10) : 
								mainAction10();
								break;
							case(11) : 
								mainAction11();
								break;
							case(12) : 
								mainAction12();
								break;
							case(13) : 
								mainAction13();
								break;
							case(14) : 
								mainAction14();
								break;
							case(15) : 
								mainAction15();
								break;
							case(16) : 
								mainAction16();
								break;
							case(17) : 
								mainAction17();
								break;
							default : 
								UserInterface.report("Opção Inválida!");
								break;
						}//end switch
					UserInterface.waitEnter();
			}//end function action()

	private void mainAction1()
		{//cria novo cliente
		String newName = UserInterface.getName("novo cliente");	
		String newCpf  = UserInterface.getCpf("novo cliente") ;
		Cliente newC = new Cliente(newName, newCpf);
		
		myFachada.cadastrar(newC);
		}

	private void mainAction2()
		{//consulta cliente
		String targetCpf  = UserInterface.getCpf("cliente", "ser consultado") ;
		Cliente target = new Cliente(" ", targetCpf);

		Cliente found = myFachada.procurar(target);
		
		if(found != null)
			{
			UserInterface.report("Cliente achado com sucesso!");
			UserInterface.print(found, 2);
			}
		
		}

	private void mainAction3()
		{//atualiza cliente
	
		String targetCpf  = UserInterface.getCpf("cliente", "ser atualizado") ;
		Cliente update = new Cliente (" ", targetCpf);
		Cliente target = myFachada.procurar(update);

			if(target != null)
				{
				String newName = UserInterface.getName("cliente", "novo nome");	
				update = new Cliente(newName, targetCpf);
				myFachada.atualizar(update);
				}
		}

	private void mainAction4()
		{//remove cliente
		String targetCpf  = UserInterface.getCpf("cliente", "ser removido") ;		
		Cliente target = new Cliente("", targetCpf);
			
		myFachada.descadastrar(target);
		}

	private void mainAction5()	
		{//cria nova conta para cliente
			
			String targetCpf = UserInterface.getCpf("cliente",
												" criar nova conta");		
			Cliente target = new Cliente("", targetCpf);
			
			String newNumber = UserInterface.getCNumber();
			
			UserInterface.ask("Qual o tipo da conta desejada?\n"+
			"digite:\n[1] para normal(default)\n" +
					  "[2] para bonificada\n" + 
						"[3] para poupança:");
			int option = UserInterface.getOption(1, 3, 1);
					
			switch(option)
			{
				case(1):
					Conta newC = new Conta(newNumber, target);
					myFachada.cadastrar(newC);	
					break;
				case(2):
					ContaBonificada newCB = new ContaBonificada(newNumber, target);
					myFachada.cadastrar(newCB);	
				break;
				case(3):	
					Poupanca newP = new Poupanca(newNumber, target);
					myFachada.cadastrar(newP);
					break;
			}
		}

	private void mainAction6()	
		{//consulta conta

		String targetNumber = UserInterface.getCNumber("a ser consultada");
				
		Conta target = new Conta(targetNumber, null);
		Conta found = myFachada.procurar(target);

			if(found != null)
				UserInterface.print(found, 3);
		}

	private void mainAction7()	
		{//atualiza conta
/*		String targetNumber = UserInterface.getCNumber("ser atualizada") ;
		Conta update = new Conta (targetNumber, null);
		Conta target = myFachada.procurar(update);

			if(target != null)
				{
				String newNumber = UserInterface.getCNumber("novo número");
				String newName = UserInterface.getName("cliente", "novo nome");	
				update = new Cliente(newName, targetCpf);
				myFachada.atualizar(update);
				}
	*/
		UserInterface.report("A operação não foi implementada!");

		}

	private void mainAction8()	
		{//remove conta
		String targetNumber = UserInterface.getCNumber("ser removida") ;
		Conta target = new Conta (targetNumber, null);
			
		myFachada.descadastrar(target);

		}
	private void mainAction9()	
		{//credita em conta
		String targetNumberDestino = UserInterface.getCNumber("conta de destino") ;			
		Conta target = new Conta (targetNumberDestino, null);
		
		double value = UserInterface.getValue("a ser creditado na conta");
	
		myFachada.creditar(target, value);
		}
	private void mainAction10()	
		{//debita em conta
		String targetNumberDestino = UserInterface.getCNumber("conta de destino") ;			
		Conta target = new Conta (targetNumberDestino, null);
		
		double value = UserInterface.getValue("a ser debitado na conta");
	
		myFachada.debitar(target, value);
		}
	private void mainAction11()	
		{//transferir entre contas
		
		String NumberOrigem = UserInterface.getCNumber("conta de origem") ;			
		Conta origem = new Conta (NumberOrigem, null);
		
		String NumberDestino = UserInterface.getCNumber("conta de destino") ;			
		Conta destino = new Conta (NumberDestino, null);
		
		double value = UserInterface.getValue("a ser transferido");
	
		myFachada.transferir(origem, destino, value);
		}
	
	private void mainAction12()	
		{//consultar conta de um cliente
			String targetCpf = UserInterface.getCpf("cliente", "a consultar contas");
			Cliente target = new Cliente ("", targetCpf);
			Cliente found = myFachada.procurar(target);
			listaContas targetList = myFachada.listaContasCliente(found);

			while(targetList.hasNext())
				{
				Conta current = targetList.next();
				UserInterface.print(current, 3);
				UserInterface.report("\n");
				}
			
			UserInterface.report("Não há mais contas desse cliente");
		}

	private void mainAction13()	
		{//exibir os dados de todas as contas
		listaContas targetList = myFachada.listaContas();

		while(targetList.hasNext())
			{
			Conta current = targetList.next();
			UserInterface.print(current, 3);
			UserInterface.report("\n");
			}
		
		UserInterface.report("Não há mais contas no sistema");
		}

	private void mainAction14()	
		{//exibir dados de todos os clientes
		listaClientes targetList = myFachada.listaClientes();

		while(targetList.hasNext())
			{
			Cliente current = targetList.next();
			UserInterface.print(current, 3);
			UserInterface.report("\n");
			}
		
		UserInterface.report("Não há mais clientes no sistema");
		}

	private void mainAction15()	
		{
		String targetN = UserInterface.getCNumber("a render bonus");
		Conta target = new Conta (targetN, null);
		Conta found = myFachada.procurar(target);
		
		myFachada.renderBonus(found);
		return;
		}

	private void mainAction16()	
		{	
		String targetN = UserInterface.getCNumber("a render juros");
		Conta target = new Conta (targetN, null);
		Conta found = myFachada.procurar(target);
		
		myFachada.renderJuros(found);

		return;
		}

	
	private void mainAction17()	
	{//sair
		UserInterface.display("Obrigado por usar a aplicação! POO exercício 6 : Interfaces");

		UserInterface.display("\n\n Juarez A.S.F. \t UnB - 2º/2013 - 11/0032829\n\n");
	}	

	 public void cleanScreen()
		{
			for(int i = 0; i < 30; i++)
				UserInterface.display("\n");
		}

}//end class Menu