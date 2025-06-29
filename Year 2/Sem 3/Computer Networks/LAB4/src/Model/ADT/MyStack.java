package Model.ADT;

import Model.Exceptions.StackException;

import java.util.ListIterator;
import java.util.Stack;

public class MyStack<T> implements IStack<T>{
    private Stack<T> elems;

    public MyStack() {
        this.elems = new Stack<T>();
    }

    @Override
    public void push(T newElem) {
        this.elems.push(newElem);
    }

    @Override
    public T pop() throws StackException {
        if (this.elems.empty()) {
            throw new StackException("Failed to pop element: Full stack.");
        }
        return elems.pop();
    }

    @Override
    public boolean isEmpty() {
        return this.elems.empty();
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        ListIterator<T> stackIterator = this.elems.listIterator(this.elems.size());
        while (stackIterator.hasPrevious()) {
            s.append(stackIterator.previous().toString()).append("\n");
        }
        if (!s.isEmpty()) {
            return s.deleteCharAt(s.length() - 1).toString();
        }
        else {
            return "";
        }
    }
}
