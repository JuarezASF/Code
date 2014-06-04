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

import sintese.InstrumentoAditivo;
import sintese.Melodia;
import sintese.Som;
import sintese.Tema;
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
		
		JMenuItem efeitosMenu = new JMenu("Efeitos");
		menuBar.add(efeitosMenu);
		
		JMenu demosInst1menu = new JMenu("Demos Instrumento 1");
		JMenu demosInst2menu = new JMenu("Demos Instrumento 2");
		JMenu demosInst3menu = new JMenu("Demos Instrumento 3");
		
		efeitosMenu.add(demosInst1menu);
		efeitosMenu.add(demosInst2menu);
		efeitosMenu.add(demosInst3menu);
		
		JMenuItem inst1demo1Item = new JMenuItem("demo 1");
		JMenuItem inst1demo2Item = new JMenuItem("demo 2");
		
		inst1demo1Item.setActionCommand("i1d1");
		inst1demo2Item.setActionCommand("i1d2");
		
		demosInst1menu.add(inst1demo1Item);
		demosInst1menu.add(inst1demo2Item);
		
		JMenuItem inst2demo1Item = new JMenuItem("demo 1");
		JMenuItem inst2demo2Item = new JMenuItem("demo 2");
		JMenuItem inst2demo3Item = new JMenuItem("demo 3");
		JMenuItem inst2demo4Item = new JMenuItem("demo 4");
		JMenuItem inst2demo5Item = new JMenuItem("demo 5");

		inst2demo1Item.setActionCommand("i2d1");
		inst2demo2Item.setActionCommand("i2d2");
		inst2demo3Item.setActionCommand("i2d3");
		inst2demo4Item.setActionCommand("i2d4");
		inst2demo5Item.setActionCommand("i2d5");
		
		
		demosInst2menu.add(inst2demo1Item);
		demosInst2menu.add(inst2demo2Item);
		demosInst2menu.add(inst2demo3Item);
		demosInst2menu.add(inst2demo4Item);
		demosInst2menu.add(inst2demo5Item);

		JMenuItem inst3demo1Item = new JMenuItem("demo 1");
		JMenuItem inst3demo2Item = new JMenuItem("demo 2");
		JMenuItem inst3demo3Item = new JMenuItem("demo 3");
		JMenuItem inst3demo4Item = new JMenuItem("demo 4");
		JMenuItem inst3demo5Item = new JMenuItem("demo 5");

		inst3demo1Item.setActionCommand("i3d1");
		inst3demo2Item.setActionCommand("i3d2");
		inst3demo3Item.setActionCommand("i3d3");
		inst3demo4Item.setActionCommand("i3d4");
		inst3demo5Item.setActionCommand("i3d5");
		
		demosInst3menu.add(inst3demo1Item);
		demosInst3menu.add(inst3demo2Item);
		demosInst3menu.add(inst3demo3Item);
		demosInst3menu.add(inst3demo4Item);
		demosInst3menu.add(inst3demo5Item);
		
		JMenu melodiaMenu = new JMenu("Melodias");
		menuBar.add(melodiaMenu);
		
		JMenuItem melodia1 = new JMenuItem("melodia 1");
		JMenuItem melodia2 = new JMenuItem("melodia 2");
		JMenuItem melodia3 = new JMenuItem("melodia 3");
		JMenuItem melodia4 = new JMenuItem("melodia 4");
		JMenuItem melodia5 = new JMenuItem("melodia 5");
		
		melodia1.setActionCommand("m1");
		melodia2.setActionCommand("m2");
		melodia3.setActionCommand("m3");
		melodia4.setActionCommand("m4");
		melodia5.setActionCommand("m5");
		
		melodiaMenu.add(melodia1);
		melodiaMenu.add(melodia2);
		melodiaMenu.add(melodia3);
		melodiaMenu.add(melodia4);
		melodiaMenu.add(melodia5);
		
		
		
		setJMenuBar(menuBar);
		
		MenuLidador menuLidador = new MenuLidador();
		
		instrumento1_item.setActionCommand("instrumento 1");
		instrumento2_item.setActionCommand("instrumento 2");
		instrumento3_item.setActionCommand("instrumento 3");
		
		instrumento1_item.addActionListener(menuLidador);
		instrumento2_item.addActionListener(menuLidador);
		instrumento3_item.addActionListener(menuLidador);
		
		inst1demo1Item.addActionListener(menuLidador);
		inst1demo2Item.addActionListener(menuLidador);
		
		inst2demo1Item.addActionListener(menuLidador);
		inst2demo2Item.addActionListener(menuLidador);
		inst2demo3Item.addActionListener(menuLidador);
		inst2demo4Item.addActionListener(menuLidador);
		inst2demo5Item.addActionListener(menuLidador);
		
		inst3demo1Item.addActionListener(menuLidador);
		inst3demo2Item.addActionListener(menuLidador);
		inst3demo3Item.addActionListener(menuLidador);
		inst3demo4Item.addActionListener(menuLidador);
		inst3demo5Item.addActionListener(menuLidador);
		
		melodia1.addActionListener(menuLidador);
		melodia2.addActionListener(menuLidador);	
		melodia3.addActionListener(menuLidador);
		melodia4.addActionListener(menuLidador);
		melodia5.addActionListener(menuLidador);
		
		tipo_instrumento = 0;
				
		//label de Frequência do Instrumento
		JLabel f_label = new JLabel("Frequência");
		F_slider = new JSlider(100, 1000);
		F_slider.setValue(440);
		f_label_value = new JLabel("440 Hz");
		
		//label de frequencia do ruido
		JLabel f_ran_label = new JLabel("F. do Ruído");
		F_ran_slider = new JSlider(1, 1000);
		F_ran_slider.setValue(60);
		f_ran_label_value = new JLabel("60 Hz");
		
		//label de amplitude do ruido
		JLabel a_ran_label = new JLabel("A. do Ruído");
		A_ran_slider = new JSlider(1, 360);
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
		
		ins1 = new Instrumento1();
		ins2 = new Instrumento2();
		ins3 = new Instrumento3();
		tipo_instrumento = 1;
		setInterface(tipo_instrumento);
			
	}
	
	private void setInterface(int instrumento){
		
		switch(instrumento){
			case(1):
				Amplitude_slider.setEnabled(false);
				amp_osci_slider.setEnabled(false);
				freq_osci_slider.setEnabled(false);
				break;
			case(2):
				Amplitude_slider.setEnabled(true);
				amp_osci_slider.setEnabled(false);
				freq_osci_slider.setEnabled(false);
				break;
			case(3):
				Amplitude_slider.setEnabled(true);
				amp_osci_slider.setEnabled(true);
				freq_osci_slider.setEnabled(true);
				break;
		}
		
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
				tipo_instrumento = 1;
				setInterface(tipo_instrumento);
			}else if("instrumento 2".equals(action)){
				tipo_instrumento = 2;
				setInterface(tipo_instrumento);
			}else if("instrumento 3".equals(action)){
				tipo_instrumento = 3;
				setInterface(tipo_instrumento);
			}else if("i1d1".equals(action)){
				tipo_instrumento = 1;
				setInterface(tipo_instrumento);
				setValue(440, -1, 20, 60, -1, -1, -1);
			}else if("i1d2".equals(action)){
				tipo_instrumento = 1;
				setInterface(tipo_instrumento);
				setValue(700, -1, 50, 660, -1, -1, -1);
			}else if("i2d1".equals(action)){
				tipo_instrumento = 2;
				setInterface(tipo_instrumento);
				setValue(440, -1, 26, 1, -1, -1, -1);
			}else if("i2d2".equals(action)){
				tipo_instrumento = 2;
				setInterface(tipo_instrumento);
				setValue(440, -1, 26, 12, -1, -1, -1);
			}else if("i2d3".equals(action)){
				tipo_instrumento = 2;
				setInterface(tipo_instrumento);
				setValue(440, -1, 60, 12, -1, -1, -1);
			}else if("i2d4".equals(action)){
				tipo_instrumento = 2;
				setInterface(tipo_instrumento);
				setValue(440, -1, 60, 425, -1, -1, -1);
			}else if("i2d5".equals(action)){
				tipo_instrumento = 2;
				setInterface(tipo_instrumento);
				setValue(440, -1, 1, 400, -1, -1, -1);
			}else if("i3d1".equals(action)){
				tipo_instrumento = 3;
				setInterface(tipo_instrumento);
				setValue(440, -1, 20, 1, -1, 10, 10);
			}else if("i3d2".equals(action)){
				tipo_instrumento = 3;
				setInterface(tipo_instrumento);
				setValue(440, -1, 1, 1, -1, 30, 10);
			}else if("i3d3".equals(action)){
				tipo_instrumento = 3;
				setInterface(tipo_instrumento);
				setValue(440, -1, 1, 1, -1, 32, 31);
			}else if("i3d4".equals(action)){
				tipo_instrumento = 3;
				setInterface(tipo_instrumento);
				setValue(440, -1, 1, 1, -1, 56, 80);
			}else if("i3d5".equals(action)){
				tipo_instrumento = 3;
				setInterface(tipo_instrumento);
				setValue(440, -1, 50, 1, -1, 56, 80);
			}else if("m1".equals(action)){
				 InstrumentoAditivo ins_add = new InstrumentoAditivo();
			     if(tipo_instrumento==1)
			    	 ins_add.addUnidade(ins1);
			     else if(tipo_instrumento==2)
			    	 ins_add.addUnidade(ins2);
			     else if(tipo_instrumento==3)
			    	 ins_add.addUnidade(ins3);
			     
			     Melodia m1 = Tema.tema_bwv988goldberg_v03_eq(0.85f).transposicao(0.35f);
			     m1.print();
			     
			     Som s1 = m1.getSom(ins_add);
			     s1.salvawave();
			     s1.tocawave();
			}
			invalidate();
			validate();
			centro.updateUI();
			
		}
		void setValue(int f, int a, int a_rui, int f_rui, int d, int a2, int f2){
			if (f != -1) F_slider.setValue(f);
			if (a != -1)Amplitude_slider.setValue(a);
			if (a_rui != -1) A_ran_slider.setValue(a_rui);
			if (f_rui != -1) F_ran_slider.setValue(f_rui);
			if (d != -1) dura_slider.setValue(d);
			if (a2 != -1)amp_osci_slider.setValue(a2);
			if (f2 != -1)freq_osci_slider.setValue(f2);

		}

		
	}// end class MenuLidador
	
	class Lidador implements ChangeListener, ActionListener{
		public void stateChanged(ChangeEvent e){
			if(e.getSource() == F_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				f_label_value.setText(desiredPosition + " Hz");
			}
			else if(e.getSource() == F_ran_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				
				f_ran_label_value.setText(desiredPosition + " Hz");
			}else if(e.getSource() == A_ran_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				a_ran_label_value.setText(desiredPosition + "");
			}else if(e.getSource() == dura_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				dura_label_value.setText(desiredPosition + " s");
			}else if(e.getSource() == Amplitude_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				amplitude_label_value.setText(desiredPosition + "");
			}else if(e.getSource() == amp_osci_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				amp_osci_label_value.setText(desiredPosition + "");
			}else if(e.getSource() == freq_osci_slider){
				JSlider src = (JSlider)e.getSource();
				int desiredPosition;
				desiredPosition = (int)src.getValue();
				
				freq_osci_label_value.setText(desiredPosition + "Hz");
			}
			
		}

		public void actionPerformed(ActionEvent e) {
			String action = e.getActionCommand();
					if("play".equals(action)){
						resetInst();
						if(tipo_instrumento == 3)
						{
							Som som = new Som(ins3);
							som.salvawave();
							som.tocawave();
							
						}else if(tipo_instrumento == 2)
						{
							Som som = new Som(ins2);
							som.salvawave();
							som.tocawave();
							
						}else if(tipo_instrumento == 1)
						{
							Som som = new Som(ins1);
							som.salvawave();
							som.tocawave();
							
						} 
					
					}
				}
		
		void resetInst(){
			Instrumento ins;
			switch(tipo_instrumento){
				case(1):
					ins1 = new Instrumento1();
					ins = ins1;
					break;
				case(2):
					ins2 = new Instrumento2();
					ins = ins2;
					break;
				case(3):
					ins3 = new Instrumento3();
					ins = ins3;
					break;
				default: //isso nuca deve acontecer
					ins = ins1;
					ins = ins1;	
					break;
			}
			
			ins.setFrequencia(F_slider.getValue());
			ins.setGanho(Amplitude_slider.getValue());
			ins.setGanhoRuido(A_ran_slider.getValue());
			ins.setF_ruido(F_ran_slider.getValue());
			ins.setDuracao(dura_slider.getValue());
			ins.setOsciFrequenciaA(amp_osci_slider.getValue());
			ins.setOsciFrequenciaF(freq_osci_slider.getValue());
		}
		
				
	}

	
	

}
