import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Tea extends Drink {
    private TeaType type;

    public Tea(String name, double caffeineQuantity, int price, TeaType type) {
        super(name, caffeineQuantity, price);
        this.type = type;
    }

    public TeaType getType() {
        return this.type;
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer(super.toString());
        sb.append(", type: ");
        sb.append(type);
        return sb.toString();
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!super.equals(obj))
            return false;
        if (!(obj instanceof Coffee))
            return false;
        Tea tea = (Tea) obj;
        return type.equals(tea.type);
    }
}
