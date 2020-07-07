import com.google.gson.Gson;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.PieSectionLabelGenerator;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;

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

    private JFreeChart chart;

    @Override
    public JRootPane createRootPane() {
        JRootPane pane = new JRootPane();
        JPanel panel = new JPanel();

        panel.setLayout(new BorderLayout());
        try (FileReader reader = new FileReader("//Users//apple//Downloads//eclipse-workspace//TP04//Task3//input.json")) {
            Gson gson = new Gson();
            Ingredient[] ingredients = gson.fromJson(reader, Ingredient[].class);
            DefaultPieDataset pieDataset = new DefaultPieDataset();
            for (Ingredient elem : ingredients) {
            	pieDataset.setValue(elem.getName(), elem.getWeight());
            }
            chart = ChartFactory.createPieChart("Pizza ingredients",
            		pieDataset, true, true, false);
            PiePlot plot = (PiePlot) chart.getPlot();
            PieSectionLabelGenerator gen = new StandardPieSectionLabelGenerator(
                    "{0}: {1} g, {2}");
            plot.setLabelGenerator(gen);
            panel.add(new ChartPanel(chart));
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        pane.setContentPane(panel);

        return pane;
    }

}