package Model.Exceptions;

public class ListException extends Exception{
    private final String msg;

    public ListException(String msg) {
        super(msg);
        this.msg = msg;
    }

    public ListException() {
        super("List operation failed");
        this.msg = "List operation failed";
    }

    @Override
    public String getMessage() {
        return this.msg;
    }
}
