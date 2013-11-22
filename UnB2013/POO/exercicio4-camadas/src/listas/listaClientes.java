package listas;
import classasBasicas.Cliente;
import repositorios.RepositorioClienteArray;


public class listaClientes {
	private RepositorioClienteArray clientes;
	private int indice;
	//indice guarda o último indice da lista acessado
	
	public listaClientes(){
		clientes = new RepositorioClienteArray();
		indice = 0;
	}
	
	public boolean hasNext(){
		return indice < clientes.getIndice();
	}
	
	public Cliente next(){
		Cliente nextCl = clientes.getClientes()[indice];
		indice++;
		return nextCl;
	}
	
	public void insert(Cliente newCl){
		this.clientes.inserir(newCl);
	}
}
