package Repositórios;

import ClassesBásicas.Curso;
import Interface.TerminalUserInterface;

public class RepositorioCursoArray {
	//--------------------------------------------------
	//----------------ATRIBUTOS-------------------------
	//--------------------------------------------------
		private Curso[] cursos;
		private int indice;
		private static final int tamCache = 100;
		private static final int NOT_FOUND = -1;
		private static final Curso ERROR = null;
	//--------------------------------------------------
	//----------------CONSTRUTORES----------------------
	//--------------------------------------------------

		public RepositorioCursoArray(){
			indice = 0;
			cursos = new Curso[tamCache];
		}
	//--------------------------------------------------
	//----------------GETTERS---------------------------
	//--------------------------------------------------
		public int getIndice(){
			return indice;
			}

		public Curso[] getCursos(){
			return cursos;
		}

		public Curso getCurso(int n){
			if(n>=0 && n < indice)
				return this.cursos[n];
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

		public void setCursos(Curso[] newCrs)
			{
			cursos = newCrs;
			}
	//--------------------------------------------------
	//--------------OPERAÇÕES COMUNS--------------------
	//--------------------------------------------------
		public void inserir(Curso newCr){
			cursos[indice] = newCr;
			indice = indice + 1;
		}

		private int procuraIndice(String targetCode){
			/**-retorna o indice do curso procurado(pelo codigo)
			 * no repositório de cursos
			 * -retorna -1 caso o aluno não esteja no repositório*/
			int i = 0;
			int indFound = NOT_FOUND;
			boolean achou = false;
			
			while((i < indice) && !achou) 
				{
				if((cursos[i].getCode()).equals(targetCode))
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

		public boolean existe(String targetCode)
			{
			int find = this.procuraIndice(targetCode);
			return (find == NOT_FOUND)? false: true;
			} 

		public boolean existe(Curso targetCr)
			{
			boolean find = existe(targetCr.getCode());
			return find;
			}
			
		public Curso procurar(String targetCode){
				int targetInd = procuraIndice(targetCode);
				if(targetInd != NOT_FOUND)
					return cursos[targetInd];
				else
					return ERROR;
			}

		public void atualizar(Curso newCr)
			{
				int targetInd = procuraIndice(newCr.getCode());
				if(targetInd != NOT_FOUND)
					{
					cursos[targetInd] = newCr;
					}
				else {
					TerminalUserInterface.reportarErro(
							"Tentou-se atualizar um curso não cadastrado!");
				}
			}

		 public void remover(String targetCode)
			{
			 	int targetInd = procuraIndice(targetCode);
			 	if(targetInd != NOT_FOUND)
			 	{
			 		cursos[targetInd] = cursos[indice-1] ;
			 		cursos[indice-1] = null;
			 		indice--;
			 	}
			else {
				TerminalUserInterface.reportarErro(
						"tentou-se remover Curso não cadastrado!");
				}
			}
		 
		 public Curso maisVazio(){
			 int currentMin = 10000;
			 int currentMinN = 0;
		 
			 for(int n = 0; n < this.getIndice(); n++)
			 	{
				 if(this.getCurso(n).getNStudents() <= currentMin)
					currentMinN = n; 
			 	}
			 return this.getCurso(currentMinN);
		 }

}
