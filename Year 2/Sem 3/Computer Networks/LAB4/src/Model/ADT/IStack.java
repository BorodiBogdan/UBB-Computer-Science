package Model.ADT;

import Model.Exceptions.StackException;

public interface IStack<T> {
    void push(T newElem);
    T pop() throws StackException;
    boolean isEmpty();
}
