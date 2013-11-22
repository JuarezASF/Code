package Repositórios;
import ClassesBásicas.Aluno;
import Interface.TerminalUserInterface;

public class RepositorioAlunoArray {
	//--------------------------------------------------
	//----------------ATRIBUTOS-------------------------
	//--------------------------------------------------
		private Aluno[] alunos;
		private int indice;
		private static final int tamCache = 100;
		private static final int NOT_FOUND = -1;
		private static final Aluno ERROR = null;
	//--------------------------------------------------
	//----------------CONSTRUTORES----------------------
	//--------------------------------------------------

		public RepositorioAlunoArray(){
			indice = 0;
			alunos = new Aluno[tamCache];
		}
	//--------------------------------------------------
	//----------------GETTERS---------------------------
	//--------------------------------------------------
		public int getIndice(){
			return indice;
			}

		public Aluno[] getAlunos(){
			return alunos;
		}

		public Aluno getAluno(int n){
			if(n>=0 && n < indice)
				return this.alunos[n];
			else 
				return null;
		}
	//--------------------------------------------------
	//----------------SETTERS---------------------------
	//--------------------------------------------------
		public void setIndice(int newI)
			{
			indice = newI;
			}

		public void setAlunos(Aluno[] newAls)
			{
			alunos = newAls;
			}
	//--------------------------------------------------
	//--------------OPERAÇÕES COMUNS--------------------
	//--------------------------------------------------
		public void inserir(Aluno newAl){
			alunos[indice] = newAl;
			indice = indice + 1;
		}

		private int procuraIndice(String targetName){
			/**-retorna o indice do aluno procurado(pelo nome)
			 * no repositório de alunos
			 * -retorna -1 caso o aluno não esteja no repositório*/
			int i = 0;
			int indFound = NOT_FOUND;
			boolean achou = false;
			
			while((i < indice) && !achou) 
				{
				if((alunos[i].getName()).equals(targetName))
					{
					indFound = i;
					achou = true;
					}
				i +=1;
				}
			if(achou == false)
				indFound = NOT_FOUND;
			
			return indFound;
			}

		public boolean existe(String targetName)
			{
			int find = this.procuraIndice(targetName);
			return (find == NOT_FOUND)? false: true;
			} 

		public boolean existe(Aluno targetAl)
			{
			if(targetAl != null)
				return existe(targetAl.getName());
			else
				return false;
			}
			
		public Aluno procurar(String targetName){
				int targetInd = procuraIndice(targetName);
				if(targetInd != NOT_FOUND)
					return alunos[targetInd];
				else
					return ERROR;
			}

		public void atualizar(Aluno newAl)
			{
				int targetInd = procuraIndice(newAl.getName());
				if(targetInd != NOT_FOUND)
					{
					alunos[targetInd] = newAl;
					}
				else {
					TerminalUserInterface.reportarErro(
							"Tentou-se atualizar um aluno não cadastrado!");
				}
			}

		 public void remover(String targetName)
			{
			 	int targetInd = procuraIndice(targetName);
			 	if(targetInd != NOT_FOUND)
			 	{
			 		alunos[targetInd] = alunos[indice-1] ;
			 		alunos[indice-1] = null;
			 		indice--;
					TerminalUserInterface.displayMsg(
							"Aluno removido com sucesso!");
			 	}
			else {
				TerminalUserInterface.reportarErro(
						"tentou-se remover Aluno não cadastrado!");
				}
			}

}//fim da classe ReposotoriosAlunosArray
