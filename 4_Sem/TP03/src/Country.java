import javax.swing.*;
import java.nio.file.Path;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Country {
    private String name;
    private String capital;
    private ImageIcon flag;
    private String description;

    public Country(String name) {
        this.name = name.substring(0, 1).toUpperCase() + name.substring(1);
        this.capital = "Unknown";
    }

    public Country(Path filePath) {
    	flag = new ImageIcon(filePath.toString());
        Pattern pattern = Pattern.compile("[a-z]+[.]");
        Matcher matcher = pattern.matcher(filePath.toString());
        if (matcher.find()) {
            name = matcher.group(0).substring(0, matcher.group(0).length() - 1);
        }
        name = name.substring(0, 1).toUpperCase() + name.substring(1);
        capital = "Unknown";
    }

    public int calcPrice() {
        return Math.abs(name.hashCode() % 1000);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCapital() {
        return capital;
    }

    public void setCapital(String capital) {
        this.capital = capital;
    }

    public ImageIcon getFlag() {
        return flag;
    }

    public void setFlag(ImageIcon flag) {
        this.flag = flag;
    }

	public String getDescription() {
		return description;
	}
	
	public void setDescription() {
		this.description = "Tour to " + this.name;
	}

	public void setDescription(String description) {
		this.description = description;
	}
    
    
}
