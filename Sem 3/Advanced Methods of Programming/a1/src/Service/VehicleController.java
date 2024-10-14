package Service;
import Exceptions.RepositoryExceptions.RepositoryException;
import Model.Vehicle;
import Repository.Repository;

public class VehicleController implements Controller {
    private Repository repository;

    public VehicleController(Repository repository) {
        this.repository = repository;
    }

    @Override
    public Object[] getItems() {
        return repository.getItems();
    }

    @Override
    public void addItem(Object object) {
        if(!(object instanceof Vehicle)) {
            throw new IllegalArgumentException("Invalid object type");
        }

        repository.addItem(object);
    }
    @Override
    public void deleteItem(Object item) throws RepositoryException {
        try {
            this.repository.deleteItem(item);
        }
        catch (RepositoryException e){
            throw e;
        }
    }
    public Vehicle[] getVehiclesWithRepairCostBiggerThan(int repairCost) {
        Vehicle[] vehicles = (Vehicle[]) repository.getItems();
        Vehicle[] result = new Vehicle[vehicles.length];
        int count = 0;
        for (Vehicle vehicle : vehicles) {
            if(vehicle == null)
                continue;

            if(vehicle.getRepairCost() > repairCost) {
                result[count++] = vehicle;
            }
        }
        return result;
    }
}
