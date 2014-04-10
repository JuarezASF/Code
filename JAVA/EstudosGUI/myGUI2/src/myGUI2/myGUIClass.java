
package myGUI2;

import java.awt.FlowLayout;
//importa o gerente de layout
//define onde as coisas são colocadas 

import javax.swing.JFrame;
//basic window features

import javax.swing.JLabel;
//label é uma linha de texto, pode-es colocar imagens também


public class myGUIClass extends JFrame{
	//ao herdar de JFrame já temos os botões
	//barra de titulo, minimize, maxmize and stuff
	
	private JLabel item1;
	
	public myGUIClass(){
		//construtor
		super("A barra de título");
		//construtor do pai
		setLayout(new FlowLayout());
		//seta o default layout
		
		item1 = new JLabel("Isto é uma frase!");
		item1.setToolTipText("Mensagem que aparece ao segurar o mouse");
		//criamos o item, setamos uma msg de informação
		//falta colocá-lo na janela
		
		add(item1);
		//função da classe myGUIclass
	}


}
