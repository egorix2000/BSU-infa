import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Reader {
    public static List<Vegetable> readXML(File file) throws SAXException, ParserConfigurationException, IOException {
        List<Vegetable> vegetables = new ArrayList<>();

        DocumentBuilderFactory vegetablesFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = vegetablesFactory.newDocumentBuilder();
        Document document = builder.parse(file);
        NodeList vegetableNodes = document.
        		getElementsByTagName("vegetables").item(0).getChildNodes();
        double tempCalories;
        double tempWeight;
        for (int i = 0; i < vegetableNodes.getLength(); i++) {
            Node product = vegetableNodes.item(i);
            if (product.getNodeType() == Node.ELEMENT_NODE) {
	            NamedNodeMap attributes = product.getAttributes();
	            tempCalories = Double.parseDouble(attributes
	            		.getNamedItem("calories").getNodeValue());
	            tempWeight = Double.parseDouble(attributes
	            		.getNamedItem("weight").getNodeValue());
	            if (product.getNodeName() == "cucumber") {
	            	vegetables.add(new Cucumber(tempCalories, tempWeight));
	            } else if (product.getNodeName() == "tomato") {
	            	vegetables.add(new Tomato(tempCalories, tempWeight));
	            } else {
	            	vegetables.add(new Garlic(tempCalories, tempWeight));
	            }
            }
        }

        return vegetables;
    }
}
