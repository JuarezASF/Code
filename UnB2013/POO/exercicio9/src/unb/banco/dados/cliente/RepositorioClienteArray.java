package unb.banco.dados.cliente;
import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteJaCadastrado;
import unb.banco.cliente.ClienteNaoCadastradoException;

public class RepositorioClienteArray implements RepositorioCliente{
//--------------------------------------------------
//----------------ATRIBUTOS-------------------------
//--------------------------------------------------
	private Cliente[] clientes;
	private int indice;
	private static final int tamCache = 100;

//--------------------------------------------------
//----------------CONSTRUTORES----------------------
//--------------------------------------------------
	public RepositorioClienteArray()	
		{
		indice = 0;
		clientes = new Cliente[tamCache];
		}	 

//--------------------------------------------------
//----------------ACESSO----------------------------
//--------------------------------------------------
	public int getIndice()
		{
		return indice;
		}

	public int getSize()
	{
	return indice;
	}


	public Cliente[] getClientes()
		{
		return clientes;
		}

	public Cliente getCliente(int n)
		{
			if((0 <= n) && (n < indice))
				return this.clientes[n];
			else
				return null;
		}	
//--------------------------------------------------
//----------------SETANDO---------------------------
//--------------------------------------------------
	public void setIndice(int newI)
		{
		indice = newI;
		}

	public void setClientes(Cliente[] newCl)
		{
		clientes = newCl;
		}
//--------------------------------------------------
//--------------OPERAÇÕES COMUNS--------------------
//--------------------------------------------------
	public void inserir(Cliente newCl)
		throws ClienteJaCadastrado
		{
		if(!this.existe(newCl))
			{
			clientes[indice] = newCl;
			indice++;
			}
		else
			throw new ClienteJaCadastrado();
		}

	private int procuraIndice(String targetCpf)
		{
		int i = 0;
		int ind = -1;
		boolean achou = false;

		while((i < indice) && !achou) 
			{
			if((clientes[i].getCpf()).equals(targetCpf))
				{
				ind = i;
				achou = true;
				}
			i +=1;
			}
		return ind;
		}

	public boolean existe(Cliente target)
		{
		if(target != null)	
			{
			int i = this.procuraIndice(target.getCpf());
			return (i != -1)? true : false;
			}
		else
			return false;
		}
		
	public Cliente procurar(Cliente targetC)
		throws ClienteNaoCadastradoException
		{
		Cliente cl = null;
		if(existe(targetC))
			{
				int i = this.procuraIndice(targetC.getCpf());
				cl = clientes[i];
				return cl;
			}
		else
			throw new ClienteNaoCadastradoException();


		}

	public void atualizar(Cliente newCl) 
			throws ClienteNaoCadastradoException
		{
		int i = procuraIndice(newCl.getCpf());
		if( i != -1)
			{
			clientes[i] = newCl;
			}
		else
			throw new ClienteNaoCadastradoException();
		}

	 public void remover(Cliente targetC)
			 throws ClienteNaoCadastradoException
		 {
		if(existe(targetC))
			{
			int i = this.procuraIndice(targetC.getCpf());
			clientes[i] = clientes[indice - 1];
			clientes[indice - 1] = null;
			indice --;
			}
		else
			throw new ClienteNaoCadastradoException();
		}

}