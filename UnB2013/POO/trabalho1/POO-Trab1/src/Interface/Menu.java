package Interface;


import ClassesBásicas.*;
import Listas.*;

public class Menu
{
	private static Menu instanciaMenu;
	private static Fachada instanciaFachada; 
	private String[] mainOption;
	private static final int nOptions = 23;
	private int exitOption;
	
	//--------------------------------------------------
	//----------------CONSTRUTORES----------------------
	//--------------------------------------------------
	
	private void init ()
		{
			mainOption = new String[nOptions];
			mainOption[0]  = "Cadastrar aluno";
			mainOption[1]  = "Procurar aluno";
			mainOption[2]  = "Atualizar aluno";
			mainOption[3]  = "Descadastrar aluno";
			mainOption[4]  = "Cadastrar curso";
			mainOption[5]  = "Procurar curso";
			mainOption[6]  = "Atualizar curso";
			mainOption[7]  = "Descadastrar curso";
			mainOption[8]  = "Matricular aluno";
			mainOption[9]  = "Procurar matrícula";
			mainOption[10]  = "Cancelar matrícula";
			mainOption[11] = "listar todas as matrículas feitas";
			mainOption[12] = "listar todos os cursos cadastrados";
			mainOption[13] = "listar todos os alunos cadastrados";
			mainOption[14] = "listar todos os alunos de um curso";
			mainOption[15] = "listar todos os alunos de todos os cursos";
			mainOption[16] = "listar todos os cursos de um aluno";
			mainOption[17] = "listar todos os cursos de todos os alunos";
			mainOption[18] = "listar todas as matriculas de um aluno";
			mainOption[19] = "listar todas as matriculas de um curso";
			mainOption[20] = "listar alunos cadastrados sem curso";
			mainOption[21] = "listar cursos cadastrado sem alunos";
			mainOption[22] = "Sair da aplicação"; 
			exitOption		= 22;
			instanciaFachada = Fachada.obterInstancia();
		}
	private Menu(){
		this.init();
	}
	
