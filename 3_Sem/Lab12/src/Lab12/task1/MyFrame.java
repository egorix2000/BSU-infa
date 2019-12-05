package Lab12.task1;

import javax.swing.*;

import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.awt.event.KeyEvent;

public class MyFrame extends JFrame {
    JTabbedPane tabbedPane;

    public static void main(String[] args) {
    	EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MyFrame frame = new MyFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
    public MyFrame() {
        setSize(450, 480);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    protected JRootPane createRootPane() {
        JRootPane pane = new JRootPane();
        JPanel panel = new JPanel();
        pane.setContentPane(panel);
        tabbedPane = new JTabbedPane();
        tabbedPane.addTab("Tab1", new Tab1());
        tabbedPane.addTab("Tab2", new Tab2());
        tabbedPane.addTab("Tab3", new Tab3());

        panel.add(tabbedPane);
        return pane;
    }
}
