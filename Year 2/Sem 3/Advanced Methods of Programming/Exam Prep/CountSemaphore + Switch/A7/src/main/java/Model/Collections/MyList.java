package Model.Collections;


import Exceptions.InterpreterException;

import java.util.ArrayList;

public class MyList<T> implements IList<T> {
    java.util.List<T> list;

    public MyList() {
        this.list = new ArrayList<>();
    }

    @Override
    public void add(T elem) {
        this.list.add(elem);
    }

    @Override
    public T pop() throws InterpreterException {
        if (list.isEmpty())
            throw new InterpreterException("The list is empty!");
        return this.list.remove(0);
    }

    @Override
    public boolean isEmpty() {
        return this.list.isEmpty();
    }

    @Override
    public java.util.List<T> getList() {
        return list;
    }

    @Override
    public String toString() {
        return this.list.toString();
    }
}