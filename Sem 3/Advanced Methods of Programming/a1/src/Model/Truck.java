package Model;

public class Truck implements Vehicle{
    private String name;
    private int repairCost;

    public Truck(String name, int repairCost) {
        this.name = name;
        this.repairCost = repairCost;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Truck otherTruck = (Truck) obj;
        return equalsCommon(otherTruck); // Use the common equality check from Vehicle interface
    }

    @Override
    public int getRepairCost(){
        return this.repairCost;
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
