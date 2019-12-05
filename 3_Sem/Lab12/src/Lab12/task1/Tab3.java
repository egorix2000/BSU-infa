package Lab12.task1;

import javax.swing.*;
import java.awt.*;

public class Tab3 extends JPanel {
	private final int BUTTONS_COUNT = 10;
	
    public Tab3(){
    	setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        ButtonGroup radioGroup = new ButtonGroup();
        for(int i = 0; i < BUTTONS_COUNT; i++){
            JRadioButton btn = new JRadioButton("State " + i);
            btn.setIcon(new ImageIcon("images/TRex.png"));
            btn.setPressedIcon(new ImageIcon("images/dolphin.png"));
            btn.setRolloverIcon(new ImageIcon("images/crown.png"));
            btn.setSelectedIcon(new ImageIcon("images/plant.png"));
            radioGroup.add(btn);
            add(btn);
        }
    }
}