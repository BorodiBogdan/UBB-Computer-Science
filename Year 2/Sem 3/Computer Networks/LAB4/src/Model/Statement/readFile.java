package Model.Statement;

import Model.Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.IntType;
import Model.Type.StringType;
import Model.Value.IValue;
import Model.Value.IntValue;
import Model.Value.StringValue;

import java.io.BufferedReader;
import java.io.IOException;

public class readFile implements IStatement{
    private IExpression expression;
    private String variableName;

    public readFile(IExpression exp, String varName) {
        this.expression = exp;
        this.variableName = varName;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException {
        if (currentState.getSymbolTable().isDefined(this.variableName)) {
            IValue variableValue =  currentState.getSymbolTable().lookUp(this.variableName);
            if (variableValue.getType().equals(new IntType())) {
                IValue fileName = this.expression.eval(currentState.getSymbolTable(), currentState.getHeapTable());
                if (fileName.getType().equals(new StringType())) {
                    StringValue stringFileName = (StringValue) fileName;
                    BufferedReader fileDescriptor = currentState.getFileTable().lookUp(stringFileName);
                    try {
                        String line = fileDescriptor.readLine();
                        if (line != null) {
                            currentState.getSymbolTable().addKeyValuePair(this.variableName, new IntValue(Integer.parseInt(line)));
                        }
                        else {
                            currentState.getSymbolTable().addKeyValuePair(this.variableName, new IntType().getDefaultValue());
                        }
                    } catch (IOException e) {
                        throw new FileException("Failed to read line from the given file.");
                    }
                }
                else {
                    throw new StatementException("The type of the given value (" + fileName + ") is not a String.");
                }
            }
            else {
                throw new StatementException("The type of the given variable (" + this.variableName + ") is not Int.");
            }
        }
        else {
            throw new DictionaryException("The given variable (" + this.variableName + ") is not defined in the symbol table.");
        }

        return currentState;
    }

    @Override
    public String toString() {
        return "readFile " + this.expression.toString() + " into variable " + this.variableName;
    }

    @Override
    public IStatement deepCopy() {
        return new readFile(this.expression, this.variableName);
    }
}
