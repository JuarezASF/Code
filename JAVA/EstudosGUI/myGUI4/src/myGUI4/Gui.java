package myGUI4;

//sistema de lençar e tratar eventos
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;
import javax.swing.JButton;
import javax.swing.Icon;
import javax.swing.ImageIcon;



public class Gui extends JFrame{

	private JButton regular;
	private JButton custom;
	
	public Gui(){
		//define título da janela
		super("Título da Janela");
		setLayout(new FlowLayout());
		
		//cria, define e adiciona butões
		regular = new JButton("regular");
		add(regular);
		
		
		//figura de butões deve ser 40x40
		//formato pode ser .png
		Icon myIcon = new ImageIcon(getClass().getResource("JF_buttom.png"));
		Icon myIco2 = new ImageIcon(getClass().getResource("IP_buttom.png"));
		custom = new JButton("Custom", myIcon);
		custom.setRolloverIcon(myIco2);
		add(custom);
		
		
		Handler myHandler = new Handler();
		regular.addActionListener(myHandler);
		custom.addActionListener(myHandler);
		
	}
	
	private class Handler implements ActionListener{
		
		public void actionPerformed(ActionEvent event) {
				JOptionPane.showMessageDialog(null, String.format("%s",event.getActionCommand()));
		}
	}//fim classe Handler
	
}
