public class RepositorioClienteArray{
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
		{
		clientes[indice] = newCl;
		indice++;
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

	public boolean existe(String targetCpf)
		{
		int i = this.procuraIndice(targetCpf);
		return (i != -1)? true : false;
		} 

	public Cliente procurar(String targetCpf)
		{
		Cliente cl = null;
		if(existe(targetCpf))
			{
				int i = this.procuraIndice(targetCpf);
				cl = clientes[i];
			}
		else
				System.out.println("Cliente procurado não existente!");

		return cl;
		}

	public void atualizar(Cliente newCl)
		{
		int i = procuraIndice(newCl.getCpf());
		if( i != -1)
			{
			clientes[i] = newCl;
			}
		else
			System.out.println("Cliente a ser atualizado não encontrdo!");
		}

	 public void remover(String targetCpf)
		{
		if(existe(targetCpf))
			{
			int i = this.procuraIndice(targetCpf);
			clientes[i] = clientes[indice - 1];
			clientes[indice - 1] = null;
			indice --;
			}
		else
			System.out.println("Cliente a ser removido não pode ser encontrado!");
		}

}