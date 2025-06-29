package Model.Statement;

import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.StatementException;
import Model.ProgramState.ProgramState;

public class NoOperationStatement implements IStatement {

    public NoOperationStatement() {}

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException {
        return currentState;
    }

    @Override
    public IStatement deepCopy() {
        return new NoOperationStatement();
    }

    @Override
    public String toString() {
        return "NoOp Statement";
    }
}
