
import org.xml.sax.SAXException;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.xml.parsers.ParserConfigurationException;

public class DrinkFrame extends JFrame implements ActionListener {
    private List<Drink> drinkList;
    private JPanel contentPane;
    private JMenuBar menuBar;
    private JMenu menuFile;
    private JMenu menuData;
    private JMenuItem openFileItem;
    private JMenuItem displaySortedDataItem;
    private JMenuItem displayDrinkNamesItem;
    private JMenuItem displayMapItem;
    private JMenuItem findThreeMostExpensiveItem;

    private JTabbedPane tabbedPane;

    private DefaultListModel<String> originalDrinksListModel;
    private JList<String> originalDrinkList;
    private JScrollPane originalDrinkListScrollPane;

    private DefaultListModel<String> sortedDrinkListModel;
    private JList<String> sortedDrinkList;
    private JScrollPane sortedDrinkListScrollPane;

    private DefaultListModel<String> drinkNamesListModel;
    private JList<String> drinkNamesList;
    private JScrollPane drinkNamesListScrollPane;

    private DefaultListModel<String> mapListModel;
    private JList<String> mapList;
    private JScrollPane mapListScrollPane;

    private final String CURRENT_DIRECTORY = "/Users/apple/Downloads";

    public static void main(String[] args) {
        DrinkFrame frame = new DrinkFrame();
        frame.setVisible(true);
    }

    public DrinkFrame() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        contentPane.setLayout(new BorderLayout(0, 0));

        menuBar = new JMenuBar();

        menuFile = new JMenu("File");
        menuBar.add(menuFile);

        openFileItem = new JMenuItem("Open");
        openFileItem.addActionListener(this);
        menuFile.add(openFileItem);

        menuData = new JMenu("Data");
        menuBar.add(menuData);

        displaySortedDataItem = new JMenuItem("Sorted data");
        displaySortedDataItem.addActionListener(this);
        menuData.add(displaySortedDataItem);

        displayDrinkNamesItem = new JMenuItem("Drink names");
        displayDrinkNamesItem.addActionListener(this);
        menuData.add(displayDrinkNamesItem);

        displayMapItem = new JMenuItem("Map");
        displayMapItem.addActionListener(this);
        menuData.add(displayMapItem);

        findThreeMostExpensiveItem = new JMenuItem("Most expensive");
        findThreeMostExpensiveItem.addActionListener(this);
        menuData.add(findThreeMostExpensiveItem);

        contentPane.add(menuBar, BorderLayout.NORTH);


        originalDrinksListModel = new DefaultListModel<>();
        originalDrinkList = new JList<>(originalDrinksListModel);
        originalDrinkList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        originalDrinkList.setLayoutOrientation(JList.VERTICAL);
        originalDrinkListScrollPane = new JScrollPane(originalDrinkList);

        sortedDrinkListModel = new DefaultListModel<>();
        sortedDrinkList = new JList<>(sortedDrinkListModel);
        sortedDrinkList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        sortedDrinkList.setLayoutOrientation(JList.VERTICAL);
        sortedDrinkListScrollPane = new JScrollPane(sortedDrinkList);

        drinkNamesListModel = new DefaultListModel<>();
        drinkNamesList = new JList<>(drinkNamesListModel);
        drinkNamesList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        drinkNamesList.setLayoutOrientation(JList.VERTICAL);
        drinkNamesListScrollPane = new JScrollPane(drinkNamesList);

        mapListModel = new DefaultListModel<>();
        mapList = new JList<>(mapListModel);
        mapList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        mapList.setLayoutOrientation(JList.VERTICAL);
        mapListScrollPane = new JScrollPane(mapList);

        tabbedPane = new JTabbedPane();
        tabbedPane.add("Collection", originalDrinkListScrollPane);
        tabbedPane.add("Sorted", sortedDrinkListScrollPane);
        tabbedPane.add("Drinks", drinkNamesListScrollPane);
        tabbedPane.add("Map", mapListScrollPane);
        contentPane.add(tabbedPane, BorderLayout.CENTER);

        setContentPane(contentPane);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            if(e.getSource() == openFileItem) {
                JFileChooser chooser = new JFileChooser();
                chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
                chooser.setCurrentDirectory(new File(CURRENT_DIRECTORY));
                if(chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
                    originalDrinksListModel.clear();
                    drinkList = Reader.readXML(chooser.getSelectedFile());
                    for (int i = 0; i < drinkList.size(); i++) {
                        originalDrinksListModel.addElement(drinkList.get(i).toString());
                    }
                    tabbedPane.setSelectedIndex(0);
                }
            } else if (e.getSource() == displaySortedDataItem) {
                tabbedPane.setSelectedIndex(1);
                sortedDrinkListModel.clear();
                List<Drink> tempSorted = new ArrayList<>(drinkList);
                Collections.sort(tempSorted);
                Iterator<Drink> iterator = tempSorted.iterator();
                while(iterator.hasNext()) {
                    Drink d = iterator.next();
                    sortedDrinkListModel.addElement(d.toString());
                }
            } else if (e.getSource() == displayDrinkNamesItem) {
                tabbedPane.setSelectedIndex(2);
                drinkNamesListModel.clear();
                TreeSet<String> tempTree = drinkList.stream().map(Drink::getName).
                        collect(Collectors.toCollection(()->new TreeSet<>(
                                (String n1, String n2) -> n2.compareTo(n1))));
                Iterator<String> iterator = tempTree.iterator();
                while(iterator.hasNext()) {
                    drinkNamesListModel.addElement(iterator.next());
                }
            } else if (e.getSource() == displayMapItem) {
                tabbedPane.setSelectedIndex(3);
                mapListModel.clear();

                mapListModel.clear();
                if(drinkList.get(0) instanceof Coffee) {
                    Map<CoffeeType, Double> mapTemp = drinkList.stream().collect(Collectors.groupingBy(b -> ((Coffee)b).getType(),
                            Collectors.averagingDouble(b -> b.getCaffeineQuantity())));
                    for (Map.Entry<CoffeeType, Double> entry : mapTemp.entrySet()) {
                        StringBuffer sb = new StringBuffer(entry.getKey().toString());
                        sb.append(" average caffeine: ");
                        sb.append(entry.getValue());
                        mapListModel.addElement(sb.toString());
                    }
                } else {
                    Map<TeaType, Double> mapTemp = drinkList.stream().collect(Collectors.groupingBy(b -> ((Tea)b).getType(),
                            Collectors.averagingDouble(b -> b.getCaffeineQuantity())));
                    for (Map.Entry<TeaType, Double> entry : mapTemp.entrySet()) {
                        StringBuffer sb = new StringBuffer(entry.getKey().toString());
                        sb.append(" average caffeine: ");
                        sb.append(entry.getValue());
                        mapListModel.addElement(sb.toString());
                    }
                }
            } else if (e.getSource() == findThreeMostExpensiveItem) {
                JOptionPane.showMessageDialog(null, originalDrinksListModel.elementAt(0));
            }
        } catch(SAXException | ParserConfigurationException | IOException ex) {
            JOptionPane.showMessageDialog(null, "File issue: " + ex.getMessage());
        } catch(NoSuchElementException ex) {
            JOptionPane.showMessageDialog(null, "Incomplete data about drink");
        } catch(NullPointerException ex) {
            JOptionPane.showMessageDialog(null, "Empty data about drink");
        } catch(NumberFormatException ex) {
            JOptionPane.showMessageDialog(null, "Wrong data format");
        }
    }

}