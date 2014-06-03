package GUI;

import java.awt.BorderLayout;
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
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import org.math.plot.Plot2DPanel;

import sintese.Som;
import SomJASF.Instrumentos.*;

public class GUI extends JFrame
{
	private JSlider F_slider, F_ran_slider, A_ran_slider, dura_slider;
	private JSlider Amplitude_slider, amp_osci_slider;
	private JSlider freq_osci_slider;
	JLabel f_label_value, f_ran_label_value, a_ran_label_value, dura_label_value;
	JLabel amplitude_label_value, amp_osci_label_value, freq_osci_label_value;
	private JButton play;
	private int tipo_instrumento;
	
	private Plot2DPanel plot;
	
	private Instrumento1 ins1;
	private Instrumento2 ins2;
	private Instrumento3 ins3;
	
	private BorderLayout myLayout;
	private JPanel  centro, sul, direita, esquerda, norte;
	
	public GUI(){
		super("Introdução a Computação Sônica - Trabalho 2 - Síntese Aditiva");		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		myLayout = new BorderLayout();
		this.setLayout(myLayout);
		
		norte = new JPanel();
		norte.setLayout(new FlowLayout());
		add(norte, BorderLayout.NORTH);
		
		centro = new JPanel();
		centro.setLayout(new FlowLayout());
		add(centro, BorderLayout.CENTER);
		
		//MENU BAR

		JMenuBar menuBar = new JMenuBar();
		
		
		add(menuBar, BorderLayout.NORTH);
		JMenu fileMenu = new JMenu("File");
		menuBar.add(fileMenu);
		

		
		JMenu carregarInstrumentoMenu = new JMenu("Carregar Instrumento");
		menuBar.add(carregarInstrumentoMenu);
		JMenuItem instrumento1_item = new JMenuItem("Instrumento 1");
		JMenuItem instrumento2_item = new JMenuItem("Instrumento 2");
		JMenuItem instrumento3_item = new JMenuItem("Instrumento 3");
		carregarInstrumentoMenu.add(instrumento1_item);
		carregarInstrumentoMenu.add(instrumento2_item);
		carregarInstrumentoMenu.add(instrumento3_item);
		
		setJMenuBar(menuBar);
		
		MenuLidador menuLidador = new MenuLidador();
		
		instrumento1_item.setActionCommand("instrumento 1");
		instrumento2_item.setActionCommand("instrumento 2");
		instrumento3_item.setActionCommand("instrumento 3");
		
		instrumento1_item.addActionListener(menuLidador);
		instrumento2_item.addActionListener(menuLidador);
		instrumento3_item.addActionListener(menuLidador);
		tipo_instrumento = 0;
		
		ins1 = new Instrumento1();
		ins2 = new Instrumento2();
		ins3 = new Instrumento3();
		
		setInstrumento1Interface();
		
			
	}
	
	private void setInstrumento1Interface(){
		tipo_instrumento = 1;
		//label de Frequência do Instrumento
		JLabel f_label = new JLabel("Frequência");
		F_slider = new JSlider(100, 1000);
		F_slider.setValue(440);
		f_label_value = new JLabel("440 Hz");
		
		//label de frequencia do ruido
		JLabel f_ran_label = new JLabel("F. do Ruído");
		F_ran_slider = new JSlider(1, 100);
		F_ran_slider.setValue(60);
		f_ran_label_value = new JLabel("60 Hz");
		
		//label de amplitude do ruido
		JLabel a_ran_label = new JLabel("A. do Ruído");
		A_ran_slider = new JSlider(1, 100);
		A_ran_slider.setValue(20);
		a_ran_label_value = new JLabel("20 Hz");
		
		
		//label de duração
		JLabel dura_label = new JLabel("Duração");
		dura_slider = new JSlider(0, 20);
		dura_slider.setValue(5);
		dura_label_value = new JLabel("5s");
		
		play = new JButton("tocar");
		play.setActionCommand("play");
	
		class Lidador implements ChangeListener, ActionListener{
			public void stateChanged(ChangeEvent e) {
				if(e.getSource() == F_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins1.setFrequencia(desiredPosition);
					f_label_value.setText(desiredPosition + " Hz");
				}
				else if(e.getSource() == F_ran_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins1.setF_ruido(desiredPosition);
					f_ran_label_value.setText(desiredPosition + " Hz");
				}else if(e.getSource() == A_ran_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins1.setGanho(desiredPosition);
					a_ran_label_value.setText(desiredPosition + "");
				}else if(e.getSource() == dura_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins1.setDuracao(desiredPosition);
					dura_label_value.setText(desiredPosition + " s");
				}
				
			}

			public void actionPerformed(ActionEvent e) {
				String action = e.getActionCommand();
						if("play".equals(action)){
							if(tipo_instrumento == 1)
							{
								Som som = new Som(ins1);
								som.salvawave("ins1.wav");
								som.tocawave("ins1.wav");
							}
						}//end "play/pause"	
					}
		}
	
		
		Lidador meuLidador = new Lidador();
		
		F_slider.addChangeListener(meuLidador);
		F_ran_slider.addChangeListener(meuLidador);
		A_ran_slider.addChangeListener(meuLidador);
		dura_slider.addChangeListener(meuLidador);
		play.addActionListener(meuLidador);
				

		
		centro.add(f_label); centro.add(F_slider);centro.add(f_label_value);
		centro.add(f_ran_label); centro.add(F_ran_slider);centro.add(f_ran_label_value);
		centro.add(a_ran_label); centro.add(A_ran_slider);centro.add(a_ran_label_value);
		centro.add(dura_label); centro.add(dura_slider);centro.add(dura_label_value);
		centro.add(play);

	}

