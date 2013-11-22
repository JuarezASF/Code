package unb.banco.dados.conta;

import unb.banco.cliente.Cliente;
import unb.banco.conta.Conta;

public interface RepositorioConta {

	int getIndice()
			throws Exception;
	Conta[] getContas()
			throws Exception;
	Conta getConta(int n)
			throws Exception;
	
	void setContas(Conta[] newC)
			throws Exception;

	void inserir(Conta c) 
			throws Exception;
	boolean existe(Conta target)
			throws Exception;
	
	void atualizar(Conta newC) 
			 throws Exception;
	
	Conta procurar(Conta target)
			throws Exception;
	void remover(Conta target) 
			throws Exception;
	Conta procura(Cliente cliente, int n) 
			throws Exception;
	Conta procura(String targetCPF, int n)
			throws Exception;

}
