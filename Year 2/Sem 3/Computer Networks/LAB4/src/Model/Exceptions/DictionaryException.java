package Model.Exceptions;

public class DictionaryException extends Exception {
    private final String msg;

    public DictionaryException(String msg) {
        super(msg);
        this.msg = msg;
    }

    public DictionaryException() {
        super("Dictionary operation failed.");
        this.msg = "Dictionary operation failed.";
    }

    @Override
    public String getMessage() {
        return this.msg;
    }
}
