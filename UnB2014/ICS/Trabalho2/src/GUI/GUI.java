package GUI;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import org.math.plot.Plot2DPanel;

import sintese.Som;
import SomJASF.Instrumentos.*;

public class GUI extends JFrame
implements ActionListener, ChangeListener
{
	private JSlider F_slider, F_ran_slider, A_ran_slider;
	private JButton play;
	private int tipo_instrumento;
	
	private JMenuBar menuBar;
	private JMenu fileMenu;
	private JMenuItem loadMenuItem, loadSBItem;
	
	private Instrumento1 ins1;
	
	public GUI(){
		super("Introduçãoo a Computaçãoo Sônica - Trabalho 2 - Síntese Aditiva");		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		tipo_instrumento = 0;
		setInstrumento1Interface();
	}
	
	private void setInstrumento1Interface(){
		tipo_instrumento = 1;
		JLabel f_label = new JLabel("Frequência");
		F_slider = new JSlider(100, 1000);
		JLabel f_ran_label = new JLabel("Frequência do Ruído");
		F_ran_slider = new JSlider(1, 100);
		JLabel a_ran_label = new JLabel("Amplitude do Ruído");
		A_ran_slider = new JSlider(1, 100);
		setLayout(new FlowLayout());
		play = new JButton("tocar");
		play.setActionCommand("play");
		
		ins1 = new Instrumento1();
		
		F_slider.addChangeListener(this);
		F_ran_slider.addChangeListener(this);
		A_ran_slider.addChangeListener(this);
		play.addActionListener(this);
		
		add(f_label); add(F_slider);
		add(f_ran_label); add(F_ran_slider);
		add(a_ran_label); add(A_ran_slider);
		add(play);
		
		
		
	}
	
	public void stateChanged(ChangeEvent e) {
		if(e.getSource() == F_slider){
			JSlider src = (JSlider)e.getSource();
			int desiredPosition;
			desiredPosition = (int)src.getValue();
			
			ins1.setFrequencia(desiredPosition);
		}
		else if(e.getSource() == F_ran_slider){
			JSlider src = (JSlider)e.getSource();
			int desiredPosition;
			desiredPosition = (int)src.getValue();
			
			ins1.setF_Ran(desiredPosition);
		}else if(e.getSource() == A_ran_slider){
			JSlider src = (JSlider)e.getSource();
			int desiredPosition;
			desiredPosition = (int)src.getValue();
			
			ins1.setGanhoRuido(desiredPosition);
		}
		
	}

	public void actionPerformed(ActionEvent e) {
String action = e.getActionCommand();
		if("play".equals(action)){
			if(tipo_instrumento == 1)
			{
				Som som = new Som(ins1);
				som.visualiza();;
			}
		}//end "play/pause"	
	}
	
	private Plot2DPanel  getPlot2d(Som som){
		short pontos[] = som.getAmostrasDireita();
		Plot2DPanel plot = new Plot2DPanel();
		
		return plot;
		
		for(int i = 0; i < pontos.length; i++){
			
		}
	
	}

}
