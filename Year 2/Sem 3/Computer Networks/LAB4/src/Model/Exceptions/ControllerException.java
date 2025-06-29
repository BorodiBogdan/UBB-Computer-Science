package Model.Exceptions;

public class ControllerException extends Exception{
    private final String msg;

    public ControllerException(String msg) {
        super(msg);
        this.msg = msg;
    }

    public ControllerException() {
        super("Controller operation failed.");
        this.msg = "Controller operation failed.";
    }

    @Override
    public String getMessage() {
        return this.msg;
    }
}
