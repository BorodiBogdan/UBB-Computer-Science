package Repository;

import Exceptions.RepositoryExceptions.RepositoryException;
import Model.Vehicle;

public interface Repository {
    Object[] getItems();
    void addItem(Object object);
    void deleteItem(Object object)throws RepositoryException;
}
