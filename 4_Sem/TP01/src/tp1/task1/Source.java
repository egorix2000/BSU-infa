package tp1.task1;

import java.util.ArrayList;
import java.util.List;


public class Source {

	public static void main(String[] args) {
		City minsk = new City("Minsk");
		List<Region> regions = new ArrayList<>();
		
		Region vitebskRegion = new Region("Vitebsk region", new City("Vitebsk"));
		vitebskRegion.getDistricts().add(new District("Braslav district", 
				new City("Glubokoe"), 250.5));
		vitebskRegion.getDistricts().add(new District("Rossony district", 
				new City("Orsha"), 101.9));
				
		Region minskRegion = new Region("Minsk region", minsk);
		minskRegion.getDistricts().add(new District("Baranovichi district", 
				new City("Baranovichi"), 10.5));
		minskRegion.getDistricts().add(new District("Liahovichi district", 
				new City("Anta"), 1301.94));
		minskRegion.getDistricts().add(new District("Molodzechno district", 
				new City("Amsterdam"), 89.1));
		
		regions.add(vitebskRegion);
		regions.add(minskRegion);
		
		State belarus = new State("Belarus", minsk, regions);
		System.out.println("Capital: " + belarus.getCapital());
		System.out.println("Number of Regions: " + belarus.getNumberOfRegions());
		System.out.println("Area: " + belarus.getArea());
		System.out.println("Region centers: " + belarus.getCenters());
	}

}
