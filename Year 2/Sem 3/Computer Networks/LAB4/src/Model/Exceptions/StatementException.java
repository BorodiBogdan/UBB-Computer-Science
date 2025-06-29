package Model.Exceptions;

public class StatementException extends Exception{
    private final String msg;

    public StatementException(String msg) {
        super(msg);
        this.msg = msg;
    }

    public StatementException() {
        super("Statement execution failed.");
        this.msg = "Statement execution failed.";
    }

    @Override
    public String getMessage() {
        return this.msg;
    }
}
