
public class Vegetable implements Comparable<Vegetable> {
	private double calories; //per 100g
	private double weight;
	
	public Vegetable(double calories, double weight) {
		this.calories = calories;
		this.weight = weight;
	}
	
	public double getCalories() {
		return calories;
	}
	public void setCalories(double calories) {
		this.calories = calories;
	}

	public double getWeight() {
		return weight;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}
	
	@Override
	public String toString() {
		return "Vegetable [weight=" + weight + "]";
	}

	@Override
    public int compareTo(Vegetable v) {
		return Double.compare(this.getWeight(), v.getWeight());
    }
	
}
