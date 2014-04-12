import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.text.DefaultCaret;


public class LogWindow extends JScrollPane{
	private JTextArea logArea;
	
	public LogWindow(int width, int height){
		logArea = new JTextArea(height, width);
		DefaultCaret caret = (DefaultCaret)logArea.getCaret();
		caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);
		this.setViewportView(logArea);
	}
	
	public void report(String msg){
		logArea.append(msg.concat("\n"));
	}
	

}
