package com.test.map;

public class DStudent {
	private int id;
	private String name;
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + id;
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
		DStudent other = (DStudent) obj;
		if (id != other.id)
			return false;
		return true;
	}

	public static void main(String [] args){
		
	}
}
