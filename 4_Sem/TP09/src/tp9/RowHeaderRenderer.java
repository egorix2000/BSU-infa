package tp9;

import java.awt.Color;
import java.awt.Component;

import javax.swing.BorderFactory;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JTable;
import javax.swing.ListCellRenderer;
import javax.swing.UIManager;
import javax.swing.table.JTableHeader;

public class RowHeaderRenderer extends JLabel implements ListCellRenderer<String> {
	public RowHeaderRenderer(JTable table) {
	    JTableHeader header = table.getTableHeader();
	    setOpaque(true);
	    setBorder(BorderFactory.createMatteBorder(0, 0, 1, 1, Color.black));
	    setHorizontalAlignment(CENTER);
	    setFont(header.getFont());
	  }

	@Override
	public Component getListCellRendererComponent(JList<? extends String> list, String value, int index,
			boolean isSelected, boolean cellHasFocus) {
		setText((value == null) ? "" : value);
	    return this;
	}

}
