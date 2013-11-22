package cadastros;
import classasBasicas.Cliente;
import listas.listaClientes;
import repositorios.RepositorioClienteArray;


public class cadastroClientes {
	//cadastro de conta deve interagir com o repositório de clientes
	
	private RepositorioClienteArray clientes;
		
	public cadastroClientes(RepositorioClienteArray repCl) {
		this.clientes = repCl;
	}
	
	public void atualizar(Cliente targetCl){
		clientes.atualizar(targetCl);
	}
	
	public void cadastrar(Cliente newCl){
		clientes.inserir(newCl);	
	}

	public void descadastrar(Cliente target){
		clientes.remover(target);
	}
	
	public Cliente procurar(Cliente target){		
		return	clientes.procurar(target);
	}
	
	
	public listaClientes listaClientes(){
		listaClientes listaCl = new listaClientes();
		int i = 0;
		
		for(i = 0; i < this.clientes.getIndice(); i++)
			listaCl.insert(this.clientes.getCliente(i));
		
		return listaCl;
	}
	
	public boolean existe(Cliente target){
		return this.clientes.existe(target);
	}
	

}//fim da classe cadastroClientes


