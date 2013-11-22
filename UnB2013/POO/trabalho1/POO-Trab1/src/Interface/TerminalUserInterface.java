package Interface;

import java.util.Scanner;
import java.util.Locale;
import ClassesBásicas.*;


public class TerminalUserInterface {
	private static Menu instanciaMenu;
	private static Scanner sc;
	private static final int INITIAL_OPTION = -1;
	
	public static void main(String[] args) {
		init();
		int option = INITIAL_OPTION;
		
		do{
			display(instanciaMenu);
			displayMsg("\n\nFavor escolher uma opção: ");
			option = getOption();
			instanciaMenu.operation(option);
		}while(option != instanciaMenu.exit());
		
	}

	public static void reportarErro(String errorMsg){
		System.out.println(errorMsg);
	}
	
	public static void displayMsg(String msg){
		System.out.println(msg);
	}
	
	
	private static void init(){ 
		instanciaMenu = Menu.obterInstancia();
		sc = new Scanner(System.in);
		sc.useLocale(Locale.US);
	}
	
	public static int getOption() {
		int option = sc.nextInt();
		//pula o ENTER digitado
		//usar isso toda vez que pegar dado com next
		sc.nextLine();

		return option;
	}
	
	 public void cleanScreen()
		{
			for(int i = 0; i < 30; i++)
				displayMsg("\n");
		}

	 public static void waitEnter()
		{
			displayMsg("ENTER para continuar");
				sc.nextLine();	
		}	
	 static	public void display(Menu mainMenu)
		{
			for(int i = 1; i <= mainMenu.getNoptions(); i++)
			{
				displayMsg(i + "- " + mainMenu.option(i));				
			}//end for
		}
	 static public String getName(String type){
		 displayMsg("Entre com o nome do " + type +"(a):");
		 String target = sc.nextLine();
		 return target;
	 }
	 
	 static public String getPhone(){
		 displayMsg("Entre com o telefone");
		 String target = sc.nextLine();
		 return target;
	 }

	 static public String getAdress(){
		 displayMsg("Entre com o endereço do aluno(a)");
		 String target = sc.nextLine();
		 return target;
	 }
	 
	 static public int getAge(){
		 displayMsg("Entre com a ideade do aluno(a)");
		 int target = sc.nextInt();
		 sc.nextLine();
		 return target;
	 }

	 static public String getCode(){
		 displayMsg("Entre com o código do curso");
		 String target = sc.nextLine();
		 return target;
	 }

	 static public String getCurseName(){
		 displayMsg("Entre com o nome do curso");
		 String target = sc.nextLine();
		 return target;
		
	 }
	 
	 static public String getSNOption(){
		 String target = sc.nextLine();
		 
		 if(target.equalsIgnoreCase("s") || target.equalsIgnoreCase("sim") ||
				 target.equalsIgnoreCase("y") || target.equalsIgnoreCase("yes"))
		 	return "sim";
		 else
			 return "não";
	 }
	 
	 static public void print(Aluno target){
		 displayMsg("Nome:" + target.getName() );
		 displayMsg("idade:" + target.getAge() );
		 displayMsg("telefone: " + target.getPhone() );
		 displayMsg("endereço:" + target.getAdress() );
	 }

	 static public void print(Aluno target, int option){
		 //option controla o número de parâmtros a imprimir
		 // na ordem: nome, idade, telefone, endereço
		 switch(option)
		 	{
		 	case 1:
		 		displayMsg("Nome:" + target.getName() );
		 		break;
		 	case 2:
		 		displayMsg("Nome:" + target.getName() );
		 		displayMsg("idade:" + target.getAge() );
		 		break;
		 	case 3:
		 		displayMsg("Nome:" + target.getName() );
		 		displayMsg("idade:" + target.getAge() );
		 		displayMsg("telefone: " + target.getPhone() );
		 		break;
		 	case 4:
		 	default:
		 		displayMsg("Nome:" + target.getName() );
		 		displayMsg("idade:" + target.getAge() );
		 		displayMsg("telefone: " + target.getPhone() );
		 		displayMsg("endereço:" + target.getAdress() );
		 		break;
		 	}
		 }
	 
	 static public void print(Curso target){
		 displayMsg("Nome:" + target.getName() );
		 displayMsg("Professor:" + target.getTeacher() );
		 displayMsg("Código: " + target.getCode() );
		 displayMsg("nº de alunos matriculados:" + target.getNStudents() );
	 }
	 static public void print(Curso target, int option){
		 //option controla o número de parâmtros a imprimir
		 // na ordem: nome, código, professor, nº de estudantes
		 switch(option)
		 	{
		 	case 1:
				 displayMsg("Nome do curso:" + target.getName() );
		 		break;
		 	case 2:
				 displayMsg("Nome do curso:" + target.getName() );
				 displayMsg("Professor:" + target.getCode());
		 		break;
		 	case 3:
				 displayMsg("Nome do curso:" + target.getName() );
				 displayMsg("Professor:" + target.getTeacher() );
				 displayMsg("Código: " + target.getCode() );
				 break;
		 	case 4:
		 	default:
				 displayMsg("Nome do curso:" + target.getName() );
				 displayMsg("Professor:" + target.getTeacher() );
				 displayMsg("Código: " + target.getCode() );
				 displayMsg("nº de alunos matriculados:" + target.getNStudents() );		 	
				}
		 }
	 static public void print(Matricula target){
		 displayMsg("Aluno:" + target.getAluno().getName());
		 displayMsg("Curso:" + target.getCurso().getCode() );
		 displayMsg("Número: " + target.getNumber() );
	 }
	 
	 static public void print(Matricula target, int option){
		 //option controla o número de parâmtros a imprimir
		 // na ordem: nome, código, professor, nº de estudantes
		 switch(option)
		 	{
		 	case 1:
				 displayMsg("código do Curso:" + target.getCurso().getCode() );
		 		break;
		 	case 2:
				 displayMsg("código do Curso:" + target.getCurso().getCode() );
				 displayMsg("Número da matrícula: " + target.getNumber() );
		 		break;
		 	case 3:
		 	default:
				 displayMsg("código do Curso:" + target.getCurso().getCode() );
				 displayMsg("Número da matrícula: " + target.getNumber() );
				 displayMsg("Aluno:" + target.getAluno().getName());	
		 	}
		 }

	 
	 
}//fim da classe TerminarUserInterface
