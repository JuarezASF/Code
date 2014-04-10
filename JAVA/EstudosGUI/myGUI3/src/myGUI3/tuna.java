package myGUI3;

import java.awt.FlowLayout;

//sistema de lençar e tratar eventos
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;

public class tuna extends JFrame{

	private JTextField item1;
	private JTextField item2;
	private JTextField item3;
	private JPasswordField senha1;
	
	public tuna(){
		super("O Título da Janela");
		setLayout(new FlowLayout());
		
		item1 = new JTextField(10);
		add(item1);
		
		item2 = new JTextField("Entre com o texto aqui");
		add(item2);
		
		item3 = new JTextField("não editável", 20);
		item3.setEditable(false);
		add(item3);
		
		senha1 = new JPasswordField("minha_senha");
		add(senha1);
		
		handler TheHandler = new handler();
		
		//adicionar handler para resolver eventos
		item1.addActionListener(TheHandler);
		item2.addActionListener(TheHandler);
		item3.addActionListener(TheHandler);
		senha1.addActionListener(TheHandler);
		
	}
	

	//Ao criar uma classe dentro de outra, a classe interna herda tudo da externa
	private class handler implements ActionListener{
		public void actionPerformed(ActionEvent event){
			String string = "";
			
			if(event.getSource() == item1)
				string = String.format("field 1: %s", event.getActionCommand());
				//event.getActionCommand() pega o texto entrado
			else if(event.getSource() == item2)
				string = String.format("field 2: %s", event.getActionCommand());
			else if(event.getSource() == item3)
				string = String.format("field 3: %s", event.getActionCommand());
			else if(event.getSource() == senha1)
				string = String.format("senha: %s", event.getActionCommand());
			
			JOptionPane.showMessageDialog(null, string);
		}
	}
	
}
