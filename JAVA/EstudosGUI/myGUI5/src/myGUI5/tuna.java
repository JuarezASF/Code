package myGUI5;
//sistema de lençar e tratar eventos
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class tuna extends JFrame{

	private JTextField tf;
	private JCheckBox boldBox;
	private JCheckBox italicBox;
	
	public tuna(){
		super("O título da Janela");
		setLayout(new FlowLayout());
		
		tf = new JTextField("Esta é a frase", 20);
		tf.setFont(new Font("Serif", Font.PLAIN, 14));
		add(tf);
		
		//ar1 = nome que aparece no check box
		boldBox = new JCheckBox("BOLD");
		add(boldBox);
		
		italicBox = new JCheckBox("Italic");
		add(italicBox);
		
		Handler myHandler = new Handler();
		boldBox.addItemListener(myHandler);
		italicBox.addItemListener(myHandler);
		
	}
	
	private class Handler implements ItemListener{
		
		public void itemStateChanged(ItemEvent e) {
			Font font = null;
			if(boldBox.isSelected() && italicBox.isSelected())
				font = new Font("Serif", Font.BOLD + Font.ITALIC, 14);
			else if(boldBox.isSelected() )
				font = new Font("Serif", Font.BOLD, 14);
			else if(italicBox.isSelected())
				font = new Font("Serif",Font.ITALIC, 14);
			else
				font = new Font("Serif", Font.PLAIN, 14);
		
			tf.setFont(font);
		}
		
		}

}