package tp9;

import java.time.LocalDate;
import java.time.OffsetDateTime;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Map.Entry;
import java.util.TreeMap;
import java.util.function.Function;

public class Node {
	private String content = "";
	private List<Node> observables;
	private List<Node> observers;
	private List<LocalDate> constants;
	private int numberParameter;
	private Function<ValueFunctionInput, LocalDate> valueFunction;
	
	private LocalDate value = null;

	private Parser parser;
	public Node(Parser parser) {
		observables = new ArrayList<Node>();
		constants = new ArrayList<LocalDate>();
		observers = new ArrayList<Node>();
		this.parser = parser;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) throws CircularDependencyException, IndexOutOfBoundsException, NumberFormatException, NoSuchElementException, DateTimeParseException, InvalidOperationException, TooFewArgumentsException, NoSuchColumnException{
		if(content == null || content.strip().isEmpty()) {
			for(int i = 0; i < observables.size(); i++) {
				observables.get(i).removeObserver(this);
			}
			observables.clear();
			constants.clear();
			valueFunction = null;
			value = null;
			this.content = "";
			notifyObservers();
		} else if(!this.content.equals(content)) {		
				parser.parse(content, this);
				this.content = content;	
				recomputeValue();
		}
	}
	
	private void recomputeValue() {
		value = valueFunction.apply(new ValueFunctionInput(observables, constants, numberParameter));
		notifyObservers();
	}
	public LocalDate getValue() {		
		return value;
	}
	@Override
	public String toString() {
		return (value == null) ? null : value.toString();
	}
	public boolean isReachableFrom(Node root) {
		if(root == this) {
			return true;
		} else {
			for (Node child : root.observers) {
				if(isReachableFrom(child)) {
					return true;
				}
			}
			return false;
		}
	}
	public void registerObserver(Node observer, boolean circularDependencyCheck) throws CircularDependencyException{
		if(circularDependencyCheck && isReachableFrom(observer)) throw new CircularDependencyException();
		observers.add(observer);
	}
	public void removeObserver(Node observer) {
		observers.remove(observer);
		
	}
	public void notifyObservers() {
		  for (Node observer : observers) {
			  observer.recomputeValue();
		  }
	}
	public void setObservables(List<Node> observables) throws CircularDependencyException{
		for(int i = 0; i < observables.size(); i++) {
			if(observables.get(i).isReachableFrom(this)) {
				throw new CircularDependencyException();
			}
		}
		for(int i = 0; i < this.observables.size(); i++) {
			this.observables.get(i).removeObserver(this);
		}
		this.observables.clear();
		this.observables.addAll(observables);
		for(int i = 0; i < observables.size(); i++) {
			observables.get(i).registerObserver(this, false);
		}
		
	}
	public void setConstants(List<LocalDate> constants) {
		this.constants.clear();
		this.constants.addAll(constants);
	}
	public void setNumberParameter(int numberParameter) {
		this.numberParameter = numberParameter;
	}
	public void setValueFunction(Function<ValueFunctionInput, LocalDate> valueFunction) {
		this.valueFunction = valueFunction;
	}
}