	private void setInstrumento2Interface(){
		tipo_instrumento = 2;
		//label de Frequência do Instrumento
		JLabel f_label = new JLabel("Frequência");
		F_slider = new JSlider(100, 1000);
		F_slider.setValue(440);
		f_label_value = new JLabel("440 Hz");
		
		//label de frequencia do ruido
		JLabel f_ran_label = new JLabel("F. do Ruído");
		F_ran_slider = new JSlider(1, 100);
		F_ran_slider.setValue(60);
		f_ran_label_value = new JLabel("60 Hz");
		
		//label de amplitude do ruido
		JLabel a_ran_label = new JLabel("A. do Ruído");
		A_ran_slider = new JSlider(1, 100);
		A_ran_slider.setValue(20);
		a_ran_label_value = new JLabel("20 Hz");
		
		
		//label de duração
		JLabel dura_label = new JLabel("Duração");
		dura_slider = new JSlider(0, 20);
		dura_slider.setValue(5);
		dura_label_value = new JLabel("5s");
		
		//label de amplitude
		JLabel amplitude_label = new JLabel("Amplitude");
		Amplitude_slider = new JSlider(0, 50);
		Amplitude_slider.setValue(10);
		amplitude_label_value = new JLabel("10");
		
		
		play = new JButton("tocar");
		play.setActionCommand("play");
	
		class Lidador implements ChangeListener, ActionListener{
			public void stateChanged(ChangeEvent e) {
				if(e.getSource() == F_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins2.setFrequencia(desiredPosition);
					f_label_value.setText(desiredPosition + " Hz");
				}
				else if(e.getSource() == F_ran_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins2.setFrequenciaRuido(desiredPosition);
					f_ran_label_value.setText(desiredPosition + " Hz");
				}else if(e.getSource() == A_ran_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins2.setGanho(desiredPosition);
					a_ran_label_value.setText(desiredPosition + "");
				}else if(e.getSource() == dura_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins2.setDuracao(desiredPosition);
					dura_label_value.setText(desiredPosition + " s");
				}else if(e.getSource() == Amplitude_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins2.setGanho(desiredPosition);
					amplitude_label_value.setText(desiredPosition + "");
				}
				
			}

			public void actionPerformed(ActionEvent e) {
				String action = e.getActionCommand();
						if("play".equals(action)){
							if(tipo_instrumento == 2)
							{
								Som som = new Som(ins2);
								som.salvawave("ins2.wav");
								som.tocawave("ins2.wav");
							}
						}//end "play/pause"	
					}
		}
	
		
		Lidador meuLidador = new Lidador();
		
		F_slider.addChangeListener(meuLidador);
		F_ran_slider.addChangeListener(meuLidador);
		A_ran_slider.addChangeListener(meuLidador);
		dura_slider.addChangeListener(meuLidador);
		Amplitude_slider.addChangeListener(meuLidador);
		play.addActionListener(meuLidador);
				

		
		centro.add(f_label); centro.add(F_slider);centro.add(f_label_value);
		centro.add(f_ran_label); centro.add(F_ran_slider);centro.add(f_ran_label_value);
		centro.add(a_ran_label); centro.add(A_ran_slider);centro.add(a_ran_label_value);
		centro.add(dura_label); centro.add(dura_slider);centro.add(dura_label_value);
		centro.add(amplitude_label); centro.add(Amplitude_slider); centro.add(amplitude_label_value);
		centro.add(play);

	}
	
