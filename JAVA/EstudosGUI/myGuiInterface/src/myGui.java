

import javax.swing.JOptionPane;
//clase básica para gui

/*
 * GUI: graphical user interface
 * */
public class myGui {
	
	public static void main(String args[]){

	String s_firstNumber = JOptionPane.showInputDialog("Entre com o primeiro número aqui:");
	String s_secondNumber = JOptionPane.showInputDialog("Entre com o segundo número aqui:");
	//showInputDialog retorna uma string de entrada
	//precisamos converter
	
	int i_firstNumber = Integer.parseInt(s_firstNumber);
	int i_secondNumber = Integer.parseInt(s_secondNumber);
	
	int sum = i_firstNumber + i_secondNumber;
	
	JOptionPane.showMessageDialog(null, "A resposta é " + sum, "titulo da janela", JOptionPane.PLAIN_MESSAGE);
	//primeiro argumento: onde o diálogo aparece. null para meio da tela
	//segundo argumento: menssagem
	//terceiro: nome da tela
	//quarto: frame em que a msg aparece
	}
}
