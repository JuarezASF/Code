package Listas;
import Repositórios.RepositorioCursoArray;
import ClassesBásicas.Curso;

public class ListaCursos {

	private RepositorioCursoArray cursos;
	private int indice;
	//indice guarda o último indice da lista acessado
	
	public ListaCursos(){
		cursos = new RepositorioCursoArray();
		indice = 0;
	}
	
	public boolean hasNext(){
		return indice <= (cursos.getIndice() - 1);
	}
	
	public Curso next(){
		Curso nextCl = cursos.getCursos()[indice];
		this.indice = this.indice + 1;
		return nextCl;
	}
	
	public void insert(Curso newAl){
		this.cursos.inserir(newAl);
	}

}//fim da classe ListaCursos

