package unb.banco.cliente;
import unb.banco.dados.cliente.RepositorioCliente;

public class cadastroClientes {
	//cadastro de conta deve interagir com o repositório de clientes
	
	private RepositorioCliente clientes;
		
	public cadastroClientes(RepositorioCliente repCl) {
		this.clientes = repCl;
	}
	
	public void atualizar(Cliente targetCl)
		throws ClienteNaoCadastradoException
		{
		clientes.atualizar(targetCl);
	}
	
	public void cadastrar(Cliente newCl)
		throws ClienteJaCadastrado
		{
		clientes.inserir(newCl);	
	}

	public void descadastrar(Cliente target)
			throws ClienteNaoCadastradoException
		{
		clientes.remover(target);
	}
	
	public Cliente procurar(Cliente target)
			throws ClienteNaoCadastradoException
		{		
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


