package Model.Statements;

import Exceptions.InterpreterException;
import Model.Collections.IDictionary;
import Model.Expressions.Expression;
import Model.ProgramState.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Value.IntValue;
import Model.Value.Value;

public class NewLatchStatement implements Statement {
    private String variableName;
    private Expression expression;

    public NewLatchStatement(String variableName, Expression expression){
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        Value expressionValue = expression.eval(state.getSymTable(), state.getHeap());
        if (!expressionValue.getType().equals(new IntType()))
            throw new InterpreterException(String.format("Expression '%s' should have evaluate to an integer", expression.toString()));

        int latch = ((IntValue) expressionValue).getValue();
        int latchLocation = state.getLatchTable().put(latch);

        Value variableValue = state.getSymTable().lookUp(variableName);
        if (variableValue == null)
            throw new InterpreterException(String.format("Variable '%s' has not been declared", variableName));
        if (!variableValue.getType().equals(new IntType()))
            throw new InterpreterException(String.format("Variable '%s' should be of integer type", variableName));
        state.getSymTable().update(variableName, new IntValue(latchLocation));

        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws InterpreterException {
        Type variableType = typeEnv.lookUp(variableName);
        if (variableName == null)
            throw new InterpreterException(String.format("Variable '%s' has not been declared", variableName));
        if (!variableType.equals(new IntType()))
            throw new InterpreterException(String.format("Variable '%s' should be of integer type", variableName));

        Type expressionType = expression.typeCheck(typeEnv);
        if (!expressionType.equals(new IntType()))
            throw new InterpreterException(String.format("Expression '%s' should be of integer type", expressionType));

        return typeEnv;
    }

    @Override
    public Statement deepCopy() {
        return new NewLatchStatement(variableName, expression);
    }

    @Override
    public String toString() {
        return String.format("newLatch(%s, %s)", variableName, expression.toString());
    }
}
