package myGUI2;

import javax.swing.JFrame;

public class myGUI {

	public static void main(String[] args) {
		
		myGUIClass juara = new myGUIClass();
		juara.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//define como terminar o programa
		
		juara.setSize(275, 180);
		juara.setVisible(true);
	}

}
