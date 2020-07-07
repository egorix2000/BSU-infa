
public class Tomato extends Vegetable {

	public Tomato(double calories, double weight) {
		super(calories, weight);
	}

	@Override
	public String toString() {
		return "Tomato [weight=" + getWeight() + "]";
	}
	
	
}
