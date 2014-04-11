import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;


import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;



public class GUI extends JFrame
implements ActionListener{

	private JButton playB;
	private JButton stopB;
	private JButton forwardB, backwardB;
	private boolean running;
	
	JTextArea logArea;
	private JScrollPane logPane;
	
	
	public GUI(){
		super("Introdução a Computação Sônica - Trabalho 1");
		setLayout(new FlowLayout());
		
		running = false;
		
		playB = new JButton("play");
		playB.addActionListener(this);
		playB.setActionCommand("play/pause");
		
		
		stopB = new JButton("stop");
		stopB.addActionListener(this);
		stopB.setActionCommand("stop");
		
		forwardB = new JButton(">>");
		forwardB.addActionListener(this);
		forwardB.setActionCommand("forward");
		
		backwardB = new JButton("<<");
		backwardB.addActionListener(this);
		backwardB.setActionCommand("backward");
		
		add(playB);
		add(stopB);
		add(forwardB);
		add(backwardB);
		
		logArea = new JTextArea(5, 30);
		logPane = new JScrollPane(logArea);
		logArea.append("linha 1\n");
		logArea.append("linha 2\n");
		logArea.append("linha 3\n");
		logArea.append("linha 4\n");
		logArea.append("linha 5\n");
		logArea.append("linha 6\n");
		
		
		add(logPane);
	}
	


	public void actionPerformed(ActionEvent E) {
		if("play/pause".equals(E.getActionCommand())){
		
			if(running == false){	
				running = true;
				playB.setText("Pause");
			}
			else{
				running = false;
				playB.setText("Play");
			}
			}//end "play/pause"
			
		else if("stop".equals(E.getActionCommand())){
			running = false;
		}//end "stop"
		
		else if("forward".equals(E.getActionCommand())){
			
		}//end "stop"
		else if("backward".equals(E.getActionCommand())){
			
		}//end "stop"
		
	}
		
		
}
