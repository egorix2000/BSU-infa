package tp9;

import java.awt.Color;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.time.format.DateTimeParseException;
import java.util.NoSuchElementException;

import javax.swing.AbstractListModel;
import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListModel;
import javax.swing.event.CellEditorListener;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TableColumnModelEvent;
import javax.swing.event.TableColumnModelListener;
import javax.swing.table.TableColumn;

public class ExcelDateLiteFrame extends JFrame implements PropertyChangeListener {
	private final int NUMBER_OF_ROWS = 40;
	private final int NUMBER_OF_COLUMNS = 40;
	private final int ROW_HEADER_WIDTH = 30;
	private JTable excelViewTable;
	public ExcelDateLiteFrame() {
		setSize(640,480);
		setTitle("ExcelDateLite");
		ExcelTableModel model = new ExcelTableModel(NUMBER_OF_ROWS, NUMBER_OF_COLUMNS);
		excelViewTable = new JTable(model) {
			@Override
			public void setValueAt(Object aValue, int row, int column) {
				try {
					super.setValueAt(aValue, row, column);
				} catch(CircularDependencyException|IndexOutOfBoundsException|InvalidOperationException|TooFewArgumentsException|NoSuchColumnException ex) {
					JOptionPane.showMessageDialog(this, "Error: "+ex.getMessage());
				} catch(NumberFormatException|NoSuchElementException|DateTimeParseException ex) {
					JOptionPane.showMessageDialog(this, "Error: Invalid cell value. " + ex.getClass().getName());
				}
			}
			
		};
		excelViewTable.getTableHeader().setReorderingAllowed(false);
		excelViewTable.getTableHeader().setBorder(BorderFactory.createMatteBorder(0, 0, 0, 1, Color.black));
		excelViewTable.addPropertyChangeListener(this);
		excelViewTable.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		excelViewTable.setGridColor(Color.black);
		for (int i = 0; i < NUMBER_OF_COLUMNS; i++) {
			excelViewTable.getColumnModel().getColumn(i).setPreferredWidth(85);
		}
		ListModel<String> lm = new AbstractListModel<String>() {

		      public int getSize() {
		        return NUMBER_OF_ROWS;
		      }

		      public String getElementAt(int index) {
		        return Integer.toString(index);
		      }
		  };
		JList<String> rowHeader = new JList<String>(lm);
	    rowHeader.setFixedCellWidth(ROW_HEADER_WIDTH);
	    rowHeader.setFixedCellHeight(excelViewTable.getRowHeight());
	    rowHeader.setCellRenderer(new RowHeaderRenderer(excelViewTable));
		JScrollPane scrollPane = new JScrollPane(excelViewTable);
		scrollPane.setRowHeaderView(rowHeader);
		excelViewTable.setFillsViewportHeight(true);
		setContentPane(scrollPane);
	}
	public static void main(String[] args) {
		ExcelDateLiteFrame frame = new ExcelDateLiteFrame();
		frame.setVisible(true);

	}
	@Override
	public void propertyChange(PropertyChangeEvent evt) {
		JTable table = (JTable) evt.getSource();
		if(table.isEditing()) {
			int row = table.getSelectedRow();
			int column = table.getSelectedColumn();
			Node node = (Node) table.getValueAt(row, column);
			JTextField editor = (JTextField) table.getEditorComponent();
			editor.setText(node.getContent());
		}
	}
	
}
