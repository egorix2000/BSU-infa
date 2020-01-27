import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Writer {
    static void writeXml(File file, List list) throws IOException {
        FileWriter wr = new FileWriter(file);
        wr.write("<?xml version=\"1.0\"?>" + "\n");
        wr.write("<results>" + "\n");
        Iterator<ExamResult> iter = list.iterator();
        while (iter.hasNext())
            wr.write(iter.next().toXML() + "\n");
        wr.write("</results>");
        wr.flush();
    }
}
