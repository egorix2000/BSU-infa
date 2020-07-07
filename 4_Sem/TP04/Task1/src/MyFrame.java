import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.io.FileReader;
import java.io.IOException;

class MyFrame extends JFrame {

    public MyFrame() {
        SwingUtilities.invokeLater(() -> {
            setVisible(true);
            setSize(500, 500);
            MyFrame.this.setLocationRelativeTo(null);
            addComponentListener(new ComponentAdapter() {
                @Override
                public void componentHidden(ComponentEvent e) {
                    System.exit(0);
                }
            });
        });
    }
    
    @Override
    public JRootPane createRootPane() {
        JRootPane pane = new JRootPane();
        JPanel panel = new JPanel();
       
        panel.add(new ClockPanel());
        pane.setContentPane(panel);

        return pane;
    }
}