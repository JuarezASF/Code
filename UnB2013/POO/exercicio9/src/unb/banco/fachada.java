package unb.banco;

import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteNaoCadastradoException;
import unb.banco.cliente.cadastroClientes;
import unb.banco.cliente.listaClientes;
import unb.banco.conta.ClasseContaInvalidaException;
import unb.banco.conta.Conta;
import unb.banco.conta.InvalidValueException;
import unb.banco.conta.SaldoInsuficienteException;
import unb.banco.conta.cadastroContas;
import unb.banco.conta.listaContas;
import unb.banco.dados.cliente.*;
import unb.banco.dados.conta.ContaNaoCadastradaException;
import unb.banco.dados.conta.RepositorioContasArquivo;


public class fachada {
/**
 * fachada deve interagir somente com cadastro de contas e de clientes
 * */
	private static fachada instanciaFachada;
	private cadastroContas contas;
	private cadastroClientes clientes;
//-------------------------------------------------
//-----------Construtores--------------------------
//-------------------------------------------------
	public static fachada obterInstancia()
			throws Exception
	{
		if (instanciaFachada == null)
			instanciaFachada = new fachada();
		return instanciaFachada;
	}
	
	private fachada()
	throws Exception
	{
		initCadastro();
	}
	
	private void initCadastro()
		throws Exception	{
		RepositorioClienteArquivo newRepoCl = new RepositorioClienteArquivo();
		this.clientes = new cadastroClientes(newRepoCl);
		
		try
		{
			RepositorioContasArquivo newRepoC = new RepositorioContasArquivo();
			this.contas = new cadastroContas(newRepoC);
		}
		catch(Exception e){
			
			throw new Exception("RepositorioContaArquivo não pode ser aberto\n"+
					e.getMessage());
		}
		
	}

//--------------------------------------------------
//-----------Manipulação de clientes----------------
//-------------------------------------------------
	public void atualizar(Cliente targetCl)
			throws Exception
		{
		this.clientes.atualizar(targetCl);
	}
	
	public Cliente procurar(Cliente target)
			throws Exception
		{
		return this.clientes.procurar(target);
	}
	
	public void cadastrar(Cliente newCl)
			throws Exception
		{
		this.clientes.cadastrar(newCl);
	}

	public void descadastrar(Cliente target)
			throws Exception
		{
		Cliente targetCl = this.clientes.procurar(target);
		listaContas targetContas = this.contas.listaContasCliente(targetCl);
		
		while(targetContas.hasNext())
			{
			try{
				this.contas.descadastrar(targetContas.next());}
			catch(ContaNaoCadastradaException e)
				{}
			}
		this.clientes.descadastrar(target);
	}

	public listaClientes listaClientes()
			throws Exception
	{
		return this.clientes.listaClientes();
	}
//--------------------------------------------------
//-----------Manipulação de contas----------------
//-------------------------------------------------
	public void atualizar(Conta targetC)
		throws ContaNaoCadastradaException,
			Exception
		{
		this.contas.atualizar(targetC);
		}
	
	public Conta procurar(Conta target)
		throws ContaNaoCadastradaException,
		Exception
		{
		return this.contas.procurar(target);
		}
	
	public void cadastrar(Conta targetC)
			throws Exception
		{
		//somente cadastramos contas de clientes existentes
		if(this.clientes.existe(targetC.getDono()))
			{
				this.contas.cadastrar(targetC);
			}
		else
			throw new ClienteNaoCadastradoException();
		}

	public void descadastrar(Conta target)
		throws ContaNaoCadastradaException
		, Exception
		{
		this.contas.descadastrar(target);
		}
	
	public void creditar(Conta target, double value)
			throws InvalidValueException,
					ContaNaoCadastradaException,
					Exception
			
	{
		this.contas.creditar(target, value);
	}
	
	public void debitar(Conta target, double value)
		throws SaldoInsuficienteException,
				ContaNaoCadastradaException,
				Exception
	{
		this.contas.debitar(target, value);
	}
	
	public void transferir(Conta origem, Conta destino, double value)
			throws SaldoInsuficienteException,
					InvalidValueException,
					ContaNaoCadastradaException,
					Exception
	{
		this.contas.transferir(origem, destino, value);
	}
	
	public listaContas listaContasCliente(Cliente target)
		throws Exception
		{
		return this.contas.listaContasCliente(target);
	}

	public listaContas listaContas() throws Exception{
		return this.contas.listaContas();
	}
	
	public void renderBonus(Conta target)
			throws 
					ContaNaoCadastradaException,
					ClasseContaInvalidaException,
					Exception
	{
		this.contas.renderBonus(target);
	}

	public void renderJuros(Conta target)
			throws 
			ContaNaoCadastradaException,
			ClasseContaInvalidaException,
			Exception
		{

			this.contas.renderJuros(target);
		}


}//fim da classe fachada
