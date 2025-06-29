package Model.ADT;

import Model.Exceptions.HeapException;

import java.util.Map;

public interface IHeapTable<V> {
    int addNewHeapEntry(V value);

    V getHeapValue(int address) throws HeapException;


    void updateHeapEntry(int address, V newValue) throws HeapException;


    boolean isDefined(int address);


    void setContent(Map<Integer, V> newContent);


    Map<Integer, V> getContent();
}
