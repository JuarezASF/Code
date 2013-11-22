package unb.banco.dados.cliente;

import unb.banco.cliente.Cliente;

public interface RepositorioCliente {

	int getIndice();
	Cliente[] getClientes();
	Cliente getCliente(int n);
	
	void setIndice(int newI);
	void setClientes(Cliente[] newCl);
	
	void inserir(Cliente newCl);
	
	boolean existe(Cliente target);	
	Cliente procurar(Cliente targetC);
	
	void atualizar(Cliente newCl);
	void remover(Cliente targetC);
	
}
