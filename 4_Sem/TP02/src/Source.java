import java.io.File;
import java.io.IOException;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;

public class Source {

	public static void main(String[] args) {
		Salad tomatoFlash = new Salad("Tomato Flash");
		try {
			List<Vegetable> components = Reader.readXML(new File("vegetables.xml"));
			for (Vegetable v : components) {
				tomatoFlash.addVegetable(v);
			}
			System.out.println("Tomato Flash calories: " + tomatoFlash.getCaloriesOfSalad());
			System.out.println("Sorted components by weights: \n" + tomatoFlash.sortedByWeight());
			System.out.println("Vegetables in calories range [19...200]: \n" 
					+ tomatoFlash.getVegetablesInRange(19, 200));
		} catch(SAXException | ParserConfigurationException | IOException e) {
			System.out.println("Error with file!");
		}
	}

}
