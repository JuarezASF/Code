package unb.banco.cliente;

public class ClienteJaCadastrado extends Exception{
	public ClienteJaCadastrado()
		{
			super("Cliente já cadastrado");
		}
	
	public ClienteJaCadastrado(String msg){
		super(msg);
		}
}
