
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

import javax.swing.AbstractListModel;

public class ExamResultListModel extends AbstractListModel<String> {
	private List<ExamResult> examResultArray;
	public ExamResultListModel() {
		super();
		examResultArray = new ArrayList<ExamResult>();
	}
	@Override
	public int getSize() {
		return examResultArray.size();
	}

	public Iterator iterator() {
		return examResultArray.iterator();
	}

	public ArrayList<ExamResult> toArray() {
		return new ArrayList<>(examResultArray);
	}

	@Override
	public String getElementAt(int index) {
		return examResultArray.get(index).toString();
	}

	public void add(ExamResult s) {
		examResultArray.add(s);
		fireIntervalAdded(this, examResultArray.size()-1, examResultArray.size()-1);
	}
	
	public void clear() {
		if(!examResultArray.isEmpty()) {
			fireIntervalRemoved(this, 0, examResultArray.size() - 1);
			examResultArray.clear();
		}
	}
}