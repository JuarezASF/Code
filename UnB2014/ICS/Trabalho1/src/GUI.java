import javax.sound.midi.InvalidMidiDataException;
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
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

public class GUI extends JFrame
implements ActionListener, ChangeListener{
	
	private ImageIcon playI, pauseI, stopI, fastI, slowI;
	private int iconSize[];
	
	private JButton playB, fastB, slowB;
	private JButton stopB;
	
	private JFileChooser fileChooser, sfChooser;
	
	private boolean running;
	
	private JSlider currentPositionSlider;
	private JLabel currentPosition;

	private JSlider volumeAtualSlider;
	private JLabel volumeAtualLabel;
	
	private LogWindow log;
	
	DefaultTableModel tableModel;
	private JScrollPane infoTablePane;
	private JTable infoTable;
	
	private Timer clock;
	private boolean mudancaInterna, mudancaExterna;
	
	private JMenuBar menuBar;
	private JMenu fileMenu;
	private JMenuItem loadMenuItem, loadSBItem;
	
		
	
	private MidiPlayer player;
	
	public GUI(){
		//DEFINE TÃ�TULO DA JANELA
		super("Introduçãoo a Computaçãoo Sônica - Trabalho 1");		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		myBGPanel painel;
		JPanel  centro, baixo, direita;
		
		ImageIcon icon = new ImageIcon("/home/juarez408/Documents/images/Ubunto7.png");
		
		painel = new myBGPanel(icon.getImage());
		painel.setLayout(new BorderLayout());
		
		baixo = new JPanel();
		baixo.setLayout(new GridLayout(1, 6));
		baixo.setOpaque(false);
		
		centro = new JPanel();
		centro.setLayout(new GridLayout(2, 1));
		centro.setOpaque(false);
		
		direita = new JPanel();
		direita.setLayout(new GridLayout(10, 3));
		direita.setOpaque(false);
		
		
		running = false;
		
		//DEFINIÃ‡ÃƒO DE Ã�CONES
		iconSize = new int[2];
		iconSize[0] = 30;
		iconSize[1] = 30;
		
		String projectFolder = System.getProperty("user.dir");
		playI = createImageIcon(projectFolder + "/Icons/play.png");
		pauseI = createImageIcon(projectFolder + "/Icons/pause.png");
		stopI = createImageIcon(projectFolder + "/Icons/stop.png");
		fastI = createImageIcon(projectFolder + "/Icons/fast.png");
		slowI = createImageIcon(projectFolder + "/Icons/slow.png");
		
		
		
		//CRIA E DEFINE BUTÃ•ES
		playB = new JButton();
		playB.setIcon(playI);
		playB.addActionListener(this);
		playB.setActionCommand("play/pause");
		
		stopB = new JButton();
		stopB.setIcon(stopI);
		stopB.addActionListener(this);
		stopB.setActionCommand("stop");

		fastB = new JButton();
		fastB.setIcon(fastI);
		fastB.addActionListener(this);
		fastB.setActionCommand("fast");
		fastB.setToolTipText("Multiplica andamento por 3/2");

		slowB = new JButton();
		slowB.setIcon(slowI);
		slowB.addActionListener(this);
		slowB.setActionCommand("slow");
		slowB.setToolTipText("Multiplica andamento por 2/3");
		
		
		playB.setPreferredSize(getIconDimension(playB.getIcon()));
		stopB.setPreferredSize(getIconDimension(stopB.getIcon()));
		
		//CRIA JANELA DE LOG
		log = new LogWindow(30,  5);
		
		//CRIA E AJUSTA SLIDER DE TEMPO e de volume
		currentPosition = new JLabel("0");
		currentPositionSlider = new JSlider(JSlider.HORIZONTAL, 0, 100, 0);
		currentPositionSlider.addChangeListener(this);
		

		volumeAtualLabel = new JLabel("75");
		volumeAtualSlider = new JSlider(JSlider.HORIZONTAL, 0, 127, 75);
		//usamos 7 bits para o volume, entÃ£o o mÃ¡ximo Ã© 127
		volumeAtualSlider.addChangeListener(this);

		
		//inicializar escolhedor de arquivos na pasta atual
		
		fileChooser = new JFileChooser("./midi/" );
		sfChooser = new JFileChooser("." );
		
		String[] columnNames = {"Propriedade",
                "Valor", "unidade"};
		
		Object[][] data = {
			    {"Arquivo", "", ""},
			    {"Duração", "", "s"},
			    {"Resoluçãoo", "", "tiques"},
			    {"Número de tiques", "", ""},
			    {"Duraçãoo do Tique", "", "s"},
			    {"Duraçãoo da Semínima", "", "s"},
			    {"Total de Semínimas", "", ""},
			    {"Andamento", "", "bpm"},
			    {"Tonalidade", "", ""},
			    {"Fórmula de Compasso", "", ""}
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
		
		//FILE MENU
		menuBar = new JMenuBar();
		fileMenu = new JMenu("File");
		loadMenuItem = new JMenuItem("Load MIDI");
		loadMenuItem.setActionCommand("loadFile");
		loadMenuItem.addActionListener(this);
		loadSBItem = new JMenuItem("Load SF");
		loadSBItem.setActionCommand("loadSF");
		loadSBItem.addActionListener(this);
		
		JMenuItem infoButton = new JMenuItem("Info");
		infoButton.setActionCommand("infoButton");
		infoButton.addActionListener(this);
		
		menuBar.add(fileMenu);
		menuBar.add(infoButton);
		fileMenu.add(loadMenuItem);
		fileMenu.add(loadSBItem);
		
		
		//ADICIONA BUTÃ•ES
		baixo.add(playB);
		baixo.add(stopB);
		baixo.add(fastB);
		baixo.add(slowB);
		
		JLabel timerLabel = new JLabel("Tempo");
		JLabel volumeLabel = new JLabel("Volume");

		direita.add(timerLabel);
		direita.add(currentPositionSlider);
		direita.add(currentPosition);
		direita.add(volumeLabel);
		direita.add(volumeAtualSlider);
		direita.add(volumeAtualLabel);
		
		
		
		//ADICIONA LABELS
		centro.add(infoTablePane);
		centro.add(log);	
		
		painel.add(centro, BorderLayout.CENTER);
		painel.add(baixo, BorderLayout.PAGE_END);
		painel.add(direita, BorderLayout.EAST);
		
		painel.add(menuBar, BorderLayout.NORTH);
		
		add(painel);

		log.reportGood("Inicializando interface");
		

	}
	

	public void actionPerformed(ActionEvent E) {
		
		String action = E.getActionCommand();
		
		try{
		
		if("play/pause".equals(action)){
		
			if(running == false)	
				play();
			else
				pause();
		}//end "play/pause"
			
		else if("stop".equals(action)){
				stop();
		}//end "stop"
		
		else if("fast".equals(action)){
			float andamento_atual = player.getBpm();
			float novo_andamento = andamento_atual*1.5f;
			player.setAndamento((int) novo_andamento);
			log.report("Multiplicando andamento por 1.5");
			getData();
			}//end "fast"
		else if("slow".equals(action)){
			float andamento_atual = player.getBpm();
			float novo_andamento = andamento_atual*0.66666f;
			player.setAndamento((int) novo_andamento);
			log.report("Multiplicando andamento por 0.666");
			getData();
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
	      
	            getData();
	            
	            play();
	        } else {
	            log.reportWarning("Comando de abrir cancelado pelo usuÃ¡rio");
	        }
			
		}
		else if(E.getSource() == clock){
			mudancaInterna = true;
			currentPositionSlider.setValue((int)player.getTime());
		}
		else if("loadSF".equals(action)){
			int returnVal = sfChooser.showOpenDialog(this);
			if (returnVal == JFileChooser.APPROVE_OPTION) {
				if(player != null){
					player.pause();
				}
				
				File file = sfChooser.getSelectedFile();
	            //mostra mensagem no log
				log.report("abrindo SF em: " + file.getName() + ".");
	            player.loadSF(file.getAbsolutePath());
				play();
	        } else {
	            log.reportWarning("Comando de carregar SF cancelado pelo usuário");
	        }
			
		}
		}
		catch(InvalidMidiDataException exce){
			//todo 
		}
		
	}
	protected ImageIcon createImageIcon(String path) {
	    ImageIcon icon = new ImageIcon(path);
	    Image img = icon.getImage();
	    Image newImg = img.getScaledInstance(iconSize[0],iconSize[1], java.awt.Image.SCALE_SMOOTH);
	    return new ImageIcon(newImg);
	}

	public void stateChanged(ChangeEvent E) {
		if(player == null)
			return;
		if(E.getSource() == currentPositionSlider){
			JSlider src = (JSlider)E.getSource();
			int desiredPosition;
			desiredPosition = (int)src.getValue();
			if(!src.getValueIsAdjusting()){
				if(mudancaInterna == true && mudancaExterna == false){
					currentPosition.setText(seg2HHmmss(desiredPosition));
					mudancaInterna = false;
				}
				else{
					goTo(desiredPosition);
				}
			}
			else{
				mudancaExterna = true;
				currentPosition.setText(seg2HHmmss(desiredPosition));
			}
		}
		else if(E.getSource() == volumeAtualSlider){
			JSlider src = (JSlider)E.getSource();
			int desiredPosition;
			desiredPosition = (int)src.getValue();
			if(!src.getValueIsAdjusting()){
				setVolume(desiredPosition);
			}
			else{}
		}//fim if VolumeAtualSlider
		}
	private Dimension getIconDimension(Icon I){
		Dimension D= new Dimension(I.getIconWidth(), I.getIconHeight());
		return D;
	}
	
	private void getData(){
		
		tableModel.setValueAt(player.getFileName(), 0, 1);
		tableModel.setValueAt(seg2HHmmss(player.getDuracao()), 1, 1);
		tableModel.setValueAt(player.getResolucao(), 2, 1);
		tableModel.setValueAt(player.getTotaltiques(), 3, 1);
		tableModel.setValueAt(player.getDuracaoTique(), 4, 1);
		tableModel.setValueAt(player.getDurSeminima(), 5, 1);
		tableModel.setValueAt(player.getTotalSeminimas(), 6, 1);
		tableModel.setValueAt(Math.round(player.getBpm()), 7, 1);
		tableModel.setValueAt(player.getTonalidade(), 8, 1);
		tableModel.setValueAt(player.getFormulaDeCompasso(), 9, 1);
		
        //altera posiÃ§Ã£o mÃ¡xima do cursor de tempo
        currentPositionSlider.setMaximum((int)player.getDuracao());
        
        setVolume(75);
			
		}
	
	private void setVolume(int value){
		player.setVolume(value);
		DecimalFormat df = new DecimalFormat("#.00"); 
		volumeAtualLabel.setText("" + df.format(100.0*value/127.0) + "%");
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
		currentPosition.setText(seg2HHmmss(desiredPosition));
		mudancaExterna = false;
		log.report("Time set to: "+ seg2HHmmss(desiredPosition));
	}
	
	public String seg2HHmmss(long seg){
		long dur_mili = seg*1000;
		 TimeZone tz = TimeZone.getTimeZone("UTC");
		 SimpleDateFormat df = new SimpleDateFormat("HH:mm:ss");
		 df.setTimeZone(tz);
		 
		 //converte a data recebendo parÃ¢metros em segundos
		 String time = df.format(new Date(dur_mili));
		 return time;
	}
}
