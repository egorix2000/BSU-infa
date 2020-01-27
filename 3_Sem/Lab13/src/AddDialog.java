import javax.swing.*;
import java.awt.*;
import java.util.zip.DataFormatException;


public class AddDialog extends JDialog {
    private JButton ok = new JButton("Ok");
    private JLabel labelId = new JLabel("  Id:");
    private JLabel labelSurname = new JLabel("  Name:");
    private JLabel labelSubject = new JLabel("  Subject:");
    private JLabel labelMark = new JLabel("  Mark:");
    private JTextField inputId = new JTextField("", 10);
    private JTextField inputSurname = new JTextField("", 10);
    private JTextField inputSubject = new JTextField("", 10);
    private JTextField inputMark = new JTextField();
    private ExamResult result;

    public AddDialog(JFrame parent, String title, ExamResult o) {
        super(parent, title, true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        this.result = o;

        Container container = this.getContentPane();
        container.setLayout(new GridLayout(5, 2));

        container.add(labelId);
        container.add(inputId);

        container.add(labelSurname);
        container.add(inputSurname);

        container.add(labelSubject);
        container.add(inputSubject);

        container.add(labelMark);
        container.add(inputMark);

        createOkButton();
        container.add(ok);
        pack();
        setVisible(true);
    }

    private void createOkButton() {
        ok.addActionListener(e -> {
            try {
                this.result.setId(Integer.parseInt(inputId.getText()));
                this.result.setSurname(inputSurname.getText());
                this.result.setSubject(inputSubject.getText());
                this.result.setMark(Integer.parseInt(inputMark.getText()));
            } catch (NumberFormatException err) {
                this.result.setSurname("");
                JOptionPane.showMessageDialog(this, "Incorrect data about result");
            }
            setVisible(false);
        });
    }


}