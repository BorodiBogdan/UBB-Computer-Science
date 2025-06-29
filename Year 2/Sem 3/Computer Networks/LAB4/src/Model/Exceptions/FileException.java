package Model.Exceptions;

public class FileException extends Exception{
    private final String msg;

    public FileException(String msg) {
        super(msg);
        this.msg = msg;
    }

    public FileException() {
        super("File operation failed.");
        this.msg = "File operation failed.";
    }

    @Override
    public String getMessage() {
        return this.msg;
    }
}
