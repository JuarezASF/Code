package unb.banco.dados.cliente;

import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteJaCadastrado;
import unb.banco.cliente.ClienteNaoCadastradoException;

public interface RepositorioCliente {

	int getIndice();
	Cliente[] getClientes();
	Cliente getCliente(int n);
	
	void setIndice(int newI);
	void setClientes(Cliente[] newCl);
	
	void inserir(Cliente newCl) throws ClienteJaCadastrado;
	
	boolean existe(Cliente target);	
	Cliente procurar(Cliente targetC) throws ClienteNaoCadastradoException;
	
	void atualizar(Cliente newCl)throws ClienteNaoCadastradoException;
	void remover(Cliente targetC)throws ClienteNaoCadastradoException;
	
}
