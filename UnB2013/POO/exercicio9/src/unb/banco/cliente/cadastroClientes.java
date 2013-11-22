package unb.banco.cliente;
import unb.banco.dados.cliente.RepositorioCliente;

public class cadastroClientes {
	//cadastro de conta deve interagir com o repositório de clientes
	
	private RepositorioCliente clientes;
		
	public cadastroClientes(RepositorioCliente repCl) {
		this.clientes = repCl;
	}
	
	public void atualizar(Cliente targetCl)
		throws Exception
		{
		clientes.atualizar(targetCl);
	}
	
	public void cadastrar(Cliente newCl)
			throws Exception
		{
		clientes.inserir(newCl);	
	}

	public void descadastrar(Cliente target)
			throws Exception
		{
		clientes.remover(target);
	}
	
	public Cliente procurar(Cliente target)
			throws Exception
		{		
		return	clientes.procurar(target);
		}
	
	
	public listaClientes listaClientes()
			throws Exception
	{
		listaClientes listaCl = new listaClientes();
		int i = 0;
		
		for(i = 0; i < this.clientes.getSize(); i++)
			listaCl.insert(this.clientes.getCliente(i));
		
		return listaCl;
	}
	
	public boolean existe(Cliente target)
			throws Exception
	{
		return this.clientes.existe(target);
	}
	

}//fim da classe cadastroClientes


