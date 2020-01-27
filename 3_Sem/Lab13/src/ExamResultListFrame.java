
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;
import java.util.function.BinaryOperator;
import java.util.function.Function;
import java.util.stream.Collectors;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

public class ExamResultListFrame extends JFrame implements ActionListener {
	private List<ExamResult> examResults;
	private JPanel contentPane;
	private JList<String> surnameList;
	private DefaultListModel<String> surnameListModel;
	private JList<String> examResultList;
	private DefaultListModel<String> examResultListModel;
	private JScrollPane examResultListScrollPane;
	private JScrollPane surnameListScrollPane;
	private JMenuBar menuBar;
	private JMenu menu;
	private JMenuItem openFileItem;
	private JMenuItem addResultItem;
	private JMenuItem saveItem;
	private JTabbedPane tabbedPane;
	private final String CURRENT_DIRECTORY = "/Users/apple/Downloads/eclipse/Lab13";

	public static void main(String[] args) {
		ExamResultListFrame frame = new ExamResultListFrame();
		frame.setVisible(true);
	}

	public ExamResultListFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));

		examResults = new ArrayList<>();

		surnameListModel = new DefaultListModel<>();
		surnameList = new JList<>(surnameListModel);
		surnameList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		surnameList.setLayoutOrientation(JList.VERTICAL);
		surnameListScrollPane = new JScrollPane(surnameList);

		examResultListModel = new DefaultListModel<>();
		examResultList = new JList<>(examResultListModel);
		examResultList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		examResultList.setLayoutOrientation(JList.VERTICAL);
		examResultListScrollPane = new JScrollPane(examResultList);

		tabbedPane = new JTabbedPane();
		tabbedPane.add("Original data", examResultListScrollPane);
		tabbedPane.add("Best students", surnameListScrollPane);
		contentPane.add(tabbedPane, BorderLayout.CENTER);

		menuBar = new JMenuBar();
		menu = new JMenu("Menu");
		menuBar.add(menu);

		openFileItem = new JMenuItem("Open");
		openFileItem.addActionListener(this);
		menu.add(openFileItem);
		addResultItem = new JMenuItem("Add result");
		addResultItem.addActionListener(this);
		menu.add(addResultItem);
		saveItem = new JMenuItem("Save");
		saveItem.addActionListener(this);
		menu.add(saveItem);
		contentPane.add(menuBar, BorderLayout.NORTH);
		setContentPane(contentPane);
	}

	public void updateSurnameList() {
		surnameListModel.clear();

		TreeSet<ExamResult> group = examResults.stream()
				.collect(Collectors.toMap(ExamResult::getId, Function.identity(),
						BinaryOperator.minBy(Comparator.comparing(ExamResult::getMark)))).values().
						stream().filter(res -> res.getMark() >= 9).collect(Collectors.toCollection(TreeSet::new));

		Iterator<ExamResult> iter = group.iterator();
		while (iter.hasNext())
			surnameListModel.addElement(iter.next().getSurname());
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			if(e.getSource() == openFileItem) {
				JFileChooser chooser = new JFileChooser();
				chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
				chooser.setCurrentDirectory(new File(CURRENT_DIRECTORY));
				if(chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
					/*File file = chooser.getSelectedFile();
					Scanner sc = new Scanner(file);
					examResultListModel.clear();
					while(sc.hasNextLine()) {
						ExamResult s = new ExamResult(sc.nextLine());
						examResultListModel.add(s);
					}
					sc.close();*/
					examResultListModel.clear();
					examResults = Reader.readXml(chooser.getSelectedFile());
					for (int i = 0; i < examResults.size(); i++) {
						examResultListModel.addElement(examResults.get(i).toString());
					}
					updateSurnameList();
				}
			} else if(e.getSource() == addResultItem) {
				/*String src = (String) JOptionPane.showInputDialog(
	                    this,
	                    "Add result using next format:\n"
	                    + "[id] [surname] [subject] [mark]",
	                    "Add result",
	                    JOptionPane.PLAIN_MESSAGE,
	                    null,
	                    null,
	                    null);
				ExamResult result = new ExamResult(src);*/
				ExamResult result = new ExamResult();
				new AddDialog(this, "Add", result);
				if (!result.getSurname().equals("")) {
					examResults.add(result);
					examResultListModel.addElement(result.toString());
					updateSurnameList();
				}
			} else if(e.getSource() == saveItem) {
				JFileChooser chooser = new JFileChooser();
				chooser.setFileSelectionMode(JFileChooser.SAVE_DIALOG);
				int result = chooser.showSaveDialog(this);
				if (result == JFileChooser.APPROVE_OPTION) {
					Writer.writeXml(chooser.getSelectedFile(), examResults);
				}
			}
		} catch(SAXException | ParserConfigurationException | IOException ex) {
			JOptionPane.showMessageDialog(null, "File issue: " + ex.getMessage());
		} catch(NoSuchElementException ex) {
			JOptionPane.showMessageDialog(null, "Incomplete data about result");
		} catch(NullPointerException ex) {
			JOptionPane.showMessageDialog(null, "Empty data about result");
		} catch(NumberFormatException ex) {
			JOptionPane.showMessageDialog(null, "Wrong data format");
		}
	}

}