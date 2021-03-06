package unb.banco.dados.conta;
import unb.banco.cliente.Cliente;
import unb.banco.conta.Conta;


public class RepositorioContasArray implements RepositorioConta
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
			//retorna último indice ocupado
		   //se tivermos N contas teremos de 0 -> N-1 
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
		throws ContaJaExistenteException
		{
		if(!this.existe(c))
			{
			contas[indice] = c;
			indice += 1;
			}
		else
			throw new ContaJaExistenteException();
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

	public boolean existe(Conta target)
		{
		if(target != null)
			{
			int i = this.procuraIndice(target.getNumber());
			return (i != -1)? true : false;
			}
		else
			return false;
		}
	
	public void atualizar(Conta newC) 
			throws ContaNaoCadastradaException
		{
		int i = procuraIndice(newC.getNumber());
		if( i != -1)
			{
			contas[i] = newC;
			}
		else
			throw new ContaNaoCadastradaException();
		} 

	public Conta procurar(Conta target)
		throws ContaNaoCadastradaException
		{
		Conta c = null;
		if(existe(target))
			{
				int i = this.procuraIndice(target.getNumber());
				c = contas[i];
				return c;
			}
		else	
			throw new ContaNaoCadastradaException();

		}

	public void remover(Conta target)
		throws ContaNaoCadastradaException
		{
		if(existe(target))
			{
			int i = this.procuraIndice(target.getNumber());
			contas[i] = contas[indice - 1];
			contas[indice - 1] = null;
			indice --;
			}
		else
			throw new ContaNaoCadastradaException();
		}

	public Conta procura(Cliente cliente, int n)
			{
			//retorn a n-ésima conta de cliente encontrada
			//retorna null caso não haja mais conta de cliente
			Conta answer = null;
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
	
	public Conta procura(String targetCPF, int n)
	{
		//retorn a n-ésima conta de cliente encontrada
		//retorna null caso não haja mais conta de cliente
		Conta answer = null;
		int i = 0;
		int sucess = 0;

		while((i < indice) && (sucess < n))
			{
				if(this.contas[i].getDono().equals(targetCPF))
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