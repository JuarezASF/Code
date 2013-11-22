package unb.banco.dados.conta;

import unb.banco.cliente.Cliente;
import unb.banco.conta.Conta;

public interface RepositorioConta {

	int getIndice();
	Conta[] getContas();
	Conta getConta(int n);
	
	void setIndice(int newI);
	void setContas(Conta[] newC);

	void inserir(Conta c) 
			throws ContaJaExistenteException;
	boolean existe(Conta target);
	
	void atualizar(Conta newC) 
			throws ContaNaoCadastradaException;
	Conta procurar(Conta target)
			throws ContaNaoCadastradaException;
	void remover(Conta target) 
			throws ContaNaoCadastradaException;
	Conta procura(Cliente cliente, int n) 
			throws ContaNaoCadastradaException;
	Conta procura(String targetCPF, int n)
			throws ContaNaoCadastradaException;

}
