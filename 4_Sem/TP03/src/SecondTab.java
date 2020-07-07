import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class SecondTab extends JPanel {

    private List<Country> countries = new ArrayList<>();
    private JTable table;
    private DefaultTableModel tableModel;
    private String[] namesOfColumns = {"Country", "Description", "Price", "Add trip"};

    private JTextField country = new JTextField();
    private JTextField description = new JTextField();
    private JTextField price = new JTextField();
    private JButton addButton;
    
    private int sum = 0;


    public SecondTab(List<Country> countries) {
        this.countries = countries;
        JPanel panelForTextFields = new JPanel(new GridBagLayout());
        
        addButton = createAddButton();
        
        GridBagConstraints c = new GridBagConstraints(); 

        c.fill = GridBagConstraints.HORIZONTAL; 
        c.weightx = 1;
        
        c.gridx = 0; 
        c.gridy = 0; 
        panelForTextFields.add(new JLabel("Country:"), c);
        
        c.gridx = 1; 
        c.gridy = 0; 
        panelForTextFields.add(new JLabel("Description:"), c);
        
        c.gridx = 2; 
        c.gridy = 0; 
        panelForTextFields.add(new JLabel("Price:"), c);
        
        c.gridx = 0; 
        c.gridy = 1; 
        panelForTextFields.add(country, c);
        
        c.gridx = 1; 
        c.gridy = 1; 
        panelForTextFields.add(description, c);
        
        c.gridx = 2; 
        c.gridy = 1; 
        panelForTextFields.add(price, c);
        
        c.gridx = 0; 
        c.gridy = 2; 
        c.gridwidth = 3;
        panelForTextFields.add(addButton, c);

        JPanel panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(1000, 600));
        table = new JTable();
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setVisible(true);
        scrollPane.setPreferredSize(new Dimension(400, 300));
        tableModel = new DefaultTableModel(namesOfColumns, 0) {
            public Class getColumnClass(int column) {
                return getValueAt(0, column).getClass();
            }

            public boolean isCellEditable(int row, int column) {
                if (row == 0)
                    return false;
                else
                    return true;
            }
            @Override                                                           
			public void setValueAt(Object ob, int row, int col){
				super.setValueAt(ob, row, col);
			}
        };
        tableModel.addTableModelListener(new TableModelListener() {
        	private boolean sumSetting = false;
        	
			@Override
			public void tableChanged(TableModelEvent e) {
				if (!sumSetting) {
					int sum = 0;
	                for (int i = 1; i < tableModel.getRowCount(); i++) {
	                	if ((boolean) tableModel.getValueAt(i, 3)) {
	                		sum += (int) tableModel.getValueAt(i, 2);
	                	}
	                }
	                sumSetting = true;
	                tableModel.setValueAt(sum, 0, 2);
	                sumSetting = false;
                }
			}
        });
        
        tableModel.addRow(new Object[]{new ImageIcon(), "Summa : ", 0, false});
    
        table.setModel(tableModel);
        		
        this.setSize(new Dimension(600, 600));
        this.setLayout(new BorderLayout());
        this.add(panelForTextFields, BorderLayout.NORTH);
        this.add(scrollPane, BorderLayout.CENTER);
        for (Country country : countries) {
        	country.setDescription();
            tableModel.insertRow(tableModel.getRowCount(), 
            		(new Object[]{country.getFlag(), country.getDescription(),
                    country.calcPrice(), false}));
        }
        tableModel.setValueAt(0, 0, 2);
    }

    private JButton createAddButton() {
        JButton addButton = new JButton("Add");
        addButton.addActionListener(e -> {
            try {
                int priceField = Integer.valueOf(price.getText());
                String countryName = country.getText();
                if (countries.stream().anyMatch(c -> c.getName().equals(countryName))) {
                    JOptionPane.showMessageDialog(this, "Error: already exists");
                } else if (countryName.length() == 0) {
                	JOptionPane.showMessageDialog(this, "Error: enter country name");
                }
                else {
                    Country cntr = new Country(countryName);
                    countries.add(cntr);
                    Object[] obj = new Object[]{cntr.getFlag(), description.getText(), priceField, false};
                    tableModel.insertRow(tableModel.getRowCount(), obj);
                }
            } catch (NumberFormatException exc) {
                JOptionPane.showMessageDialog(null, exc.getMessage());
            }
        });
        return addButton;
    }
}
