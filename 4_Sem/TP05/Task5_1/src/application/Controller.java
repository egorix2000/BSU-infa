package application;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Controller {
	
    private final static Pattern NATURAL = Pattern.compile("([0-9]*)([1-9])([0-9]*)");
    private final static Pattern INTEGER = Pattern.compile("[+-]?[0-9]+");
    private final static Pattern REAL = Pattern.compile("[-+]?(([0-9]*[.][0-9]+)|([0-9]+[.][0-9]*))([eE][-+]?[0-9]+)?|([-+]?[0-9]+([eE][-+]?[0-9]+))");
    private final static Pattern DATE = Pattern.compile("((0)[1-9]|[1-2][0-9]|(3)[0-1])((.)|(/)|(-))((01)|(03)|(05)|(07)|(10)|(12))((.)|(/)|(-))(\\d{4})" +
            "|((0)[1-9]|[1-2][0-9]|(3)[0])((.)|(/)|(-))((04)|(06)|(08)|(09)|(11))((.)|(/)|(-))(\\d{4})"
            + "|((0)[1-9]|[0-2][0-9])((.)|(/)|(-))((02))((.)|(/)|(-))(\\d{4})");
    private final static Pattern TIME = Pattern.compile("([01]?[0-9]|2[0-3]):[0-5][0-9]"); 
	private final static Pattern EMAIL = Pattern.compile("^[a-zA-Z0-9+._-]+@[a-z0-9.-]+\\.[a-z]{2,6}");

    private final static String[] ELEMENTS = {"Natural", "Integer", "Real", "Date", "Time", "E-Mail"};


    @FXML
    private TextField input;

    @FXML
    private ComboBox<String> comboBox;

    @FXML
    private Circle circle;

    private Matcher getMatcher(String newValue) {
    	Matcher m;
    	switch (comboBox.getValue()) {
        case "Integer":
            m = INTEGER.matcher(newValue);
            break;

        case "Real":
            m = REAL.matcher(newValue);
            break;
            
        case "Date":
            m = DATE.matcher(newValue);
            break;

        case "Time":
            m = TIME.matcher(newValue);
            break;

        case "E-Mail":
            m = EMAIL.matcher(newValue);
            break;
        
        default:
        	m = NATURAL.matcher(newValue);
            break;
    	}
    	return m;
    }
    
    public void comboAction() {
    	Matcher m = getMatcher(input.getText());
        if (m.matches())
        	circle.setFill(Color.GREEN);
        else
        	circle.setFill(Color.RED);
    }
    
    public void initialize() {

    	comboBox.setItems(FXCollections.observableArrayList(ELEMENTS));
    	comboBox.setValue("Natural");
    	

    	input.textProperty().addListener((observable, oldValue, newValue) -> {
            Matcher m = getMatcher(newValue);
            if (m.matches())
            	circle.setFill(Color.GREEN);
            else
            	circle.setFill(Color.RED);
        });
    }
}
