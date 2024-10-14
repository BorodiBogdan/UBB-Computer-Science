package Model;

import Exceptions.VehicleExceptions.InvalidRepairCostException;

public class basicCar implements Vehicle {
    private String name;
    private int repairCost;

    public basicCar(String name, int repairCost) {
        this.name = name;
        this.repairCost = repairCost;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        basicCar otherCar= (basicCar) obj;
        return equalsCommon(otherCar); // Use the common equality check from Vehicle interface
    }

    @Override
    public int getRepairCost() {
        return this.repairCost;
    }

    @Override
    public String getName() {
        return name;
    }

    public void setRepairCost(int repairCost) throws InvalidRepairCostException {
        if(repairCost < 0)
            throw new InvalidRepairCostException("Repair cost cannot be negative");

        this.repairCost = repairCost;
    }

    public void setName(String name) {
        this.name = name;
    }
}
