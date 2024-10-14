package Exceptions.RepositoryExceptions;

public class RepositoryException extends Exception{
    public RepositoryException(){
        super("Error in repo");
    }
    public RepositoryException(String message){
        super(message);
    }
}
