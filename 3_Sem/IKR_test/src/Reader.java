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
    public static List<Drink> readXML(File file) throws SAXException, ParserConfigurationException, IOException {
        List<Drink> drinks = new ArrayList<>();

        DocumentBuilderFactory drinksFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = drinksFactory.newDocumentBuilder();
        Document document = builder.parse(file);
        NodeList coffeeNodes = document.getDocumentElement().getElementsByTagName("coffee");
        NodeList teaNodes = document.getDocumentElement().getElementsByTagName("tea");
        NodeList drinkNodes;
        boolean isTea;
        if(coffeeNodes.getLength() == 0) {
            drinkNodes = teaNodes;
            isTea = true;
        } else {
            drinkNodes = coffeeNodes;
            isTea = false;
        }

        String tempName;
        double tempCaffeineQuantity;
        int tempPrice;
        for (int i = 0; i < drinkNodes.getLength(); i++) {
            Node product = drinkNodes.item(i);
            NamedNodeMap attributes = product.getAttributes();
            tempName = attributes.getNamedItem("name").getNodeValue();
            tempCaffeineQuantity = Double.parseDouble(attributes.getNamedItem("caffeineQuantity").getNodeValue());
            tempPrice = Integer.parseInt(attributes.getNamedItem("price").getNodeValue());
            if (isTea) {
                drinks.add(new Tea(tempName, tempCaffeineQuantity, tempPrice,
                        TeaType.toType(attributes.getNamedItem("type").getNodeValue())));
            } else {
                drinks.add(new Coffee(tempName, tempCaffeineQuantity, tempPrice,
                        CoffeeType.toType(attributes.getNamedItem("type").getNodeValue())));
            }

        }

        return drinks;
    }
}
