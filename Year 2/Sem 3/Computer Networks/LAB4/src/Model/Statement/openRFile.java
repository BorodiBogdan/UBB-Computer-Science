package Model.Statement;

import Model.Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.StringType;
import Model.Value.IValue;
import Model.Value.StringValue;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class openRFile implements IStatement{
    private IExpression exp;

    public openRFile(IExpression e) {
        this.exp = e;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException {
        IValue val = this.exp.eval(currentState.getSymbolTable(), currentState.getHeapTable());
        if (val.getType().equals(new StringType())) {
            StringValue stringValue = (StringValue) val;
            if (currentState.getFileTable().isDefined(stringValue)) {
                throw new StatementException("The given string value already is a key in the file table.");
            }
            try {
                BufferedReader fileDescriptor = new BufferedReader(new FileReader(stringValue.getValue()));
                currentState.getFileTable().addKeyValuePair(stringValue, fileDescriptor);
            } catch (FileNotFoundException e) {
                throw new FileException("The given file (" + stringValue.getValue() + ") was not found");
            }
        }
        else {
            throw new StatementException("The given expression is not evaluated to a string");
        }
        return currentState;
    }

    @Override
    public String toString() {
        return "openFile " + this.exp.toString();
    }

    @Override
    public IStatement deepCopy() {
        return new openRFile(this.exp.deepCopy());
    }
}
