package unb.banco;

import unb.banco.cliente.Cliente;
import unb.banco.cliente.ClienteJaCadastrado;
import unb.banco.cliente.ClienteNaoCadastradoException;
import unb.banco.cliente.cadastroClientes;
import unb.banco.cliente.listaClientes;
import unb.banco.conta.ClasseContaInvalidaException;
import unb.banco.conta.Conta;
import unb.banco.conta.InvalidValueException;
import unb.banco.conta.SaldoInsuficienteException;
import unb.banco.conta.cadastroContas;
import unb.banco.conta.listaContas;
import unb.banco.dados.cliente.RepositorioClienteArray;
import unb.banco.dados.conta.ContaJaExistenteException;
import unb.banco.dados.conta.ContaNaoCadastradaException;
import unb.banco.dados.conta.RepositorioContasArray;


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
	public static fachada obterInstancia(){
		if (instanciaFachada == null)
			instanciaFachada = new fachada();
		return instanciaFachada;
	}
	
	private fachada(){
		initCadastro();
	}
	
	private void initCadastro(){
		RepositorioClienteArray newRepoCl = new RepositorioClienteArray();
		this.clientes = new cadastroClientes(newRepoCl);
		
		RepositorioContasArray newRepoC = new RepositorioContasArray();
		this.contas = new cadastroContas(newRepoC);
	}

//--------------------------------------------------
//-----------Manipulação de clientes----------------
//-------------------------------------------------
	public void atualizar(Cliente targetCl)
			throws ClienteNaoCadastradoException
		{
		this.clientes.atualizar(targetCl);
	}
	
	public Cliente procurar(Cliente target)
			throws ClienteNaoCadastradoException
		{
		return this.clientes.procurar(target);
	}
	
	public void cadastrar(Cliente newCl)
			throws ClienteJaCadastrado
		{
		this.clientes.cadastrar(newCl);
	}

	public void descadastrar(Cliente target)
			throws ClienteNaoCadastradoException
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

	public listaClientes listaClientes(){
		return this.clientes.listaClientes();
	}
//--------------------------------------------------
//-----------Manipulação de contas----------------
//-------------------------------------------------
	public void atualizar(Conta targetC)
		throws ContaNaoCadastradaException
		{
		this.contas.atualizar(targetC);
		}
	
	public Conta procurar(Conta target)
		throws ContaNaoCadastradaException
		{
		return this.contas.procurar(target);
		}
	
	public void cadastrar(Conta targetC)
			throws	ContaJaExistenteException,
					ClienteNaoCadastradoException
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
		{
		this.contas.descadastrar(target);
		}
	
	public void creditar(Conta target, double value)
			throws InvalidValueException,
					ContaNaoCadastradaException
			
	{
		this.contas.creditar(target, value);
	}
	
	public void debitar(Conta target, double value)
		throws SaldoInsuficienteException,
				ContaNaoCadastradaException
	{
		this.contas.debitar(target, value);
	}
	
	public void transferir(Conta origem, Conta destino, double value)
			throws SaldoInsuficienteException,
					InvalidValueException,
					ContaNaoCadastradaException
	{
		this.contas.transferir(origem, destino, value);
	}
	
	public listaContas listaContasCliente(Cliente target){
		return this.contas.listaContasCliente(target);
	}

	public listaContas listaContas(){
		return this.contas.listaContas();
	}
	
	public void renderBonus(Conta target)
			throws 
					ContaNaoCadastradaException,
					ClasseContaInvalidaException
	{
		this.contas.renderBonus(target);
	}

	public void renderJuros(Conta target)
			throws 
			ContaNaoCadastradaException,
			ClasseContaInvalidaException
		{

			this.contas.renderJuros(target);
		}


}//fim da classe fachada
