import Exceptions.RepositoryExceptions.RepositoryException;
import Model.*;
import Repository.*;
import Service.*;

public class Main {
    public static void main(String[] args) {
        Vehicle car1 = new basicCar("BMW", 20);
        Vehicle motorBike = new MotorBike("Yamaha", 1001);
        Vehicle Truck = new Truck("TAF", 21334);
        Vehicle VWGolf = new basicCar("VW Golf", 2134);

        Repository vehicleRepo = new VehicleMemoryRepository();
        Controller vehicleController = new VehicleController(vehicleRepo);

        vehicleController.addItem(car1);
        vehicleController.addItem(motorBike);
        vehicleController.addItem(Truck);
        vehicleController.addItem(VWGolf);

        try {
            vehicleController.deleteItem("123");
        }
        catch (RepositoryException e){
            System.out.println(e.toString());
        }
        Vehicle[] expensiveVehicles = ((VehicleController)vehicleController).getVehiclesWithRepairCostBiggerThan(999);

        for(int i = 0; i < expensiveVehicles.length; ++i)
            if(expensiveVehicles[i] != null){
                System.out.println(((Vehicle)expensiveVehicles[i]).getRepairCost());
                System.out.println(((Vehicle)expensiveVehicles[i]).getName());
            }
    }
}