package Model.ADT;

import Model.Exceptions.HeapException;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
import java.util.PriorityQueue;

public class MyHeapTable<V> implements IHeapTable<V> {
    private HashMap<Integer, V> elems;
    private PriorityQueue<Integer> freedPositions;
    private int nextFreeLocation;

    public MyHeapTable() {
        this.elems = new HashMap<>();
        this.freedPositions = new PriorityQueue<>();
        this.nextFreeLocation = 1;
    }

    @Override
    public int addNewHeapEntry(V value) {
        int allocatedAddress;

        if (!freedPositions.isEmpty()) {
            allocatedAddress = freedPositions.poll();
        }

        else {
            allocatedAddress = this.nextFreeLocation;
            this.nextFreeLocation++;
        }

        this.elems.put(allocatedAddress, value);
        return allocatedAddress;
    }

    @Override
    public V getHeapValue(int address) throws HeapException {
        if (!this.elems.containsKey(address)) {
            throw new HeapException("ERROR: Could not return heap value. The given address is not a key in the heap table.");
        }
        return this.elems.get(address);
    }

    @Override
    public void updateHeapEntry(int address, V newValue) throws HeapException {
        if (!this.elems.containsKey(address)) {
            throw new HeapException("ERROR: Could not update heap entry. The given address is not a key in the heap table");
        }


        this.elems.put(address, newValue);
    }

    @Override
    public boolean isDefined(int address) {
        return this.elems.containsKey(address);
    }

    @Override
    public void setContent(Map<Integer, V> newContent) {
        this.elems.clear();
        this.freedPositions.clear();
        this.elems.putAll(newContent);

        this.nextFreeLocation = this.elems.keySet().stream().max(Integer::compareTo).orElse(0) + 1;
    }

    @Override
    public Map<Integer, V> getContent() {
        return this.elems;
    }

    public void removeHeapEntry(int address) throws HeapException {
        if (!this.elems.containsKey(address)) {
            throw new HeapException("ERROR: Could not remove heap entry. The given address is not a key in the heap table.");
        }

        this.elems.remove(address);

        this.freedPositions.add(address);
    }

    @Override
    public String toString() {
        StringBuilder elemsInString = new StringBuilder();
        int i = 0;


        for (Map.Entry<Integer, V> entry : this.elems.entrySet()) {
            int key = entry.getKey();
            V value = entry.getValue();
            elemsInString.append(key);
            elemsInString.append(" --> ");
            elemsInString.append(value.toString());
            if (i < this.elems.size() - 1) {
                elemsInString.append("\n");
            }
            i += 1;
        }
        return elemsInString.toString();
    }
}
