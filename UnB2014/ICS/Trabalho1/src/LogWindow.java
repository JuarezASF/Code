import java.awt.Color;

import javax.swing.JScrollPane;
import javax.swing.JTextPane;
import javax.swing.text.DefaultCaret;
import javax.swing.text.StyleContext;
import javax.swing.text.AttributeSet;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;


public class LogWindow extends JScrollPane{
	private JTextPane logArea;
	
	
	public LogWindow(int width, int height){
		logArea = new JTextPane();
		DefaultCaret caret = (DefaultCaret)logArea.getCaret();
		caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);
		this.setViewportView(logArea);
	}
	
	public void report(String msg){
		append(msg + "\n", Color.BLACK);
	}

	public void reportGood(String msg){
		append(msg + "\n", Color.GREEN);	}
	
	public void reportBad(String msg){
		append(msg + "\n", Color.RED);	}
	
	public void reportWarning(String msg){
		append(msg + "\n", Color.YELLOW);
	}
	
    private void append(String msg, Color c)
    {
        StyleContext sc = StyleContext.getDefaultStyleContext();
        AttributeSet aset = sc.addAttribute(SimpleAttributeSet.EMPTY, StyleConstants.Foreground, c);

        aset = sc.addAttribute(aset, StyleConstants.FontFamily, "Lucida Console");
        aset = sc.addAttribute(aset, StyleConstants.Alignment, StyleConstants.ALIGN_JUSTIFIED);

        int len = logArea.getDocument().getLength();
        logArea.setCaretPosition(len);
        logArea.setCharacterAttributes(aset, false);
        logArea.replaceSelection(msg);
    }

}
