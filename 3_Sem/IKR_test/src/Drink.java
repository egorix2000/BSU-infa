
public abstract class Drink implements Comparable<Drink>{
    private String name;
    private double caffeineQuantity;
    private int price;

    public Drink(String name, double caffeineQuantity, int price) {
        this.name = name;
        this.caffeineQuantity = caffeineQuantity;
        this.price = price;
    }

    public String getName() {
        return this.name;
    }

    public double getCaffeineQuantity() {
        return this.caffeineQuantity;
    }

    @Override
    public int compareTo(Drink drink) {
        int result = drink.price - price != 0 ? drink.price - price :
                Double.compare(caffeineQuantity, drink.caffeineQuantity);
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Drink drink = (Drink) obj;
        return name.equals(drink.name)&& caffeineQuantity == drink.caffeineQuantity && (price == drink.price);
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer("Name:");
        sb.append(name);
        sb.append(", caffeineQuantity: ");
        sb.append(caffeineQuantity);
        sb.append(", price: ");
        sb.append(price);
        return sb.toString();
    }
}
