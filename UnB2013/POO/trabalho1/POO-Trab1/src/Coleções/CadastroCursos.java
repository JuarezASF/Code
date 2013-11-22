package Coleções;

import Interface.TerminalUserInterface;
import Repositórios.RepositorioCursoArray;
import ClassesBásicas.Curso;
import Listas.ListaCursos;

public class CadastroCursos {
	private RepositorioCursoArray cursos;
	
	public CadastroCursos(RepositorioCursoArray newCursos){
		cursos = newCursos;
	}
	
	public void atualizar(Curso newCrs)
	{
		cursos.atualizar(newCrs);
	}
	
	public void cadastrar(Curso newCrs){
		if(cursos.existe(newCrs)){
			TerminalUserInterface.reportarErro("Curso já cadastrado!");
		}
		else
		{
			cursos.inserir(newCrs);
			TerminalUserInterface.displayMsg("Curso cadastrado com sucesso!");
		}
	}
	public Curso procurar(String targetCode){
		Curso targetFound = cursos.procurar(targetCode);
		return targetFound;
	}
	
	public void descadastrar(Curso targetCr){
		this.cursos.remover(targetCr.getCode());
	}
	
	public ListaCursos ListaCursos(){
		ListaCursos listaAl = new ListaCursos();
		int n = 0;
		
		for(n = 0; n < this.cursos.getIndice(); n++)
			listaAl.insert(this.cursos.getCurso(n));
		
		return listaAl;
	}
	
	public boolean existe(Curso targetCr){
		if(targetCr != null)
			return this.cursos.existe(targetCr);
		else
			return false;
	}
	
	public Curso maisVazio(){
		return this.cursos.maisVazio();
	}


}//fim da classe CadastroCursos
