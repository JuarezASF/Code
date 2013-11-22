package unb.banco.dados.cliente;

import unb.banco.cliente.Cliente;


public interface RepositorioCliente {

	int getSize();
	
	Cliente[] getClientes()throws Exception;
	
	Cliente getCliente(int i)throws Exception;
	
	void setClientes(Cliente[] newCl) throws Exception;
	
	void inserir(Cliente newCl) throws Exception;
	
	boolean existe(Cliente target) throws Exception;	

	Cliente procurar(Cliente targetC) throws Exception;
	
	void atualizar(Cliente newCl)throws Exception;
	
	void remover(Cliente targetC)throws Exception;
	
}
