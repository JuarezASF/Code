
public class RepositorioContasArray
{
	private Conta[] contas;
	private int indice;
	private final static int tamCache = 100;

	public RepositorioContasArray()
		{
		indice = 0;
		contas = new Conta[tamCache];
		}

	public int getIndice()
		{
			return indice;
		}

	public Conta[] getContas()
		{
			return contas;
		}	

	public Conta getConta(int n)
		{
			if((0 <= n) && (n < indice))
				return this.contas[n];
			else
				return null;
		}	

	public void setIndice(int newI)
		{
			indice = newI;
		}

	public void setContas(Conta[] newC)
		{
			contas = newC;
		}

	public void inserir(Conta c)
		{
		contas[indice] = c;
		indice += 1;
		} 

	private int procuraIndice(String targetNumber)
		{
		int i = 0;
		int ind = -1;
		boolean achou = false;

		while((i < indice) && !achou)  
			{
			if((contas[i].getNumber()).equals(targetNumber))
				{
				ind = i;
				achou = true;
				}
			i +=1;
			}
		return ind;
		} 

	public boolean existe(String targetNumber)
		{
		int i = this.procuraIndice(targetNumber);
		return (i != -1)? true : false;
		}

	public void atualizar(Conta newC)
		{
		int i = procuraIndice(newC.getNumber());
		if( i != -1)
			{
			contas[i] = newC;
			}
		else
			System.out.println("Conta a ser atualizada não encontrda!");
		} 

	public Conta procurar(String targetNumber)
		{
		Conta c = null;
		if(existe(targetNumber))
			{
				int i = this.procuraIndice(targetNumber);
				c = contas[i];
			}
		else
				System.out.println("Conta procurada não existente!");

		return c;
		}

	public void remover(String targetNumber)
		{
		if(existe(targetNumber))
			{
			int i = this.procuraIndice(targetNumber);
			contas[i] = contas[indice - 1];
			contas[indice - 1] = null;
			indice --;
			}
		else
			System.out.println("Conta a ser removida não pode ser encontrada!");
		}

	public Conta procuraCliente(Cliente cliente, int n)
		{
			//retorn a n-ésima conta de cliente encontrada
			//retorna null caso não haja mais conta de cliente
			Conta answer = null;
			boolean achou = false;
			int i = 0;
			int sucess = 0;

			while((i < indice) && (sucess < n))
				{
					if(this.contas[i].getDono().equals(cliente.getCpf()))
						{
							answer = this.contas[i];
							sucess++;
						}
					i++;
				}
			if(sucess != n)
				answer = null;

			return answer;
		}


}