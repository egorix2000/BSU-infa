package tp1.task1;

import java.util.ArrayList;
import java.util.List;

public class State {
	private String name;
	private City capital;
	private List<Region> regions;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public City getCapital() {
		return capital;
	}
	public void setCapital(City capital) {
		this.capital = capital;
	}
	public List<Region> getRegions() {
		return regions;
	}
	public void setRegions(ArrayList<Region> regions) {
		this.regions = regions;
	}
	public State(String name, City capital, List<Region> regions) {
		this.name = name;
		this.capital = capital;
		this.regions = regions;
	}
	public State(String name, City capital) {
		this.name = name;
		this.capital = capital;
		this.regions = new ArrayList<Region>();
	}
	public double getArea() {
		double area=0;
		for (int t = 0; t < regions.size(); t++) {
			area += regions.get(t).getArea();
		}
		return area;
	}
	public int getNumberOfRegions() {
		return regions.size();
	}
	public ArrayList<City> getCenters() {
		ArrayList<City> centers = new ArrayList<>();
		for (int t = 0; t < regions.size(); t++) {
			centers.add(regions.get(t).getCenter());
		}
		return centers;
	}
	@Override
	public String toString() {
		return "State [name=" + name + ", capital=" + capital + ", regions=" + regions + "]";
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((capital == null) ? 0 : capital.hashCode());
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + ((regions == null) ? 0 : regions.hashCode());
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
		State other = (State) obj;
		if (capital == null) {
			if (other.capital != null)
				return false;
		} else if (!capital.equals(other.capital))
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		if (regions == null) {
			if (other.regions != null)
				return false;
		} else if (!regions.equals(other.regions))
			return false;
		return true;
	}
}
