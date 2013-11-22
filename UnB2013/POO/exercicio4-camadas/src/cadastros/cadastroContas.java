package cadastros;
import classasBasicas.Cliente;
import classasBasicas.Conta;
import listas.listaContas;
import repositorios.RepositorioContasArray;
import userInterface.UserInterface;


public class cadastroContas {
//cadastro de conta deve interagir com o repositório de contas
	private RepositorioContasArray contas;
	
	public cadastroContas(RepositorioContasArray repC) {
		this.contas = repC;
	}
	
	public void atualizar(Conta newC){
		contas.atualizar(newC);
	}
	
	public void cadastrar(Conta newC){
		contas.inserir(newC);	
	}
	
	public void creditar(Conta target, double value){
		Conta c = contas.procurar(target);
		if(c != null)
			if(value >= 0)
				c.creditar(value);
			else
				UserInterface.report("Valor não pode ser creditado!");
	}

	public void debitar(Conta target, double value){
		Conta c = contas.procurar(target);
		if(c != null)
			if(value >= 0 && value <= c.getSaldo())
				c.debitar(value);
			else
				UserInterface.report("Valor não pode ser debitado!");
	}
	
	public void descadastrar(Conta target){
			this.contas.remover(target);
	}
	
	public Conta procurar(Conta target){
		return contas.procurar(target);
	}
	
	public void transferir(Conta origem, Conta destino,
							double value)
	{	
		Conta O = contas.procurar(origem);
		Conta D = contas.procurar(destino);
		
		if(O == null || D == null)
			{
			UserInterface.report("Problema com identificação das contas!");
			return;
			}
			
		if(value < 0 || value > D.getSaldo())
			{
				UserInterface.report("Valor não pode ser transferido!");
				return;
			}
		
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
					listaC.insert(current);
				}
			}
		return listaC;
	}
	
	public listaContas listaContas(){
		listaContas listaC = new listaContas();
		int i = 0;
		
		for(i = 0; i < this.contas.getIndice(); i++)
			listaC.insert(this.contas.getConta(i));
		
		return listaC;
	}
	

}//fim da classe
