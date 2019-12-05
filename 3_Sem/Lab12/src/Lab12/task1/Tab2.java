package Lab12.task1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Tab2 extends JPanel implements MouseListener {
    private Color prevColor;
    private String prevName;
    private final int TABLE_DIMENSION = 4;
    private final int SIZE = 100;
    public Tab2() {
        setLayout(new GridLayout(TABLE_DIMENSION, TABLE_DIMENSION));
        for (int i = 0; i < TABLE_DIMENSION; i++)
            for (int j = 0; j < TABLE_DIMENSION; j++) {
                JButton bn = new JButton(i*TABLE_DIMENSION+j+1+"");
                bn.setSize(new Dimension(SIZE,SIZE));
                bn.addMouseListener(this);
                bn.setBackground(Color.PINK);
                add(bn);
            }
        setPreferredSize(new Dimension(SIZE*TABLE_DIMENSION, SIZE*TABLE_DIMENSION));
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {
        JButton temp = ((JButton) e.getSource());
        prevName = temp.getText();
        temp.setText("clicked!");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        JButton temp = ((JButton) e.getSource());
        temp.setText(prevName);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        JButton temp = ((JButton) e.getSource());
        prevColor = temp.getBackground();
        temp.setBackground(Color.YELLOW);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        JButton temp = ((JButton) e.getSource());
        temp.setBackground(prevColor);
    }
}