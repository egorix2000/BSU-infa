package application;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Controller {

    private final static Pattern DATE = Pattern.compile("([0-2][0-9]|(3)[0-1])((.)|(-))(((0)[0-9])|((1)[0-2]))((.)|(-))(\\d{4})");


    @FXML
    private TextArea input;

    @FXML
    private ListView<String> dates;


    public void initialize() {
    	
    	input.textProperty().addListener(new ChangeListener<String>() {
    	    @Override
    	    public void changed(final ObservableValue<? extends String> observable, final String oldValue, final String newValue) {
    	    	dates.getItems().clear();
            	String text = input.getText();
                Matcher matcher = DATE.matcher(text);
                while (matcher.find()) {
                	dates.getItems().add(dates.getItems().size(), matcher.group());
                }
    	    }
    	});
    }
}