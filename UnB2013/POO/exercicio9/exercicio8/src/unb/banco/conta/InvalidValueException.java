package unb.banco.conta;

public class InvalidValueException extends Exception {

	public InvalidValueException(){
		super("Valor inválido");
	}
	
	public InvalidValueException(String msg){
		super(msg);
	}
	
	
}