	private void setInstrumento3Interface(){
		tipo_instrumento = 3;
		//label de Frequência do Instrumento
		JLabel f_label = new JLabel("Frequência");
		F_slider = new JSlider(100, 1000);
		F_slider.setValue(440);
		f_label_value = new JLabel("440 Hz");
		
		//label de frequencia do ruido
		JLabel f_ran_label = new JLabel("F. do Ruído");
		F_ran_slider = new JSlider(1, 100);
		F_ran_slider.setValue(60);
		f_ran_label_value = new JLabel("60 Hz");
		
		//label de amplitude do ruido
		JLabel a_ran_label = new JLabel("A. do Ruído");
		A_ran_slider = new JSlider(1, 100);
		A_ran_slider.setValue(20);
		a_ran_label_value = new JLabel("20 Hz");
		
		
		//label de duração
		JLabel dura_label = new JLabel("Duração");
		dura_slider = new JSlider(0, 20);
		dura_slider.setValue(5);
		dura_label_value = new JLabel("5s");
		
		//label de amplitude
		JLabel amplitude_label = new JLabel("Amplitude");
		Amplitude_slider = new JSlider(0, 50);
		Amplitude_slider.setValue(10);
		amplitude_label_value = new JLabel("10");

		//label de amplitude do oscilador de frequencia
		JLabel amp_osci_label = new JLabel("A. Osci. Freq.");
		amp_osci_slider = new JSlider(0, 100);
		amp_osci_slider.setValue(10);
		amp_osci_label_value = new JLabel("10");

		//label de freq do oscilador de frequencia
		JLabel freq_osci_label = new JLabel("F. Osci. Freq.");
		freq_osci_slider = new JSlider(0, 100);
		freq_osci_slider.setValue(10);
		freq_osci_label_value = new JLabel("10");
		
		play = new JButton("tocar");
		play.setActionCommand("play");
		
	
		class Lidador implements ChangeListener, ActionListener{
			public void stateChanged(ChangeEvent e) {
				if(e.getSource() == F_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setFrequencia(desiredPosition);
					f_label_value.setText(desiredPosition + " Hz");
				}
				else if(e.getSource() == F_ran_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setFRuido(desiredPosition);
					f_ran_label_value.setText(desiredPosition + " Hz");
				}else if(e.getSource() == A_ran_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setGanho(desiredPosition);
					a_ran_label_value.setText(desiredPosition + "");
				}else if(e.getSource() == dura_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setDuracao(desiredPosition);
					dura_label_value.setText(desiredPosition + " s");
				}else if(e.getSource() == Amplitude_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setGanho(desiredPosition);
					amplitude_label_value.setText(desiredPosition + "");
				}else if(e.getSource() == amp_osci_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setOsciFrequenciaA(desiredPosition);
					amp_osci_label_value.setText(desiredPosition + "");
				}else if(e.getSource() == freq_osci_slider){
					JSlider src = (JSlider)e.getSource();
					int desiredPosition;
					desiredPosition = (int)src.getValue();
					
					ins3.setOsciFrequenciaF(desiredPosition);
					freq_osci_label_value.setText(desiredPosition + "Hz");
				}
				
			}

			public void actionPerformed(ActionEvent e) {
				String action = e.getActionCommand();
						if("play".equals(action)){
							if(tipo_instrumento == 3)
							{
								Som som = new Som(ins3);
								som.salvawave("ins3.wav");
								som.tocawave("ins3.wav");
							}
						}//end "play/pause"	
					}
		}
	
		
		Lidador meuLidador = new Lidador();
		
		F_slider.addChangeListener(meuLidador);
		F_ran_slider.addChangeListener(meuLidador);
		A_ran_slider.addChangeListener(meuLidador);
		dura_slider.addChangeListener(meuLidador);
		Amplitude_slider.addChangeListener(meuLidador);
		amp_osci_slider.addChangeListener(meuLidador);
		freq_osci_slider.addChangeListener(meuLidador);
		play.addActionListener(meuLidador);
				

		
		centro.add(f_label); centro.add(F_slider);centro.add(f_label_value);
		centro.add(f_ran_label); centro.add(F_ran_slider);centro.add(f_ran_label_value);
		centro.add(a_ran_label); centro.add(A_ran_slider);centro.add(a_ran_label_value);
		centro.add(dura_label); centro.add(dura_slider);centro.add(dura_label_value);
		centro.add(amplitude_label); centro.add(Amplitude_slider); centro.add(amplitude_label_value);
		centro.add(amp_osci_label); centro.add(amp_osci_slider); centro.add(amp_osci_label_value);
		centro.add(freq_osci_label); centro.add(freq_osci_slider); centro.add(freq_osci_label_value);
		
		centro.add(play);

	}




	
	private Plot2DPanel  getPlot2d(Som som){
		byte pontos[] = som.getAmostras();
		Plot2DPanel plot = new Plot2DPanel();
		

		
		double[] x_array =new double[pontos.length];
		 double[] y_array =new double[pontos.length];
		  for (int i = 0; i < x_array.length; i++) {
			  x_array[i] = i;
			  y_array[i] = pontos[i]; 
		  }
		  
		  plot.addLinePlot("Pontos", x_array, y_array);

		return plot;
	}
	
	private void showInstrumento1(){
		
		Som som = new Som(ins1);
		plot = getPlot2d(som);
		add(plot);

		JFrame frame = new JFrame("Rand Envoltoria");
		  frame.setContentPane(plot);
		  frame.setVisible(true);
		  frame.setSize(320, 240);

	}
	
	class MenuLidador implements ActionListener{

		public void actionPerformed(ActionEvent e) {
			String action = e.getActionCommand();
			if("instrumento 1".equals(action)){
				centro.removeAll();
				setInstrumento1Interface();
			}else if("instrumento 2".equals(action)){
				centro.removeAll();
				setInstrumento2Interface();	
			}else if("instrumento 3".equals(action)){
				centro.removeAll();
				setInstrumento3Interface();
			}
			invalidate();
			validate();
			centro.updateUI();
			
		}
		
	}
	
	

}
