package unb.banco.conta;

public class ClasseContaInvalidaException extends Exception {
	public ClasseContaInvalidaException(String msg)
		{
			super(msg);
		}
	public ClasseContaInvalidaException()
		{
			super("A operação não está disponível para essa classe de conta!");
		}
	
}
