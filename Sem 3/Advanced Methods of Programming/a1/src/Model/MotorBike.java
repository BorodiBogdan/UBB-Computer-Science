package Model;

public class MotorBike implements Vehicle {
    private String name;
    private int repairCost;

    public MotorBike(String name, int repairCost) {
        this.name = name;
        this.repairCost = repairCost;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        MotorBike otherMotorBike = (MotorBike) obj;
        return equalsCommon(otherMotorBike); // Use the common equality check from Vehicle interface
    }

    @Override
    public int getRepairCost() {
        return repairCost;
    }

    @Override
    public String getName() {
        return name;
    }

    public void setRepairCost(int repairCost) {
        this.repairCost = repairCost;
    }

    public void setName(String name) {
        this.name = name;
    }
}
