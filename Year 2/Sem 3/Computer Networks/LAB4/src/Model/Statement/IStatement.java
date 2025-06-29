package Model.Statement;

import Model.Exceptions.*;
import Model.ProgramState.ProgramState;

public interface IStatement {
    ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException;
    IStatement deepCopy();
}
