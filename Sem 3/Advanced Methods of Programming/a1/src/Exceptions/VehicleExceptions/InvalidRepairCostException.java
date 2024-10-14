package Exceptions.VehicleExceptions;

public class InvalidRepairCostException extends Exception {
    public InvalidRepairCostException() {
        super("Invalid repair cost provided");
    }

    public InvalidRepairCostException(String message) {
        super(message);
    }
}
