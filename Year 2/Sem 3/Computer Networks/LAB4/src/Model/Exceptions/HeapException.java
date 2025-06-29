package Model.Exceptions;

public class HeapException extends Exception{
    private final String msg;

    public HeapException(String msg) {
        super(msg);
        this.msg = msg;
    }

    public HeapException() {
        super("Heap operation failed.");
        this.msg = "Heap operation failed.";
    }

    @Override
    public String getMessage() {
        return this.msg;
    }
}
