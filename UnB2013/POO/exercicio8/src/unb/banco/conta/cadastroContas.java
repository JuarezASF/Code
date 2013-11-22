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
		throws ContaNaoCadastradaException
		{
		contas.atualizar(newC);
		}
	
	public void cadastrar(Conta newC)
		throws ContaJaExistenteException
		{
		contas.inserir(newC);	
		}
	
	public void creditar(Conta target, double value)
		throws InvalidValueException,
				ContaNaoCadastradaException
	{
		Conta c = contas.procurar(target);
		c.creditar(value);

	}

	public void debitar(Conta target, double value)
	throws SaldoInsuficienteException,
			ContaNaoCadastradaException
	
	{
		Conta c = contas.procurar(target);
		c.debitar(value);
	}
	
	public void descadastrar(Conta target)
		throws ContaNaoCadastradaException
		{
		
		this.contas.remover(target);
		}
	
	public Conta procurar(Conta target)
		throws ContaNaoCadastradaException
		{
		return contas.procurar(target);
		}
	
	public void transferir(Conta origem, Conta destino,
							double value)
		throws SaldoInsuficienteException,
				InvalidValueException,
				ContaNaoCadastradaException
	{	
		Conta O = contas.procurar(origem);
		Conta D = contas.procurar(destino);
		
		O.transferir(D, value);		
			return;
	}
	
	public listaContas listaContasCliente(Cliente target){
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
	
	public listaContas listaContas(){
		listaContas listaC = new listaContas();
		int i = 0;
		
		for(i = 0; i < this.contas.getIndice(); i++)
			try{listaC.insert(this.contas.getConta(i));}
		catch(ContaJaExistenteException e){}
		
		return listaC;
	}
	
	public void renderBonus(Conta target)
			throws 	ClasseContaInvalidaException,
					ContaNaoCadastradaException
	{
		Conta find = this.contas.procurar(target);
			if(find instanceof ContaBonificada)
				((ContaBonificada)find).renderBonus();
			else
				throw new ClasseContaInvalidaException();

	}
	
	public void renderJuros(Conta target)
			throws 	ClasseContaInvalidaException,
			ContaNaoCadastradaException

		{
		Conta find = this.contas.procurar(target);
			if(find instanceof Poupanca)
				((Poupanca)find).renderJuros();
			else
				throw new ClasseContaInvalidaException();
		}

}//fim da classe
