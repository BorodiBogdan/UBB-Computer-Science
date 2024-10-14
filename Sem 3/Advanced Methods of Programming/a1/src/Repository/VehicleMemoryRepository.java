package Repository;
import Exceptions.RepositoryExceptions.RepositoryException;
import Model.Vehicle;

public class VehicleMemoryRepository implements Repository {
    private Vehicle[] vehicles;
    private int capacity;
    private int size;

    public VehicleMemoryRepository() {
        this.capacity = 100;
        this.vehicles = new Vehicle[capacity];
        this.size = 0;
    }

    public VehicleMemoryRepository(Vehicle[] vehicles) {
        this.vehicles = vehicles;
        this.capacity = vehicles.length;
        this.size = vehicles.length;
    }

    @Override
    public void addItem(Object object) {
        if(!(object instanceof Vehicle)) {
            throw new IllegalArgumentException("Invalid object type");
        }

        if(vehicles.length == this.size) {
            Vehicle[] temp = new Vehicle[this.size * 2];
            System.arraycopy(vehicles, 0, temp, 0, this.size);
            vehicles = temp;
            this.capacity *= 2;
        }

        this.vehicles[this.size++] = (Vehicle) object;
    }

    @Override
    public Object[] getItems() {
        return vehicles;
    }

    @Override
    public void deleteItem(Object object) throws RepositoryException {
        //find the item
        if(!(object instanceof  Vehicle))
            throw new RepositoryException("Not a valid item");

        int pos = -1, index = 0;

        for(int i = 0; i < this.size; ++i){
            Vehicle item = vehicles[i];
            if(item.equals(object)){
                pos = index;
            }
            index++;
        }

        if(pos == -1)
            throw new RepositoryException("Item not found for delete");
        //move all items to right

        for(int i = pos; i < vehicles.length - 1; ++i){
            vehicles[i] = vehicles[i + 1];
        }

        //delete last item
        vehicles[this.size] = null;
        this.size--;
    }
}
