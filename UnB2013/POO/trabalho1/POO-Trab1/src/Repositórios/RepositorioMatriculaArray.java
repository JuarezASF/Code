package Repositórios;

import ClassesBásicas.Matricula;
import Interface.TerminalUserInterface;

public class RepositorioMatriculaArray {
	//--------------------------------------------------
	//----------------ATRIBUTOS-------------------------
	//--------------------------------------------------
		private Matricula[] matriculas;
		private int indice;
		private static final int tamCache = 100;
		private static final int NOT_FOUND = -1;
		private static final Matricula ERROR = null;
	//--------------------------------------------------
	//----------------CONSTRUTORES----------------------
	//--------------------------------------------------

		public RepositorioMatriculaArray(){
			indice = 0;
			matriculas = new Matricula[tamCache];
		}
	//--------------------------------------------------
	//----------------GETTERS---------------------------
	//--------------------------------------------------
		public int getIndice(){
			return indice;
			}

		public Matricula[] getMatriculas(){
			return matriculas;
		}

		public Matricula getMatricula(int n){
			if(n>=0 && n < indice)
				return this.matriculas[n];
			else 
				return ERROR;
		}
	//--------------------------------------------------
	//----------------SETTERS---------------------------
	//--------------------------------------------------
		public void setIndice(int newI)
			{
			indice = newI;
			}

		public void setMatriculas(Matricula[] newMtcls)
			{
			matriculas = newMtcls;
			}
	//--------------------------------------------------
	//--------------OPERAÇÕES COMUNS--------------------
	//--------------------------------------------------
		public void inserir(Matricula newCr){
			newCr.makeMember();
			matriculas[indice] = newCr;
			indice = indice + 1;
		}

		private int procuraIndice(int targetNumber){
			/**-retorna o indice do Matricula procurado(pelo numero)
			 * no repositório de Matriculas
			 * -retorna -1 caso a matricula não esteja no repositório*/
			int i = 0;
			int indFound = NOT_FOUND;
			boolean achou = false;
			
			while((i < indice) && !achou) 
				{
				if(matriculas[i].getNumber()==targetNumber)
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

		private int procuraIndice(String targetAl, String targetCrCd){
			/**-retorna o indice do Matricula procurado(aluno e codigo do curso)
			 * no repositório de Matriculas
			 * -retorna -1 caso a matricula não esteja no repositório*/
			int i = 0;
			int indFound = NOT_FOUND;
			boolean achou = false;
			
			while((i < indice) && !achou) 
				{
				if(matriculas[i].getAluno().getName().equals(targetAl) &&
						matriculas[i].getCurso().getCode().equals(targetCrCd))
					{
					indFound = i;
					achou = true;
					}
				i += 1;
				}
			if(achou == false)
				indFound = NOT_FOUND;
			
			return indFound;
			}
		
		
		public boolean existe(int targetNumber)
			{
			int find = this.procuraIndice(targetNumber);
			return (find == NOT_FOUND)? false: true;
			} 

		public boolean existe(Matricula targetMtrc)
			{//procura se o indice de uma matricula com dado aluno e curso já existe
			int find = this.procuraIndice(targetMtrc.getAluno().getName(),
					targetMtrc.getCurso().getCode());
			return (find == NOT_FOUND)? false: true;
			}
			
		public Matricula procurar(int targetNumber){
				int targetInd = procuraIndice(targetNumber);
				if(targetInd != NOT_FOUND)
					return matriculas[targetInd];
				else
					return ERROR;
			}

		public Matricula procurar(Matricula targetMtrc){
			//procura uma matricula pelo nome do aluno e do curso
			int targetInd = this.procuraIndice(targetMtrc.getAluno().getName(),
					targetMtrc.getCurso().getCode());
			if(targetInd != NOT_FOUND)
				return matriculas[targetInd];
			else
				return ERROR;
		}
		
		public void atualizar(Matricula newMtrc)
			{
				int targetInd = procuraIndice(newMtrc.getNumber());
				if(targetInd != NOT_FOUND)
					{
					matriculas[targetInd] = newMtrc;
					}
				else {
					TerminalUserInterface.reportarErro(
							"Tentou-se atualizar um Matricula não cadastrada!");
				}
			}

		 public void remover(int targetNumber)
			{
			 	int targetInd = procuraIndice(targetNumber);
			 	if(targetInd != NOT_FOUND)
			 	{
			 		matriculas[targetInd] = matriculas[indice-1] ;
			 		matriculas[indice-1] = null;
			 		indice--;
			 		TerminalUserInterface.displayMsg(
			 				"Matrícula removida com sucesso!");
			 	}
			else {
				TerminalUserInterface.reportarErro(
						"tentou-se remover Matricula não cadastrado!");
				}
			}
		 public void remover(Matricula targetMtrc)
			{
			 this.remover(targetMtrc.getNumber());
			}
}//fim da classe RepositorioMatriculaArray
