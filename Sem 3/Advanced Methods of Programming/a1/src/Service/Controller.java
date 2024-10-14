package Service;

import Exceptions.RepositoryExceptions.RepositoryException;

public interface Controller {
    Object []getItems();
    void addItem(Object object);
    void deleteItem(Object object) throws RepositoryException;
}
