import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class Coffee extends Drink {
    private CoffeeType type;

    public Coffee(String name, double caffeineQuantity, int price, CoffeeType type) {
        super(name, caffeineQuantity, price);
        this.type = type;
    }

    public CoffeeType getType() {
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
        Coffee coffee = (Coffee) obj;
        return type.equals(coffee.type);
    }
}
