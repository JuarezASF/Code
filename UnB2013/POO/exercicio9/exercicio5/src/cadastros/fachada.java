package cadastros;
import listas.listaClientes;
import listas.listaContas;
import classasBasicas.Cliente;
import classasBasicas.Conta;
import repositorios.RepositorioClienteArray;
import repositorios.RepositorioContasArray;
import userInterface.UserInterface;


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
	public void atualizar(Cliente targetCl){
		this.clientes.atualizar(targetCl);
	}
	
	public Cliente procurar(Cliente target){
		return this.clientes.procurar(target);
	}
	
	public void cadastrar(Cliente newCl){
		this.clientes.cadastrar(newCl);
	}

	public void descadastrar(Cliente target){
		
		Cliente targetCl = this.clientes.procurar(target);
		listaContas targetContas = this.contas.listaContasCliente(targetCl);
		
		while(targetContas.hasNext())
			{
			this.contas.descadastrar(targetContas.next());
			}
		this.clientes.descadastrar(target);
	}

	public listaClientes listaClientes(){
		return this.clientes.listaClientes();
	}
//--------------------------------------------------
//-----------Manipulação de contas----------------
//-------------------------------------------------
	public void atualizar(Conta targetC){
		this.contas.atualizar(targetC);
	}
	
	public Conta procurar(Conta target){
		return this.contas.procurar(target);
	}
	
	public void cadastrar(Conta targetC){
		//somente cadastramos contas de clientes existentes
		if(this.clientes.existe(targetC.getDono()))
			this.contas.cadastrar(targetC);
		else
			UserInterface.report("O cliente dono da conta não foi encontrado!");
	}

	public void descadastrar(Conta target){
		this.contas.descadastrar(target);
	}
	
	public void creditar(Conta target, double value){
		this.contas.creditar(target, value);
	}
	
	public void debitar(Conta target, double value){
		this.contas.debitar(target, value);
	}
	
	public void transferir(Conta origem, Conta destino, double value){
		this.contas.transferir(origem, destino, value);
	}
	
	public listaContas listaContasCliente(Cliente target){
		return this.contas.listaContasCliente(target);
	}

	public listaContas listaContas(){
		return this.contas.listaContas();
	}
	
	public void renderBonus(Conta target){
		Conta found = this.contas.procurar(target);
		if (found != null)
			this.contas.renderBonus(found);
	}

	public void renderJuros(Conta target){
		Conta found = this.contas.procurar(target);
		if (found != null)
			this.contas.renderJuros(found);
	}


}//fim da classe fachada
