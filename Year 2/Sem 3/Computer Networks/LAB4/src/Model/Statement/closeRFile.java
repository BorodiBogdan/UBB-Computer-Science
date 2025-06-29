package Model.Statement;

import Model.Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.StringType;
import Model.Value.IValue;
import Model.Value.StringValue;

import java.io.BufferedReader;
import java.io.IOException;

public class closeRFile implements IStatement{
    private IExpression expression;

    public closeRFile(IExpression expr) {
        this.expression = expr;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException {
        IValue val =  this.expression.eval(currentState.getSymbolTable(), currentState.getHeapTable());
        if (val.getType().equals(new StringType())) {
            StringValue stringValue = (StringValue) val;
            BufferedReader fileDescriptor = currentState.getFileTable().lookUp(stringValue);
            try {
                fileDescriptor.close();
            } catch (IOException e) {
                throw new FileException("Failed to close the file " + stringValue);
            }
            currentState.getFileTable().removeByKey(stringValue);
        }
        else {
            throw new StatementException("The given expression (" + this.expression.toString() + ") is not a String");
        }
        return currentState;
    }

    @Override
    public String toString() {
        return "closeFile " + this.expression.toString();
    }

    @Override
    public IStatement deepCopy() {
        return new closeRFile(this.expression);
    }
}
