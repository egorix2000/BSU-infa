import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class MyPanel extends JFrame {

    public MyPanel() {
        SwingUtilities.invokeLater(() -> {
            setVisible(true);
            setSize(700, 500);
            MyPanel.this.setLocationRelativeTo(null);
            addComponentListener(new ComponentAdapter() {
                @Override
                public void componentHidden(ComponentEvent e) {
                    System.exit(0);
                }
            });
        });
    }

    private List<Country> countries;
    private JFileChooser chooser = new JFileChooser();
    private SecondTab secondTask;
    private FirstTab firstPanel;
    private Map<String, String> capitalsMap;

    @Override
    public JRootPane createRootPane() {
        JRootPane pane = new JRootPane();
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        countries = new ArrayList<>();
        initialMap();
        fillCountries();
        JTabbedPane tabbedPane = createTabbedPane();
        panel.add(tabbedPane, BorderLayout.CENTER);
        pane.setContentPane(panel);
        
        return pane;
    }

    private JTabbedPane createTabbedPane() {
        JTabbedPane tabbedPane = new JTabbedPane();
        firstPanel = new FirstTab(countries);
        secondTask = new SecondTab(countries);
        tabbedPane.addTab("FirstTab", firstPanel);
        tabbedPane.addTab("SecondTab", secondTask);
        return tabbedPane;
    }

    private void initialMap() {
    	capitalsMap = new TreeMap<>();
        try (Scanner sc = new Scanner(new File("//Users//apple//Downloads//eclipse-workspace//TP03//src//input.txt"))) {
            while (sc.hasNext()) {
            	capitalsMap.put(sc.next(), sc.next());
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void fillCountries() {
    	try (Stream<Path> paths = Files.walk(
    			Paths.get("//Users//apple//Downloads//eclipse-workspace//TP03//flags"))) {
    	    for (Path path : paths.filter(Files::isRegularFile).collect(Collectors.toList())
    	    		.stream().filter(f -> f.toString().endsWith("png"))
    	    		.collect(Collectors.toList())) {
                Country country = new Country(path);
                if (capitalsMap.get(country.getName()) != null) {
                    country.setCapital(capitalsMap.get(country.getName()));
                }
                countries.add(country);
            } 
    	} 
        catch (IOException e) {
        	System.out.println("Something wrong with flags!");
		}
    }

}