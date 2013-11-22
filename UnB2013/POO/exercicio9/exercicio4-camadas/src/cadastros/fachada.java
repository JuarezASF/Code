package cadastros;
import listas.listaClientes;
import listas.listaContas;
import classasBasicas.Cliente;
import classasBasicas.Conta;
import repositorios.RepositorioClienteArray;
import repositorios.RepositorioContasArray;


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
		Cliente targetCl = this.clientes.procurar(targetC.getDono());
		Conta newConta = new Conta (targetC.getNumber(), targetCl);
		
		if(targetCl != null)
			this.contas.cadastrar(newConta);
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
	

}//fim da classe fachada
