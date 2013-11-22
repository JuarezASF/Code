package Listas;
import Repositórios.RepositorioMatriculaArray;
import ClassesBásicas.Matricula;

public class ListaMatriculas {

	private RepositorioMatriculaArray matriculas;
	private int indice;
	//indice guarda o último indice da lista acessado
	
	public ListaMatriculas(){
		matriculas = new RepositorioMatriculaArray();
		indice = 0;
	}
	
	public boolean hasNext(){
		return indice <= (matriculas.getIndice() - 1);
	}
	
	public Matricula next(){
		Matricula nextCl = matriculas.getMatriculas()[indice];
		indice = indice + 1;
		return nextCl;
	}
	
	public void insert(Matricula newAl){
		this.matriculas.inserir(newAl);
	}

}//fim da classe ListaMatriculas
