package Lab12.task1;

import javax.swing.*;
import java.awt.*;
import java.util.Vector;

public class Tab1 extends JPanel {
    private final String[] DATA_1 = { "Mercury", "Venus", "Earth", "Mars", "Saturn" };
    private final String[] DATA_2 = { "Bear", "Ostrich", "Dog", "Frog", "Giraffe", "Hawk", "Jackal", "Hornets" };
    private DefaultListModel<String> leftListModel;
    private DefaultListModel<String> rightListModel;
    private JList<String> rightList;
    private JList<String> leftList;
    private JPanel central;
    private JButton topButton;
    private JButton bottomButton;


    public Tab1() {
        setLayout(new BorderLayout());
        central = new JPanel();
        central.setLayout(new BorderLayout());
        
        leftListModel = new DefaultListModel<String>();
        for (String el : DATA_1) {
        	leftListModel.addElement(el);
        }
        
        leftList = new JList<String>(leftListModel);
        leftList.setPreferredSize(new Dimension(60,500));
        
        rightListModel = new DefaultListModel<String>();
        for (String el : DATA_2) {
            rightListModel.addElement(el);
        }
        rightList = new JList<String>(rightListModel);
        rightList.setPreferredSize(new Dimension(60,500));
        
        add(leftList, BorderLayout.WEST);
        add(new JScrollPane(leftList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.WEST);
        add(rightList, BorderLayout.EAST);
        add(new JScrollPane(rightList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.EAST);
        
        topButton  = new JButton("<");
        topButton.setSize(70,70);
        topButton.addActionListener(e -> {
            if (!rightList.isSelectionEmpty()) {
            	for (String el : rightList.getSelectedValuesList()) {
            		leftListModel.addElement(el);
                    rightListModel.removeElement(el);
            	}
            }
        });
        
        central.add(topButton, BorderLayout.NORTH);
        
        bottomButton = new JButton(">");
        bottomButton.setSize(70,70);
        bottomButton.addActionListener(e -> {
            if (!leftList.isSelectionEmpty()) {
            	for (String el : leftList.getSelectedValuesList()) {
            		rightListModel.addElement(el);
            		leftListModel.removeElement(el);
            	}
            }
        });
        central.add(bottomButton, BorderLayout.SOUTH);
        this.add(central, BorderLayout.CENTER);
        setVisible(true);
    }


}