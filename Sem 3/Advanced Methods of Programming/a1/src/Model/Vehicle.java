package Model;
/*
Intr-un service se afla in reparatie mai multe
masini, camioane si motociclete. Sa se afiseze
toate autovehiculele ce au costul de reparatie
mai mare de 1000Ron.
 */
public interface Vehicle {
    int getRepairCost();
    String getName();

    default boolean equalsCommon(Vehicle otherVehicle) {
        if (otherVehicle == null) return false;
        return this.getName().equals(otherVehicle.getName()) &&
                this.getRepairCost() == otherVehicle.getRepairCost();
    }
}
