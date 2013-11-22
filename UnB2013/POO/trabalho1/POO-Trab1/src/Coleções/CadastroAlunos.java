package Coleções;

import Interface.TerminalUserInterface;
import Repositórios.RepositorioAlunoArray;
import ClassesBásicas.Aluno;
import Listas.ListaAlunos;

public class CadastroAlunos {
	private RepositorioAlunoArray alunos;
	
	public CadastroAlunos(RepositorioAlunoArray newAlunos){
		alunos = newAlunos;
	}
	
	public void atualizar(Aluno newAl)
	{
		alunos.atualizar(newAl);
	}
	
	public void cadastrar(Aluno newAl){
		if(alunos.existe(newAl.getName())){
			TerminalUserInterface.reportarErro("Aluno já cadastrado!");
		}
		else
		{
			alunos.inserir(newAl);
			TerminalUserInterface.displayMsg("Aluno cadastrado com sucesso!");
		}
	}
	public Aluno procurar(String targetName){
		Aluno targetFound = alunos.procurar(targetName);
		return targetFound;
	}
	
	public ListaAlunos ListaAlunos(){
		ListaAlunos listaAl = new ListaAlunos();
		int n = 0;
		
		for(n = 0; n < this.alunos.getIndice(); n++)
			listaAl.insert(this.alunos.getAluno(n));
		
		return listaAl;
	}
	
	public boolean existe(String targetName){
		return this.alunos.existe(targetName);
	}
	
	public boolean existe(Aluno targetAl){
		if(targetAl != null)
			return this.existe(targetAl.getName());
		else
			return false;
	}
	
	public void descadastrar(Aluno targetAl){
		this.alunos.remover(targetAl.getName());
	}


}//fim da classe CadastroAlunos
