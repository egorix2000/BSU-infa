import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Salad {
	private String name;
	private List<Vegetable> components;
	
	public Salad(String name) {
		this.name = name;
		this.components = new ArrayList<>();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public void addVegetable(Vegetable v) {
		components.add(v);
	}
	
	public double getCaloriesOfSalad() {
		double calories = 0;
		for (Vegetable v : components) {
			calories += v.getCalories()*v.getWeight()/100;
		}
		return calories;
	}
	
	public List<Vegetable> sortedByWeight() {
		List<Vegetable> sorted = new ArrayList<>(components);
		Collections.sort(sorted);
		return sorted;
	}
	
	public List<Vegetable> getVegetablesInRange(double lowerBound, double upperBound) {
		List<Vegetable> vInRange = new ArrayList<>();
		for (Vegetable v : components) {
			if (v.getCalories() < upperBound && v.getCalories() > lowerBound) {
				vInRange.add(v);
			}
		}
		return vInRange;
	}
}
