package unb.banco.conta;
import unb.banco.cliente.Cliente;
import unb.banco.dados.conta.ContaJaExistenteException;
import unb.banco.dados.conta.ContaNaoCadastradaException;
import unb.banco.dados.conta.RepositorioConta;


public class cadastroContas {
//cadastro de conta deve interagir com o repositório de contas
	private RepositorioConta contas;
	
	public cadastroContas(RepositorioConta repC) {
		this.contas = repC;
	}
	
	public void atualizar(Conta newC)
		throws Exception
		{
		contas.atualizar(newC);
		}
	
	public void cadastrar(Conta newC)
		throws Exception
		{
		contas.inserir(newC);	
		}
	
	public void creditar(Conta target, double value)
		throws InvalidValueException,
				Exception
	{
		Conta c = contas.procurar(target);
		c.creditar(value);
		
		this.atualizar(c);

	}

	public void debitar(Conta target, double value)
	throws SaldoInsuficienteException,
			Exception
	
	{
		Conta c = contas.procurar(target);
		c.debitar(value);
		this.atualizar(c);
	}
	
	public void descadastrar(Conta target)
		throws Exception
		{
		
		this.contas.remover(target);
		}
	
	public Conta procurar(Conta target)
		throws Exception
		{
		return contas.procurar(target);
		}
	
	public void transferir(Conta origem, Conta destino,
							double value)
		throws Exception,
				InvalidValueException,
				ContaNaoCadastradaException
	{	
		Conta O = contas.procurar(origem);
		Conta D = contas.procurar(destino);
		
		O.transferir(D, value);
		this.atualizar(O);
		this.atualizar(D);
			return;
	}
	
	public listaContas listaContasCliente(Cliente target)
		throws Exception
	{
		
		listaContas listaC = new listaContas();
		
		if(target != null)
			{
			for(int i = 0; i < this.contas.getIndice(); i++)
				{
				Conta current = this.contas.getConta(i);
				if(current.getDono() == target)
					try{listaC.insert(current);
						}catch (ContaJaExistenteException e)
						{}
				}
			}
		return listaC;
	}
	
	public listaContas listaContas()
			throws Exception
		{
		listaContas listaC = new listaContas();
		int i = 0;
		
		for(i = 0; i < this.contas.getIndice(); i++)
			try{listaC.insert(this.contas.getConta(i));}
		catch(ContaJaExistenteException e){}
		
		return listaC;
	}
	
	public void renderBonus(Conta target)
			throws 	ClasseContaInvalidaException,
					ContaNaoCadastradaException,
					Exception
	{
		Conta find = this.contas.procurar(target);
			if(find instanceof ContaBonificada){
				((ContaBonificada)find).renderBonus();
				this.atualizar(find);
			}

			else
				throw new ClasseContaInvalidaException();

	}
	
	public void renderJuros(Conta target)
			throws 	ClasseContaInvalidaException,
			ContaNaoCadastradaException,
			 Exception

		{
		Conta find = this.contas.procurar(target);
			if(find instanceof Poupanca){
				((Poupanca)find).renderJuros();
				this.atualizar(find);
			}
			else
				throw new ClasseContaInvalidaException();
		}

}//fim da classe
