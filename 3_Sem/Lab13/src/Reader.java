import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.swing.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Reader {
    static List<ExamResult> readXml(File file) throws SAXException, ParserConfigurationException, IOException {
        List<ExamResult> result = new ArrayList<>();
        DocumentBuilderFactory examResults = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = examResults.newDocumentBuilder();
        Document document = builder.parse(file);
        NodeList resultElements = document.getDocumentElement().getElementsByTagName("result");
        for (int i = 0; i < resultElements.getLength(); i++) {
            Node product = resultElements.item(i);
            NamedNodeMap attributes = product.getAttributes();
            result.add(new ExamResult(Integer.parseInt(attributes.getNamedItem("id").getNodeValue()),
                    attributes.getNamedItem("surname").getNodeValue(),
                    attributes.getNamedItem("subject").getNodeValue(),
                    Integer.parseInt(attributes.getNamedItem("mark").getNodeValue())));
        }
        return result;
    }
}
