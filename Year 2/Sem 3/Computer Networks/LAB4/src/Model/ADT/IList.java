package Model.ADT;

import Model.Exceptions.ListException;

import java.util.ArrayList;

public interface IList<T> {
    void add(T newElem);
    ArrayList<T> getElems();
    T getElemAtIndex(int index) throws ListException;
    int size();
}
