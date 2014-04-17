import javax.swing.Icon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.JTable;
import javax.swing.JFileChooser;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Image;
import java.io.File;

public class GUI extends JFrame
implements ActionListener, ChangeListener{
	
	private ImageIcon playI, pauseI, stopI, fwI, bwI;
	private int iconSize[];
	
	private JButton playB;
	private JButton stopB;
	private JButton fwB, bwB;
	private JButton loadB;
	
	private JFileChooser fileChooser;
	
	private boolean running;
	
	private JSlider currentPositionSlider;
	
	private LogWindow log;
	
	private JTable infoTable;
	
	private JLabel timeLabel;
	private JLabel resolLabel;
	private JLabel durationLabel;
	private JLabel numTiqLabel;
	private JLabel durTiqLabel;
	private JLabel durSemLabel;
	private JLabel numSemLabel;
	private JLabel andaLabel;
	private JLabel fileName;
	
	private MidiPlayer player;
	
	public GUI(){
		//DEFINE TÍTULO DA JANELA
		super("Introdução a Computação Sônica - Trabalho 1");		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		JPanel painel, centro, baixo, direita;
		
		painel = new JPanel();
		BorderLayout BL = new BorderLayout();
		painel.setLayout(BL);
		
		baixo = new JPanel();
		baixo.setLayout(new GridLayout(1, 6));
		
		centro = new JPanel();
		GridLayout GL2 = new GridLayout(10, 1);
		centro.setLayout(GL2);
		
		direita = new JPanel();
		direita.setLayout(new GridLayout(5, 2));
		
		
		running = false;
		
		//DEFINIÇÃO DE ÍCONES
		iconSize = new int[2];
		iconSize[0] = 30;
		iconSize[1] = 30;
		playI = createImageIcon("images/play/style1.png");
		pauseI = createImageIcon("images/pause/style1.png");
		stopI = createImageIcon("images/stop/style1.png");
		fwI = createImageIcon("images/forward/style1.png");
		bwI = createImageIcon("images/backward/style1.png");
		
		//CRIA E DEFINE BUTÕES
		playB = new JButton();
		playB.setIcon(playI);
		playB.addActionListener(this);
		playB.setActionCommand("play/pause");
		
		stopB = new JButton();
		stopB.setIcon(stopI);
		stopB.addActionListener(this);
		stopB.setActionCommand("stop");
		
		fwB = new JButton();
		fwB.setIcon(fwI);
		fwB.addActionListener(this);
		fwB.setActionCommand("forward");
		
		bwB = new JButton();
		bwB.setIcon(bwI);
		bwB.addActionListener(this);
		bwB.setActionCommand("backward");

		loadB = new JButton("load .midi");
		loadB.addActionListener(this);
		loadB.setActionCommand("loadFile");
		
		playB.setPreferredSize(getIconDimension(playB.getIcon()));
		stopB.setPreferredSize(getIconDimension(stopB.getIcon()));
		fwB.setPreferredSize(getIconDimension(fwB.getIcon()));
		bwB.setPreferredSize(getIconDimension(fwB.getIcon()));
		
		//CRIA JANELA DE LOG
		log = new LogWindow(30,  5);
		
		//CRIA E AJUSTA SLIDER DE TEMPO
		currentPositionSlider = new JSlider(JSlider.HORIZONTAL, 0, 100, 0);
		currentPositionSlider.addChangeListener(this);
		
		//CRIA E DEFINE LABELS
		timeLabel = new JLabel();
		resolLabel = new JLabel();
		resolLabel.setToolTipText("número de divisões da semínima");
		durationLabel = new JLabel();
		numTiqLabel = new JLabel();
		durTiqLabel = new JLabel();
		durSemLabel = new JLabel();
		numSemLabel = new JLabel();
		andaLabel = new JLabel();
		fileName = new JLabel();
		
		//inicializar escolhedor de arquivos na pasta atual
		
		fileChooser = new JFileChooser(".");
		
		setTimeLabel(0);
		setDurationLabel(31);
		setResolLabel(256);
		setNumTiqLabel(16380);
		setDurTiqLabel((float) 0.00189);
		setDurSemLabel((float) 0.48);
		setNumSemLabel(63);
		setAndaLabel(124);
		setFileName("ode_to_joy.mid");
		
		//ADICIONA BUTÕES
		baixo.add(playB);
		baixo.add(stopB);
		baixo.add(fwB);
		baixo.add(bwB);
		
		direita.add(loadB);
		direita.add(log);
		direita.add(currentPositionSlider);
		
		
		//ADICIONA LABELS
		centro.add(timeLabel);
		centro.add(resolLabel);
		centro.add(durationLabel);
		centro.add(numTiqLabel);
		centro.add(durTiqLabel);
		centro.add(resolLabel); 
		centro.add(durSemLabel);
		centro.add(numSemLabel);
		centro.add(andaLabel); 
		centro.add(fileName);
	
		
		painel.add(centro, BorderLayout.CENTER);
		painel.add(baixo, BorderLayout.PAGE_END);
		painel.add(direita, BorderLayout.EAST);
		add(painel);

	}
	

	public void setTimeLabel(int sec) {
		this.timeLabel.setText(sec + " s") ;
	}
	
	public void setDurationLabel(int sec) {
		this.durationLabel.setText("Tempo Total: " + sec + " s") ;
	}

	public void setResolLabel(int tiques) {
		this.resolLabel.setText("Resolução: " + tiques + " tiques");
	}

	public void setDurationLabel(String minSec) {
		this.durationLabel.setText("Duração: " + minSec);
	}

	public void setNumTiqLabel(int value) {
		this.numTiqLabel.setText("Número de Tiques: " + value);
	}

	public void setDurTiqLabel(float value) {
		this.durTiqLabel.setText("Duração do Tique: " + value + " s");
	}

	public void setDurSemLabel(float value) {
		this.durSemLabel.setText("Duração da Semínima: " + value + " s");
	}

	public void setNumSemLabel(int value) {
		this.numSemLabel.setText("Número de Semínimas: " + value);
	}

	public void setAndaLabel(int value) {
		this.andaLabel.setText("Andamento: " + value + " bpm");
	}

	public void setFileName(String fileName) {
		this.fileName.setText("Arquivo: " + fileName);
	}

	public void actionPerformed(ActionEvent E) {
		if("play/pause".equals(E.getActionCommand())){
		
			if(running == false){	
				running = true;
				playB.setIcon(pauseI);
			}
			else{
				running = false;
				playB.setIcon(playI);
			}
			}//end "play/pause"
			
		else if("stop".equals(E.getActionCommand())){
			running = false;
			playB.setIcon(playI);
		}//end "stop"
		
		else if("forward".equals(E.getActionCommand())){
			
		}//end "stop"
		else if("backward".equals(E.getActionCommand())){
		}//end "stop"
		else if("loadFile".equals(E.getActionCommand())){
			int returnVal = fileChooser.showOpenDialog(this);
			if (returnVal == JFileChooser.APPROVE_OPTION) {
	            File file = fileChooser.getSelectedFile();
	            //This is where a real application would open the file.
	            log.report("abrindo: " + file.getName() + ".");
	        } else {
	            log.report("Comando de abrir cancelado pelo usuário");
	        }
			
		}
		
	}
	protected ImageIcon createImageIcon(String path) {
	    java.net.URL imgURL = GUI.class.getResource(path);
	    ImageIcon icon = new ImageIcon(imgURL);
	    Image img = icon.getImage();
	    Image newImg = img.getScaledInstance(iconSize[0],iconSize[1], java.awt.Image.SCALE_SMOOTH);
	    return new ImageIcon(newImg);
	}

	public void stateChanged(ChangeEvent E) {
		JSlider src = (JSlider)E.getSource();
		int desiredPosition;
		desiredPosition = (int)src.getValue();
		if(!src.getValueIsAdjusting()){
			log.report("Value set to: "+ desiredPosition);
		}
		else{
			setTimeLabel(desiredPosition);
		}
	}
	private Dimension getIconDimension(Icon I){
		Dimension D= new Dimension(I.getIconWidth(), I.getIconHeight());
		return D;
	}
	

		
		
}
