package listas;
import classasBasicas.Conta;
import repositorios.RepositorioContasArray;


public class listaContas {
	// TODO Auto-generated constructor stub
	private RepositorioContasArray contas;
	private int indice;
	//indice guarda o último indice da lista acessado
	
	public listaContas(){
		contas = new RepositorioContasArray();
		indice = 0;
	}
	
	public boolean hasNext(){
		return indice < contas.getIndice();
	}
	
	public Conta next(){
		Conta nextC = contas.getContas()[indice];
		indice++;
		return nextC;
	}
	
	public void insert(Conta newC){
		this.contas.inserir(newC);
	}
}
