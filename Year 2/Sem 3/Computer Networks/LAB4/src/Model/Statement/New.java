package Model.Statement;

import Model.Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.RefType;
import Model.Value.IValue;
import Model.Value.RefValue;

public class New implements IStatement{
    private String variableName;
    private IExpression expression;

    public New(String varName, IExpression exp) {
        this.variableName = varName;
        this.expression = exp;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException {

        if (!currentState.getSymbolTable().isDefined(this.variableName)) {
            throw new StatementException("ERROR: The given variable(" + this.variableName + ") is not defined in the symbol table.");
        }



        IValue variableValue = currentState.getSymbolTable().lookUp(this.variableName);
        if (!(variableValue.getType().equals(new RefType(null)))) {
            throw new StatementException("ERROR: The given variable(" + this.variableName + ") is not a reference value.");
        }


        RefValue refValue = (RefValue) variableValue;
        IValue expressionValue = this.expression.eval(currentState.getSymbolTable(), currentState.getHeapTable());

        if (!expressionValue.getType().equals(refValue.getLocationType())) {
            throw new StatementException("ERROR: The type of the expression's value does not match with the locationType.");
        }


        int addressUsed = currentState.getHeapTable().addNewHeapEntry(expressionValue);

        currentState.getSymbolTable().addKeyValuePair(this.variableName, new RefValue(addressUsed, refValue.getLocationType()));

        return currentState;
    }

    @Override
    public IStatement deepCopy() {
        return new New(this.variableName, this.expression);
    }

    @Override
    public String toString() {
        return "New(" + this.variableName + ", " + this.expression.toString() + ")";
    }
}
