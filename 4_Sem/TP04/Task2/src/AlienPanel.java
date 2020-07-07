import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.image.BufferedImage;
import java.io.File;

public class AlienPanel extends JPanel implements ComponentListener{
    private int radius;
    private int angle;
    private BufferedImage image;
    private int speed;
    private int direction;

    public AlienPanel(int initSpeed) {
        super();
        angle = 0;
        direction = 1;
        speed = initSpeed;
        try {
            image = ImageIO.read(new File("//Users//apple//Downloads//eclipse-workspace//tp12//images//startImage.jpg"));
        }catch (Exception ex){
            System.out.println(ex.getMessage());
        }
        radius = 225;
        int delay = 100;
        ActionListener taskPerformer = evt -> {
            angle += direction * (int)(speed * 1000 / (2 * Math.PI * radius)); 
            repaint();
        };
        Timer timer = new Timer(delay, taskPerformer);
        timer.start();
        this.addComponentListener(this);
    }

	@Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        int xImage = radius - image.getWidth() / 2 - 
          		(int) ((radius - image.getWidth() / 2) * Math.sin(-Math.toRadians(angle)));
        int yImage = radius - image.getHeight() / 2 - 
           		(int) ((radius - image.getHeight() / 2) * Math.cos(-Math.toRadians(angle)));
        g.drawImage(image, xImage, yImage, null);
        
    }

	@Override
	public void componentResized(ComponentEvent e) {
		radius = Math.min(this.getWidth(), this.getHeight()) / 2;
		//repaint();
	}

	@Override
	public void componentMoved(ComponentEvent e) {
		// TODO Auto-generated method stub
	}

	@Override
	public void componentShown(ComponentEvent e) {
		// TODO Auto-generated method stub
	}

	@Override
	public void componentHidden(ComponentEvent e) {
		// TODO Auto-generated method stub
		
	}
	
	public void setSpeed(int speed) {
		this.speed = speed;
	}
	
	public void setDirection(int direction) {
		this.direction = direction;
	}
}
