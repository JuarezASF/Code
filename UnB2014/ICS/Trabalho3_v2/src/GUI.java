import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Hashtable;

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

import sintese.InstrumentoAditivo;
import sintese.Melodia;
import sintese.Som;
import sintese.Tema;


public class GUI extends JFrame implements ActionListener, ChangeListener
{
	private EfeitoRissetContinuo risset;

	public GUI(){
		super("Risset Contínuo");		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		risset = new EfeitoRissetContinuo(5, 440, 0.1f, 10, false);
		
		JButton playB = new JButton("Tocar");
		playB.setActionCommand("play");
		playB.addActionListener(this);
		
		JButton visuB = new JButton("Visualizar");
		visuB.setActionCommand("visualizar");
		visuB.addActionListener(this);
		
		JSlider sliderT0 = new JSlider(0, 20, 5);
		sliderT0.setPaintLabels(true);
		sliderT0.setPaintTicks(true);
		sliderT0.setMajorTickSpacing(5);
		sliderT0.setMinorTickSpacing(1);
		sliderT0.addChangeListener(this);
		sliderT0.setName("sliderT0");
		JLabel labelT0 = new JLabel("T0", JLabel.CENTER);
		
		JSlider sliderDuracao = new JSlider(0, 40, 10);
		sliderDuracao.setPaintLabels(true);
		sliderDuracao.setPaintTicks(true);
		sliderDuracao.setMajorTickSpacing(10);
		sliderDuracao.setMinorTickSpacing(5);
		sliderDuracao.addChangeListener(this);
		sliderDuracao.setName("sliderDuracao");
		JLabel labelDuracao = new JLabel("Duração", JLabel.CENTER);
	
		JSlider sliderFc = new JSlider(0, 1000, 440);
		sliderFc.setPaintLabels(true);
		sliderFc.setPaintTicks(true);
		sliderFc.setMajorTickSpacing(250);
		sliderFc.setMinorTickSpacing(50);
		sliderFc.addChangeListener(this);
		sliderFc.setName("sliderFc");
		JLabel labelFc = new JLabel("Frequência Central", JLabel.CENTER);
	   
		JSlider sliderVar = new JSlider(0, 50, 10);
		sliderVar.setPaintLabels(true);
		sliderVar.setPaintTicks(true);
		sliderVar.setMajorTickSpacing(10);
		sliderVar.setMinorTickSpacing(5);
		sliderVar.addChangeListener(this);
		sliderVar.setName("sliderVar");
		JLabel labelVar = new JLabel("Variância(%)", JLabel.CENTER);
		
		JButton inverteB = new JButton("Inverter");
		inverteB.setActionCommand("inverte");
		inverteB.addActionListener(this);
		
		setLayout(new BorderLayout());
		
		JPanel centro = new JPanel();
		centro.setLayout(new FlowLayout());
		
		JPanel sul = new JPanel();
		sul.setLayout(new FlowLayout());
		
		centro.add(labelT0); centro.add(sliderT0);
		centro.add(labelDuracao); centro.add(sliderDuracao);
		centro.add(labelFc); centro.add(sliderFc);
		centro.add(labelVar); centro.add(sliderVar);
		centro.add(inverteB);
		
		sul.add(playB);
		sul.add(visuB);
		
		add(centro, BorderLayout.CENTER);
		add(sul, BorderLayout.SOUTH);
		
		

		
	}

		public void actionPerformed(ActionEvent e) {
			String action = e.getActionCommand();
			if(action.equals("play")){
				Som som = risset.getSom();
				som.salvawave("./wav/meuSom.wav");
				som.tocawave("./wav/meuSom.wav");
			}else if(action.equals("visualizar")){
				Som som = risset.getSom();
				som.visualiza();
			}else if(action.equals("inverte")){
				risset.setCrescente(!risset.isbCrescente());
			}
			
		}


		public void stateChanged(ChangeEvent e) {
			String action = ((JSlider)e.getSource()).getName();
			JSlider source = (JSlider)e.getSource();
			float value = source.getValue();
			if (!source.getValueIsAdjusting()) {
				if(action.equals("sliderT0"))
					risset.setT0(value);
				else if(action.equals("sliderDuracao"))
					risset.setDuracao(value);
				else if(action.equals("sliderFc"))
					risset.setFc(value);
				else if(action.equals("sliderVar"))
					risset.setVar(value);
			}//end if adjusting
		}//end statChanged(ChangeEvent e)

}
