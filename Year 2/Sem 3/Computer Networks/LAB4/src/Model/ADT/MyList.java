package Model.ADT;

import Model.Exceptions.ListException;

import java.util.ArrayList;

public class MyList<T> implements IList<T>{
    private ArrayList<T> elems;

    public MyList() {
        this.elems = new ArrayList<T>();
    }

    @Override
    public void add(T newElem) {
        this.elems.add(newElem);
    }

    @Override
    public ArrayList<T> getElems() {
        return this.elems;
    }

    @Override
    public T getElemAtIndex(int index) throws ListException {
        if (index >= this.elems.size()) {
            throw new ListException("Failed to get element: the given index is too large.");
        }
        return this.elems.get(index);
    }

    @Override
    public int size() {
        return this.elems.size();
    }

    @Override
    public String toString() {
        StringBuilder elemsInString = new StringBuilder();
        for (int i = 0; i < this.elems.size(); i++) {
            elemsInString.append(this.elems.get(i).toString());
            if (i < this.elems.size() - 1) {
                elemsInString.append("\n");
            }
        }
        return elemsInString.toString();
    }
}
