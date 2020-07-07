package tp1.task1;

import java.util.ArrayList;
import java.util.List;

public class Region {
	private String name;
	private List<District> districts;
	private City center;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public List<District> getDistricts() {
		return districts;
	}
	public void setDistricts(List<District> districts) {
		this.districts = districts;
	}
	public City getCenter() {
		return center;
	}
	public void setCenter(City center) {
		this.center = center;
	}
	public Region(String name, List<District> districts, City center) {
		this.name = name;
		this.districts = districts;
		this.center = center;
	}
	public Region(String name, City center) {
		this.name = name;
		this.districts = new ArrayList<District>();
		this.center = center;
	}
	public double getArea() {
		double area=0;
		for (int t = 0; t < districts.size(); t++) {
			area += districts.get(t).getArea();
		}
		return area;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((center == null) ? 0 : center.hashCode());
		result = prime * result + ((districts == null) ? 0 : districts.hashCode());
		result = prime * result + ((name == null) ? 0 : name.hashCode());
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
		Region other = (Region) obj;
		if (center == null) {
			if (other.center != null)
				return false;
		} else if (!center.equals(other.center))
			return false;
		if (districts == null) {
			if (other.districts != null)
				return false;
		} else if (!districts.equals(other.districts))
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		return true;
	}
	@Override
	public String toString() {
		return "Region [name=" + name + ", districts=" + districts + ", center=" + center + "]";
	}
	
}