	public static Menu obterInstancia(){
		if(instanciaMenu == null)
			instanciaMenu = new Menu();
		return instanciaMenu;
	}
	//--------------------------------------------------
	//----------------GETTTERS--------------------------
	//--------------------------------------------------

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
			if(number <= nOptions && number > 0)
				return mainOption[number - 1];
			else
				return "Opção não definida!";
		}

	public int exit()
		{
			return (exitOption + 1);
		}

	public void operation(int action)
		{
			TerminalUserInterface.displayMsg("A opção escolhida foi :" + option(action) + "\n\n");
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
							case(18) : 
								mainAction18();
								break;
							case(19) : 
								mainAction19();
								break;
							case(20) : 
								mainAction20();
								break;
							case(21) : 
								mainAction21();
								break;
							case(22) : 
								mainAction22();
								break;
							case(23) : 
								mainAction23();
								break;
							default : 
								TerminalUserInterface.reportarErro("Opção Inválida!");
								break;
						}//end switch
					TerminalUserInterface.waitEnter();
			}//end function action()

	private void mainAction1()
		{//cadastrar aluno
		String nameAl = TerminalUserInterface.getName("Aluno");
		String adressAl = TerminalUserInterface.getAdress();
		String phoneAl = TerminalUserInterface.getPhone();
		int ageAl = TerminalUserInterface.getAge();
		
		Aluno newAl = new Aluno(nameAl, adressAl, phoneAl, ageAl);
		instanciaFachada.cadastarAluno(newAl);
		
		}

	private void mainAction2()
		{//procurar aluno
		String targetName = TerminalUserInterface.getName("Aluno");
		Aluno targetAluno = instanciaFachada.procurarAluno(targetName);
		if (targetAluno != null)
			{
			TerminalUserInterface.print(targetAluno);
			}
		else
			TerminalUserInterface.reportarErro("Aluno não encontrado!");
		}

	private void mainAction3()
		{//atualiza aluno
		
		TerminalUserInterface.displayMsg("Entre agora com o nome do aluno a atualizar");
		String nameAl = TerminalUserInterface.getName("Aluno");
		
		Aluno targetAluno = instanciaFachada.procurarAluno(nameAl);
		if(targetAluno != null)
			{
			TerminalUserInterface.displayMsg("Os dados atuais são:");
			TerminalUserInterface.print(targetAluno);
		
			TerminalUserInterface.displayMsg("Entre com os novos dados");
			String adressAl = TerminalUserInterface.getAdress();
			String phoneAl = TerminalUserInterface.getPhone();
			int ageAl = TerminalUserInterface.getAge();
			
			Aluno newAl = new Aluno(nameAl, adressAl, phoneAl, ageAl);
			instanciaFachada.atualizarAluno(newAl);
			
			TerminalUserInterface.displayMsg("Aluno atualizado com sucesso!");
			}
		else
			TerminalUserInterface.reportarErro("Aluno não cadastrado!");
		}

	private void mainAction4()
		{//descadastrar aluno
		String nameAl = TerminalUserInterface.getName("Aluno");
		Aluno targetAl = new Aluno(nameAl);
		instanciaFachada.descadastrarAluno(targetAl);
		}

	private void mainAction5()	
		{//cadastrar curso
		String nameCr = TerminalUserInterface.getCurseName();
		String teacherCr = TerminalUserInterface.getName("Professor");
		String codeCr = TerminalUserInterface.getCode();
		
		Curso newCr = new Curso(codeCr, nameCr, teacherCr);
		instanciaFachada.cadastrarCurso(newCr);
		}

	private void mainAction6()	
		{//procurar curso
		String targetCode = TerminalUserInterface.getCode();
		Curso target = instanciaFachada.procurarCurso(targetCode);
		if (target != null)
			{
			TerminalUserInterface.print(target);
			}
		else
			TerminalUserInterface.reportarErro("Curso não encontrado!");
		}

	private void mainAction7()	
		{//atualizar curso
				TerminalUserInterface.displayMsg("Entre agora com o código do curso a atualizar");
				String targetCodeCr = TerminalUserInterface.getCode();
				
				Curso target = instanciaFachada.procurarCurso(targetCodeCr);
				if(target != null)
					{
					TerminalUserInterface.displayMsg("Os dados atuais são:");
					TerminalUserInterface.print(target);
				
					TerminalUserInterface.displayMsg("Entre com os novos dados:");
					String nameCr = TerminalUserInterface.getCurseName();
					String teacherCr = TerminalUserInterface.getName("Professor");
					String codeCr = TerminalUserInterface.getCode();
					
					Curso newCr = new Curso(codeCr, nameCr, teacherCr);
					instanciaFachada.atualizarCurso(newCr);
					
					TerminalUserInterface.displayMsg("Curso atualizado com sucesso!");
					}
				else
					TerminalUserInterface.reportarErro("Curso não cadastrado!");
		}

	private void mainAction8()	
		{//descadastrar curso
		String codeCr = TerminalUserInterface.getCode();
		
		Curso targetCr = new Curso(codeCr);
		
		instanciaFachada.descadastrarCurso(targetCr);
		}
	private void mainAction9()	
		{//matricular aluno
		TerminalUserInterface.displayMsg("\n Para matricular aluno entre com o nome deste e o código curso desejado\n");
		String targetAlName = TerminalUserInterface.getName("Aluno");
		Aluno targetAl = instanciaFachada.procurarAluno(targetAlName);
		
		TerminalUserInterface.displayMsg("Deseja informar o código do curso a matricular?");
			String option = TerminalUserInterface.getSNOption();
		Curso targetCr;
		if(option.equals("sim"))
			{
			String targetCrCode = TerminalUserInterface.getCode();
			targetCr = instanciaFachada.procurarCurso(targetCrCode);				
			}
		else
			{
			targetCr = null ;
			}
		
		Matricula newMtrc = new Matricula(targetCr, targetAl);
		
		instanciaFachada.cadastrarMatricula(newMtrc);
		}
	private void mainAction10()	
		{//procurar matricula
		TerminalUserInterface.displayMsg("\n Para procurar matrícula entre com o nome do aluno e o código do curso\n");

		String targetAlName = TerminalUserInterface.getName("Aluno");
		Aluno targetAl = instanciaFachada.procurarAluno(targetAlName);
		
		String targetCrCode = TerminalUserInterface.getCode();
		Curso targetCr = instanciaFachada.procurarCurso(targetCrCode);
		
		Matricula targetMtrc = new Matricula(targetCr, targetAl);
		
		
		Matricula foundMtrc = instanciaFachada.procurarMatricula(targetMtrc);
		
		if(foundMtrc != null)
			TerminalUserInterface.print(foundMtrc);
		else
			TerminalUserInterface.reportarErro("Matrícula não encontrada!");
		}
	private void mainAction11()	
		{//cancelar matricula
		TerminalUserInterface.displayMsg("\n Para remover matrícula entre com o nome do aluno e o código do curso\n");

		String targetAlName = TerminalUserInterface.getName("Aluno");
		Aluno targetAl = instanciaFachada.procurarAluno(targetAlName);
		
		String targetCrCode = TerminalUserInterface.getCode();
		Curso targetCr = instanciaFachada.procurarCurso(targetCrCode);
		
		Matricula targetMtrc = new Matricula(targetCr, targetAl);
		
		instanciaFachada.descadastrarMatricula(targetMtrc);
		}
	
	private void printMtrcList(ListaMatriculas targetListMtrc)
		{
		Matricula currentMtrc;
		
		while(targetListMtrc.hasNext())
			{
			currentMtrc = targetListMtrc.next();
			TerminalUserInterface.print(currentMtrc);
			TerminalUserInterface.displayMsg("\n");			
			}
		TerminalUserInterface.displayMsg("Não existem mais matrículas \n");
		}
	
	private void mainAction12()	
		{//listar todas as matrículas feitas
		ListaMatriculas listaMtrc = instanciaFachada.getListAllMtrc();
		printMtrcList(listaMtrc);
		}

	private void printCrList(ListaCursos targetListCr)
		{
		Curso currentCr;
		
		while(targetListCr.hasNext())
			{
			currentCr = targetListCr.next();
			TerminalUserInterface.print(currentCr);
			TerminalUserInterface.displayMsg("\n");
			}
		TerminalUserInterface.displayMsg("Não existem mais cursos \n");
		}
	
	private void mainAction13()	
		{//listar todos os cursos cadastrados
		ListaCursos listCr = instanciaFachada.getListAllCr();
		printCrList(listCr);
		}

	private void printAlList(ListaAlunos targetListAl)
		{
		Aluno currentAl;
		
		while(targetListAl.hasNext())
			{
			currentAl = targetListAl.next();
			TerminalUserInterface.print(currentAl);
			TerminalUserInterface.displayMsg("\n");
			}
		TerminalUserInterface.displayMsg("Não existem mais alunos\n");
		}
	
	private void mainAction14()	
		{//listar todos os alunos cadastrados
		ListaAlunos listaAl = instanciaFachada.getListAllAl();
		printAlList(listaAl);
		}

	private void printMtrcList(ListaMatriculas targetListMtrc, int option)
		//option decide se imprime aluno ou curso
		//1 para aluno
		//2 para curso
		// 3 para matrículaou default 
		{
		Matricula currentMtrc;
		 final int  OP_ALUNO = 1;
		 final int OP_CURSO  = 2;
		 final int OP_MTRC = 3;
		
		while(targetListMtrc.hasNext())
			{
			currentMtrc = targetListMtrc.next();
			switch(option)
				{
				case OP_ALUNO :
					TerminalUserInterface.print(currentMtrc.getAluno(), 1);
					TerminalUserInterface.displayMsg("\n");
					break;
				case OP_CURSO :
					TerminalUserInterface.print(currentMtrc.getCurso(), 2);
					TerminalUserInterface.displayMsg("\n");
					break;
				case OP_MTRC:
				default :
					TerminalUserInterface.print(currentMtrc, 3);
					TerminalUserInterface.displayMsg("\n");
					break;
				}
			}
		switch(option)
			{
			case OP_ALUNO :
				TerminalUserInterface.displayMsg("Não existem mais alunos\n");
				break;
			case OP_CURSO :
				TerminalUserInterface.displayMsg("Não existem mais cursos\n");				
				break;
			case OP_MTRC :
			default : 
				TerminalUserInterface.displayMsg("Não existem mais matrículas\n");				
			}
		}//fim de void printMtrcList(ListaMatriculas targetListMtrc, int option)
	
	
	private void mainAction15()	
	{//listar todos os alunos de um curso
		String targetCode = TerminalUserInterface.getCode();
		Curso targetCr = instanciaFachada.procurarCurso(targetCode);
		if(instanciaFachada.existe(targetCr))
			{
			ListaMatriculas listaCrMtrc = instanciaFachada.getListAllMtrcByCr(targetCr);
			
			final int PRINT_ALUNOS = 1;
			printMtrcList(listaCrMtrc, PRINT_ALUNOS);
			}
		else
			TerminalUserInterface.reportarErro("Curso não encontrado!");
	}
	
	private void mainAction16()	
	{//listar todos os alunos de todos os cursos
		ListaCursos listCr = instanciaFachada.getListAllCr();
		final int PRINT_ALUNOS = 1;
		
		while(listCr.hasNext())
			{
			Curso currentCr = listCr.next();
			TerminalUserInterface.print(currentCr, 2);
			TerminalUserInterface.displayMsg("\n");
			ListaMatriculas listaCrMtrc = instanciaFachada.getListAllMtrcByCr(currentCr);
			printMtrcList(listaCrMtrc, PRINT_ALUNOS);
			TerminalUserInterface.displayMsg("\n\n");
			}
		TerminalUserInterface.displayMsg("Não existe mais nada a listar");
	}
	private void mainAction17()	
	{//listar todos os cursos de um aluno
		String targetName = TerminalUserInterface.getName("aluno");
		Aluno targetAl = instanciaFachada.procurarAluno(targetName);
		
		if(instanciaFachada.existe(targetAl))
		{
			ListaMatriculas listaCrMtrc = instanciaFachada.getListAllMtrcByAl(targetAl);
			
			final int PRINT_CURSOS = 2;
			printMtrcList(listaCrMtrc, PRINT_CURSOS);
		}
		else
			TerminalUserInterface.reportarErro("Aluno não encontrado!");
	}
	
	private void mainAction18()	
	{//listar todos os cursos de todos os alunos
		ListaAlunos listAl = instanciaFachada.getListAllAl();
		final int PRINT_CURSOS = 2;
		
		while(listAl.hasNext())
			{
			Aluno currentAl = listAl.next();
			TerminalUserInterface.print(currentAl, 1);
			TerminalUserInterface.displayMsg("\n");
			
			ListaMatriculas listaCrMtrc = instanciaFachada.getListAllMtrcByAl(currentAl);
			printMtrcList(listaCrMtrc, PRINT_CURSOS);
			TerminalUserInterface.displayMsg("\n\n");
			}
		TerminalUserInterface.displayMsg("Não existe mais nada a listar");
	}
	private void mainAction19()	
	{//listas todas as matrículas de um aluno
		String targetName = TerminalUserInterface.getName("aluno");
		Aluno targetAl = instanciaFachada.procurarAluno(targetName);
		
		if(instanciaFachada.existe(targetAl))
		{
			ListaMatriculas listaCrMtrc = instanciaFachada.getListAllMtrcByAl(targetAl);
			
			final int PRINT_MTRC = 3;
			printMtrcList(listaCrMtrc, PRINT_MTRC);
		}
		else
			TerminalUserInterface.reportarErro("Aluno não encontrado!");
	}
	private void mainAction20()	
	{//listar todas as matrículas de um curso
		String targetCode = TerminalUserInterface.getCode();
		Curso targetCr = instanciaFachada.procurarCurso(targetCode);
		if(instanciaFachada.existe(targetCr))
			{
			ListaMatriculas listaCrMtrc = instanciaFachada.getListAllMtrcByCr(targetCr);
			
			final int PRINT_MTRC = 3;
			printMtrcList(listaCrMtrc, PRINT_MTRC);
			}
		else
			TerminalUserInterface.reportarErro("Curso não encontrado!");
	}
	private void mainAction21()	
	{//listar todos os alunos cadastrados sem curso
		ListaAlunos targetList= instanciaFachada.getListAllAl();
		
		TerminalUserInterface.displayMsg("\nAlunos sem curso:\n\n");
		while(targetList.hasNext())
		{
			Aluno current = targetList.next();
			if(current.getNCurses() == 0)
				TerminalUserInterface.print(current);
			TerminalUserInterface.displayMsg("\n");
		}
		TerminalUserInterface.displayMsg("Não há mais alunos sem curso");		
	}
	private void mainAction22()	
	{//listar cursos cadastrados sem alunos
		ListaCursos targetList= instanciaFachada.getListAllCr();
		
		TerminalUserInterface.displayMsg("\nCursos sem alunos:\n\n");
		while(targetList.hasNext())
		{
			Curso current = targetList.next();
			if(current.getNStudents() == 0)
				TerminalUserInterface.print(current);
			TerminalUserInterface.displayMsg("\n");
		}
		TerminalUserInterface.displayMsg("Não há mais cursos sem alunoss");	
	}
	private void mainAction23()	
	{//sair
	TerminalUserInterface.displayMsg("Obrigado por usar a aplicação! POO Trab 1");

	TerminalUserInterface.displayMsg("\n\n Juarez A.S.F. \t UnB - 2º/2013 - 11/0032829\n\n");
	}
	
}//end class Menu
