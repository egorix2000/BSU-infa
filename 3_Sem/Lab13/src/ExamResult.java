
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.StringTokenizer;

public class ExamResult implements Comparable<ExamResult>{
	private int id;
	private String surname;
	private String subject;
	private int mark;
	private final int MINIMAL_MARK = 0;
	private final int MAXIMAL_MARK = 10;
	private final int MINIMAL_ID = 0;

	public ExamResult(int id, String surname, String subject, int mark) throws NumberFormatException {
		this.id = id;
		this.surname = surname;
		this.subject = subject;
		this.mark = mark;
		if(mark < MINIMAL_MARK || mark > MAXIMAL_MARK || id < MINIMAL_ID) {
			throw new NumberFormatException();
		}
	}

	public ExamResult() { }

	public ExamResult(String src) throws NoSuchElementException, NullPointerException, NumberFormatException {
		StringTokenizer st = new StringTokenizer(src);
		this.id = Integer.parseInt(st.nextToken());
		this.surname = st.nextToken();
		this.subject = st.nextToken();
		this.mark = Integer.parseInt(st.nextToken());
		if(mark < MINIMAL_MARK || mark > MAXIMAL_MARK || id < MINIMAL_ID) {
			throw new NumberFormatException();
		}
	}

	public int getMark() { return mark; }

	public int getId() throws NumberFormatException {
		if(id < MINIMAL_ID) {
			throw new NumberFormatException();
		}
		return id;
	}

	public String getSurname() { return surname; }

	public void setMark(int mark) throws NumberFormatException {
		if(mark < MINIMAL_MARK || mark > MAXIMAL_MARK) {
			throw new NumberFormatException();
		}
		this.mark = mark;
	}

	public void setId(int id) { this.id =  id; }

	public void setSurname(String surname) { this.surname = surname; }

	public void setSubject(String subject) { this.subject = subject; }

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(id);
		sb.append(" ");
		sb.append(surname);
		sb.append(" ");
		sb.append(subject);
		sb.append(" ");
		sb.append(mark);
		return sb.toString();
	}

	@Override
	public int compareTo(ExamResult s) {
		return surname.compareTo(s.surname);
	}

	public String toXML() {
		String format = String.format("\t<result id='%s' surname='%s' subject='%s' mark='%s'/>",
				id, surname, subject, mark);
		return format;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		ExamResult examResult = (ExamResult) obj;
		return id == examResult.id;
	}
}
