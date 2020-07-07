import javax.swing.*;
import java.awt.*;

public class ClockPanel extends JPanel {

    private int radius;
    private int margin;
    private int angle;

    public ClockPanel() {
        angle = 0;
        radius = 225;
        margin = 5;
        setPreferredSize(new Dimension(2*radius + 2*margin, 2*radius + 2*margin));
        Timer timer = new Timer(1000, e -> {
            repaint();
            angle += 6;
            if (angle >= 360) {
                angle = 0;
            }
        });
        timer.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
    	super.paintComponent(g);
        
        int x2 = margin + radius - (int) (radius * Math.sin(-Math.toRadians(angle)));
        int y2 = margin + radius - (int) (radius * Math.cos(-Math.toRadians(angle)));
        g.drawLine(margin + radius, margin + radius, x2, y2);
        g.drawOval(margin, margin, radius*2, radius*2);
    }

}
