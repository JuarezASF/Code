import java.util.Scanner;
import java.util.Locale;

public class Menu
{
	private String[] mainOption;
	private static final int nOptions = 15;
	private int exitOption;
	private RepositorioClienteArray clientes;
	private RepositorioContasArray  contas;
	private Scanner sc; 
	
	
	public Menu(RepositorioClienteArray clientes, RepositorioContasArray contas)
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
			mainOption[14] = "Sair da aplicação"; 
			exitOption		= 14;
		
			this.clientes = clientes;
			this.contas   = contas; 	

			sc = new Scanner(System.in);
			sc.useLocale(Locale.US);
		}

	public int getNoptions()
		{
			return nOptions;
		}

	public String[] getMainOption()
		{
			return mainOption;
		}

	public String option(int number)
		{
			if(number < nOptions)
				return mainOption[number];
			else
				return "Opção não definida!";
		}

	public int exit()
		{
			return (exitOption + 1);
		}

	public void operation(int action, RepositorioClienteArray clientes, RepositorioContasArray contas)
		{
			System.out.println("A opção escolhida foi :" + option(action - 1));
			this.cleanScreen();

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
							default : 
								System.out.println("Opção Inválida!");
								break;
						}//end switch
					waitEnter();
			}//end function action()

	private void mainAction1()
		{//cria novo cliente
			System.out.println("Entre com o nome do novo cliente:");
			// pula o caracter de mudanca de linha '\n', ou seja o Enter, que foi digitado na leitura do inteiro acima
     		//String linha = sc.nextLine();
			
				String newName = sc.nextLine();	
			
			System.out.println("Entre com o Cpf do novo cliente:");
				String newCpf = sc.next();

			Cliente newCliente = new Cliente(newName, newCpf);
			clientes.inserir(newCliente);
			System.out.println("Cliente adicionado com sucesso!");
		}

	private void mainAction2()
		{//consulta cliente
			System.out.println("Entre com o Cpf do cliente a ser consultado:");
				String targetCpf = sc.next();

			Cliente target = clientes.procurar(targetCpf);

			if(target != null)
				target.print();
		}

	private void mainAction3()
		{//atualiza cliente
			System.out.println("Entre com o Cpf do cliente a ser atualizado:");
				String targetCpf = sc.next();

			Cliente target = clientes.procurar(targetCpf);

			if(target != null)
				{
				System.out.println("Entre com o novo nome do cliente:");
					String newName = sc.nextLine();

				Cliente newCliente = new Cliente(newName, targetCpf);

				clientes.atualizar(newCliente);

				System.out.println("Cliente atualizado com sucesso!");
				}
		}

	private void mainAction4()
		{//remove cliente
			System.out.println("Entre com o Cpf do cliente a ser removido");
				String targetCpf = sc.next();

			Cliente target = clientes.procurar(targetCpf);
			
			clientes.remover(targetCpf);

			if(target != null)
				System.out.println("Cliente removido com sucesso!");

		}

	private void mainAction5()	
		{//cria nova conta para cliente
			System.out.println("Entre com o Cpf do cliente para criar uma conta");
			String targetCpf = sc.next();						
		
			if(clientes.existe(targetCpf))
				{
					System.out.println("Entre com o número da nova conta");
					String newNumber = sc.next();
					Conta newC = new Conta(newNumber, targetCpf);
					
					contas.inserir(newC);

					System.out.println("Nova conta criada com sucesso!");
				}
		}

	private void mainAction6()	
		{//consulta conta
			System.out.println("Entre com o número da conta a ser consultada:");
				String targetNumber = sc.next();

			Conta target = contas.procurar(targetNumber);

			if(target != null)
				target.print();
		}

	private void mainAction7()	
		{//atualiza conta
			System.out.println("Entre com a conta a ser atualizada:");
				String targetNumber = sc.next();

			Conta target = contas.procurar(targetNumber);

			if(target != null)
				{
				System.out.println("Entre com o novo dono da conta:");
					String newDono = sc.nextLine();


				System.out.println("Entre com o novo saldo da conta:");
					double newSaldo = sc.nextDouble();

				Conta newConta = new Conta(targetNumber, newDono, newSaldo);

				contas.atualizar(newConta);

				System.out.println("Conta atualizada com sucesso!");
				}
		}

	private void mainAction8()	
		{//remove conta
			System.out.println("Entre com o numero da conta a ser removida");
				String targetNumber = sc.next();

			Conta target = contas.procurar(targetNumber);
			
			contas.remover(targetNumber);

			if(target != null)
				System.out.println("Conta removida com sucesso!");
		}
	private void mainAction9()	
		{//credita em conta
			System.out.println("Entre com o numero da conta a ser creditada");
			String targetNumber = sc.next();			

			System.out.println("Entre com o valor a ser creditado");
			Double value = sc.nextDouble();

			Conta target = contas.procurar(targetNumber);

			target.creditar(value);
		}
	private void mainAction10()	
		{//debita em conta
			System.out.println("Entre com o numero da conta a ser debitada");
			String targetNumber = sc.next();			

			System.out.println("Entre com o valor a ser debitado");
			Double value = sc.nextDouble();

			Conta target = contas.procurar(targetNumber);

			target.debitar(value);
			
		}
	private void mainAction11()	
		{//transferir entre contas
			System.out.println("Entre com o numero da conta de origem");
			String srcNumber = sc.next();			

			System.out.println("Entre com o numero da conta destino");
			String targetNumber = sc.next();

			System.out.println("Entre com a valor a ser transferido");
			Double value = sc.nextDouble();

			Conta src = contas.procurar(srcNumber);
			Conta target = contas.procurar(targetNumber);

			if(src != null && target !=null)			
				src.transferir(target, value);
			else
				System.out.println("Problema com a transferência!"+
						" Uma das contas, ou as duas, não pode ser encontrada");
		}
	private void mainAction12()	
		{//consultar conta de um cliente
			System.out.println("Entre com o Cpf de um cliente para consultar suas contas");
			String targetCpf = sc.next();			
			Cliente targetCl = clientes.procurar(targetCpf);
			int n = 1;
			Conta targetContaN= contas.procuraCliente(targetCl, n);
			//guarda a n-ésima conta do cliente

				while(targetContaN != null)	
					{
					System.out.println("\n"+n+"º conta: ");
					targetContaN.print();
					targetContaN = contas.procuraCliente(targetCl, ++n);
					}
				System.out.println("Não há mais contas desse cliente");
		}

	private void mainAction13()	
		{//exibir os dados de todas as contas
			int n=0;
			Conta current = contas.getConta(n);

			while(current != null)
				{
				System.out.println("\n"+n+"º conta: ");
				current.print_ws();
				current = contas.getConta(++n);
				}
			System.out.println("Não há mais contas no sistema");
		}

	private void mainAction14()	
		{//exibir dados de todos os clientes
			int n=0;
			Cliente current = clientes.getCliente(n);

			while(current != null)
				{
				System.out.println("\n"+n+"º cliente: ");
				current.print();
				current = clientes.getCliente(++n);
				}
			System.out.println("Não há mais clientes no sistema");	
		}

	 public void cleanScreen()
		{
			for(int i = 0; i < 30; i++)
				System.out.println("\n");
		}

public void waitEnter()
		{
			Scanner sc = new Scanner(System.in);
			sc.useLocale(Locale.US);
			System.out.println("ENTER para continuar");
				sc.nextLine();				
		}	

}//end class Menu