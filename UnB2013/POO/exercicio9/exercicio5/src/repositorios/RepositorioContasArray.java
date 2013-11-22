package repositorios;
import userInterface.UserInterface;
import classasBasicas.Cliente;
import classasBasicas.Conta;


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
		{
		if(!this.existe(c))
			{
			contas[indice] = c;
			indice += 1;
			UserInterface.report("Conta cadastrada com sucesso!");
			}
		else
			UserInterface.report("Conta já cadastrada!");
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
		{
		int i = procuraIndice(newC.getNumber());
		if( i != -1)
			{
			contas[i] = newC;
			UserInterface.report("Conta atualizada com sucesso!");
			}
		else
			UserInterface.report("Conta a ser atualizada não encontrda!");
		} 

	public Conta procurar(Conta target)
		{
		Conta c = null;
		if(existe(target))
			{
				int i = this.procuraIndice(target.getNumber());
				c = contas[i];
			}
		else
				UserInterface.report("Conta procurada não existente!");

		return c;
		}

	public void remover(Conta target)
		{
		if(existe(target))
			{
			int i = this.procuraIndice(target.getNumber());
			contas[i] = contas[indice - 1];
			contas[indice - 1] = null;
			indice --;
			UserInterface.report("Conta removida com sucesso!");
			}
		else
			UserInterface.report("Conta a ser removida não pode ser encontrada!");
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