import java.awt.Graphics;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;


class BGPanel extends JPanel {
    private Image bg;
    private boolean set;
    
    public BGPanel(){
    	set = false;
    }
    
    public void setBG(String path){
    	bg = new ImageIcon("water.jpg").getImage();
    	set = true;
    }
    
    public void paintComponent(Graphics g) 
    {
    	if(set == true)
        g.drawImage(bg, 0, 0, getWidth(), getHeight(), this);
    
    }
}
