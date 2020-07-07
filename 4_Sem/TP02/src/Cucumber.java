
public class Cucumber extends Vegetable {

	public Cucumber(double calories, double weight) {
		super(calories, weight);
	}

	@Override
	public String toString() {
		return "Cucumber [weight=" + getWeight() + "]";
	}

	
}
