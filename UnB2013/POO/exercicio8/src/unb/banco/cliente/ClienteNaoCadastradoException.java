package unb.banco.cliente;

public class ClienteNaoCadastradoException extends Exception{
	public ClienteNaoCadastradoException()
		{
			super("Cliente não cadastrado");
		}
	
	public ClienteNaoCadastradoException(String msg){
		super(msg);
		}
}
