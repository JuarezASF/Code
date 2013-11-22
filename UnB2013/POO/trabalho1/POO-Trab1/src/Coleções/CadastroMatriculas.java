package Coleções;

import Interface.TerminalUserInterface;
import Repositórios.RepositorioMatriculaArray;
import ClassesBásicas.*;
import Listas.ListaMatriculas;

public class CadastroMatriculas {
	private RepositorioMatriculaArray matriculas;
	
	public CadastroMatriculas(RepositorioMatriculaArray newMatriculas){
		matriculas = newMatriculas;
	}
	
	public void atualizar(Matricula newMtrc)
	{
		matriculas.atualizar(newMtrc);
	}
	
	public void cadastrar(Matricula newMtrc){
		if(matriculas.existe(newMtrc)){
			TerminalUserInterface.reportarErro("Matricula já cadastrado!");
		}
		else{
			matriculas.inserir(newMtrc);
			newMtrc.getCurso().incrementNStudents();
			newMtrc.getAluno().upNCursos();
		}
	}
	
	public void descadastrar(Matricula targetMtrc){
		if(this.matriculas.existe(targetMtrc));
			{
				targetMtrc.getCurso().decrementNStudents();
				targetMtrc.getAluno().downNCursos();
				this.matriculas.remover(targetMtrc);
			}
	}
	
	public void descadastrar(ListaMatriculas target){
		while(target.hasNext())
			descadastrar(target.next());
	}
	
	
	public Matricula procurar(int targetNumber){
		Matricula targetFound = matriculas.procurar(targetNumber);
		return targetFound;
	}
	
	public Matricula procurar(Matricula targetMtrc){
		Matricula targetFound = matriculas.procurar(targetMtrc);
		return targetFound;
	}
	
	
	public ListaMatriculas ListaMatriculas(){
		ListaMatriculas listaAl = new ListaMatriculas();
		int n = 0;
		
		for(n = 0; n < this.matriculas.getIndice(); n++)
			listaAl.insert(this.matriculas.getMatricula(n));
		
		return listaAl;
	}

	public ListaMatriculas ListaMatriculasAluno(Aluno targetAl){
		//retorna lista das matriculas com um determinado aluno
		ListaMatriculas listaAl = new ListaMatriculas();
		int n = 0;

		String targetNameAl = targetAl.getName();
		for(n = 0; n < this.matriculas.getIndice(); n++)
			{
			String currentName = matriculas.getMatricula(n).getAluno().getName();
			if(targetNameAl.equals(currentName))
					listaAl.insert(this.matriculas.getMatricula(n));
			}
		return listaAl;
	}

	public ListaMatriculas ListaMatriculasCurso(Curso targetCr){
		//retorna lista das matriculas com um determinado curso
		ListaMatriculas listaAl = new ListaMatriculas();
		int n = 0;
		
		String targetCrCode = targetCr.getCode();
		for(n = 0; n < this.matriculas.getIndice(); n++)
			{
			String currentCode = matriculas.getMatricula(n).getCurso().getCode();
			if(targetCrCode.equals(currentCode))
					listaAl.insert(this.matriculas.getMatricula(n));
			}
		return listaAl;
	}

}//fim da classe CadastroMatriculas
