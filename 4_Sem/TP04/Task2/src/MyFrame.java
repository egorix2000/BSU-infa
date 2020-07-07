import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;

class MyFrame extends JFrame {

    public MyFrame() {
        SwingUtilities.invokeLater(() -> {
            setVisible(true);
            setSize(600, 600);
            MyFrame.this.setLocationRelativeTo(null);
            addComponentListener(new ComponentAdapter() {
                @Override
                public void componentHidden(ComponentEvent e) {
                    System.exit(0);
                }
            });
        });
    }

    private static final int MIN_SPEED = 3;
    private static final int MAX_SPEED = 15;

    private JSlider slider;
    private JComboBox<String> comboBox;
    private AlienPanel alien;


    @Override
    public JRootPane createRootPane() {
        JRootPane pane = new JRootPane();
        JPanel panel = new JPanel();
        alien = new AlienPanel(MIN_SPEED);

        comboBox = new JComboBox<>(new String[]{"Right", "Left"});

        slider = new JSlider(JSlider.HORIZONTAL, MIN_SPEED, MAX_SPEED, MIN_SPEED);
        slider.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
            	alien.setSpeed(slider.getValue());
            }
        });
        
        comboBox.addActionListener(e -> {
            String item = (String) comboBox.getSelectedItem();
            alien.setDirection("Right".equals(item) ? 1 : -1);
        });
        panel.setLayout(new BorderLayout());
        panel.add(slider, BorderLayout.NORTH);
        panel.add(comboBox, BorderLayout.SOUTH);
        panel.add(alien, BorderLayout.CENTER);
        
        pane.setContentPane(panel);

        return pane;
    }
}