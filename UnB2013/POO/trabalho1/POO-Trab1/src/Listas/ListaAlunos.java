package Listas;
import Repositórios.RepositorioAlunoArray;
import ClassesBásicas.Aluno;

public class ListaAlunos {

	private RepositorioAlunoArray alunos;
	private int indice;
	//indice guarda o último indice da lista acessado
	
	public ListaAlunos(){
		alunos = new RepositorioAlunoArray();
		indice = 0;
	}
	
	public boolean hasNext(){
		return indice <= (alunos.getIndice() - 1);
		//alunos.getIndice guarda o lugar ondo o próximo será
		//colocado
	}
	
	public Aluno next(){
		Aluno nextCl = alunos.getAlunos()[indice];
		this.indice = this.indice + 1;
		return nextCl;
	}
	
	public void insert(Aluno newAl){
		this.alunos.inserir(newAl);
	}

}//fim da classe ListaAlunos
