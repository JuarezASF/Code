package unb.banco.dados.conta;

public class ContaJaExistenteException extends Exception{

	public ContaJaExistenteException()
		{
		super("Conta já cadastrada!");
		}
}
