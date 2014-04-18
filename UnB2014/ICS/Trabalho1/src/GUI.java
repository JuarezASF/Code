import javax.swing.Icon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.JTable;
import javax.swing.JFileChooser;
import javax.swing.Timer;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JMenu;


import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
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
	private JLabel currentPosition;
	
	private LogWindow log;
	
	DefaultTableModel tableModel;
	private JScrollPane infoTablePane;
	private JTable infoTable;
	
	private Timer clock;
	private boolean mudancaInterna, mudancaExterna;
	
	private JMenuBar menuBar;
	private JMenu fileMenu;
	private JMenuItem loadMenuItem;
		
	
	private MidiPlayer player;
	
	public GUI(){
		//DEFINE TÍTULO DA JANELA
		super("Introdução a Computação Sônica - Trabalho 1");		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		JPanel painel, centro, baixo, direita;
		
		painel = new JPanel();
		painel.setLayout(new BorderLayout());
		
		baixo = new JPanel();
		baixo.setLayout(new GridLayout(1, 6));
		
		centro = new JPanel();
		centro.setLayout(new FlowLayout());
		
		direita = new JPanel();
		direita.setLayout(new GridLayout(5, 2));
		
		
		running = false;
		
		//DEFINIÇÃO DE ÍCONES
		iconSize = new int[2];
		iconSize[0] = 30;
		iconSize[1] = 30;
		
		String projectFolder = System.getProperty("user.dir");
		
		playI = createImageIcon(projectFolder + "/images/play/style1.png");
		pauseI = createImageIcon(projectFolder + "/images/pause/style1.png");
		stopI = createImageIcon(projectFolder + "/images/stop/style1.png");
		fwI = createImageIcon(projectFolder + "/images/forward/style1.png");
		bwI = createImageIcon(projectFolder + "/images/backward/style1.png");
		
		
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
		currentPosition = new JLabel("0");
		currentPositionSlider = new JSlider(JSlider.HORIZONTAL, 0, 100, 0);
		currentPositionSlider.addChangeListener(this);
		
		
		//inicializar escolhedor de arquivos na pasta atual
		
		fileChooser = new JFileChooser("./midi/" );
	
		
		String[] columnNames = {"Propriedade",
                "Valor", "unidade"};
		
		Object[][] data = {
			    {"Arquivo", "", ""},
			    {"Duração", "", "s"},
			    {"Resolução", "", "tiques"},
			    {"Número de tiques", "", ""},
			    {"Duração do Tique", "", "s"},
			    {"Duração da Semínima", "", "s"},
			    {"Total de Semínimas", "", ""},
			    {"Andamento", "", "bpm"},
			};
		
		tableModel = new DefaultTableModel(data, columnNames);
		JTable infoTable = new JTable(tableModel);
		infoTablePane = new JScrollPane(infoTable);
		infoTable.setFillsViewportHeight(true);
		infoTablePane.setPreferredSize(new Dimension(300, 500));
				
		clock = new Timer(1000, this);
		mudancaInterna = false;
		mudancaExterna = false;
		
		player = null;
		
		//DENIE MENU
		menuBar = new JMenuBar();
		fileMenu = new JMenu("File");
		loadMenuItem = new JMenuItem("Load Midi");
		loadMenuItem.setActionCommand("loadFile");
		loadMenuItem.addActionListener(this);
		
		menuBar.add(fileMenu);
		fileMenu.add(loadMenuItem);
		
		//ADICIONA BUTÕES
		baixo.add(playB);
		baixo.add(stopB);
		baixo.add(fwB);
		baixo.add(bwB);
		
		direita.add(log);
		direita.add(currentPositionSlider);
		direita.add(currentPosition);
		
		
		//ADICIONA LABELS
		centro.add(infoTablePane);
	
		
		painel.add(centro, BorderLayout.CENTER);
		painel.add(baixo, BorderLayout.PAGE_END);
		painel.add(direita, BorderLayout.EAST);
		
		painel.add(menuBar, BorderLayout.NORTH);
		
		add(painel);

		log.reportGood("Inicializando interface");
		

	}
	

	public void actionPerformed(ActionEvent E) {
		
		String action = E.getActionCommand();
		if("play/pause".equals(action)){
		
			if(running == false)	
				play();
			else
				pause();
		}//end "play/pause"
			
		else if("stop".equals(action)){
				stop();
		}//end "stop"
		
		else if("forward".equals(action)){
			
		}//end "stop"
		else if("backward".equals(action)){
		}//end "stop"
		else if("loadFile".equals(action)){
			int returnVal = fileChooser.showOpenDialog(this);
			if (returnVal == JFileChooser.APPROVE_OPTION) {
				if(player != null){
					player.stop();
				}
				
				File file = fileChooser.getSelectedFile();
	            //mostra mensagem no log
				log.report("abrindo: " + file.getName() + ".");
	            player = new MidiPlayer(file.getAbsolutePath());
				stop();
	      
	            //mostra dados na tabela de dados
	            currentPositionSlider.setMaximum((int)player.getDuracao());
	            getData();
	            
	            play();
	        } else {
	            log.reportWarning("Comando de abrir cancelado pelo usuário");
	        }
			
		}
		else if(E.getSource() == clock){
			mudancaInterna = true;
			currentPositionSlider.setValue((int)player.getTime());
		}
		
	}
	protected ImageIcon createImageIcon(String path) {
	    ImageIcon icon = new ImageIcon(path);
	    Image img = icon.getImage();
	    Image newImg = img.getScaledInstance(iconSize[0],iconSize[1], java.awt.Image.SCALE_SMOOTH);
	    return new ImageIcon(newImg);
	}

	public void stateChanged(ChangeEvent E) {
		JSlider src = (JSlider)E.getSource();
		int desiredPosition;
		desiredPosition = (int)src.getValue();
		if(!src.getValueIsAdjusting()){
			if(mudancaInterna == true && mudancaExterna == false){
				currentPosition.setText("" + desiredPosition + "s");
				mudancaInterna = false;
			}
			else{
				goTo(desiredPosition);
			}
		}
		else{
			mudancaExterna = true;
			currentPosition.setText("" + desiredPosition + "s");
		}
	}
	private Dimension getIconDimension(Icon I){
		Dimension D= new Dimension(I.getIconWidth(), I.getIconHeight());
		return D;
	}
	
	private void getData(){
		tableModel.setValueAt(player.getFileName(), 0, 1);
		tableModel.setValueAt(player.getDuracao(), 1, 1);
		tableModel.setValueAt(player.getResolucao(), 2, 1);
		tableModel.setValueAt(player.getTotaltiques(), 3, 1);
		tableModel.setValueAt(player.getDuracaoTique(), 4, 1);
		tableModel.setValueAt(player.getDurSeminima(), 5, 1);
		tableModel.setValueAt(player.getTotalSeminimas(), 6, 1);
		tableModel.setValueAt(Math.round(player.getBpm()), 7, 1);
	}
	
	private void play(){
        //muda para estado de 'playing'
		if(player == null){ return;}
        running = true;
		playB.setIcon(pauseI);
        player.play();
		clock.start();
	
	}

	private void pause(){
		if(player == null){ return;}
		running = false;
		playB.setIcon(playI);
		player.pause();
		clock.stop();

	}
	
	private void stop(){
		if(player == null){ return;}
		running = false;
		playB.setIcon(playI);
		
		player.stop();
		clock.stop();
		
		mudancaInterna = true;
		currentPositionSlider.setValue(0);

	}
	
	private void goTo(int desiredPosition){
		if(player == null){ return;}
		player.goTo(desiredPosition);
		mudancaExterna = false;
		log.report("Time set to: "+ desiredPosition + " s");
	}
}
