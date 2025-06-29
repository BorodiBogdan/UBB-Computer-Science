package Model.Statement;

import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Exceptions.StatementException;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.BoolType;
import Model.Value.BoolValue;
import Model.Value.IValue;

public class IfStatement implements IStatement {
    private IExpression expression;
    private IStatement thenStatement;
    private IStatement elseStatement;

    public IfStatement(IExpression expression, IStatement thenStatement, IStatement elseStatement) {
        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, HeapException {
        IValue conditional = this.expression.eval(currentState.getSymbolTable(), currentState.getHeapTable());
        if (conditional.getType().equals(new BoolType())) {
            BoolValue boolConditional = (BoolValue) conditional;
            if (boolConditional.getValue()) {
                currentState.getExecutionStack().push(this.thenStatement);
            } else {
                currentState.getExecutionStack().push(this.elseStatement);
            }
        } else {
            throw new StatementException("Conditional expression is not a boolean.");
        }
        return currentState;
    }

    @Override
    public IStatement deepCopy() {
        return new IfStatement(this.expression.deepCopy(), this.thenStatement.deepCopy(), this.elseStatement.deepCopy());
    }

    @Override
    public String toString() {
        return "IF (" + this.expression.toString() + ") " +
                "THEN (" + this.thenStatement.toString() + ") " +
                "ELSE (" + this.elseStatement.toString() + ")";
    }
}
