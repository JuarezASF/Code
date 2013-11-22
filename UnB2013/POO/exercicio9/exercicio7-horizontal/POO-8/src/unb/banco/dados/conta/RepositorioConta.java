package unb.banco.dados.conta;

import unb.banco.cliente.Cliente;
import unb.banco.conta.Conta;

public interface RepositorioConta {

	int getIndice();
	Conta[] getContas();
	Conta getConta(int n);
	
	void setIndice(int newI);
	void setContas(Conta[] newC);

	void inserir(Conta c);
	boolean existe(Conta target);
	
	void atualizar(Conta newC);
	Conta procurar(Conta target);
	void remover(Conta target);
	Conta procura(Cliente cliente, int n);
	Conta procura(String targetCPF, int n);

}
