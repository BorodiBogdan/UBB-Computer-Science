package Model.Statement;

import Model.ADT.IDictionary;
import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Exceptions.StatementException;
import Model.Expression.IExpression;
import Model.ProgramState.ProgramState;
import Model.Type.IType;
import Model.Value.IValue;

public class AssignStatement implements IStatement{
    private String id;
    private IExpression expression;

    public AssignStatement(String id, IExpression expression) {
        this.id = id;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, HeapException {
        IDictionary<String, IValue> symbolTable = currentState.getSymbolTable();
        if (symbolTable.isDefined(this.id)) {
            IValue val = this.expression.eval(symbolTable, currentState.getHeapTable());
            IType type = symbolTable.lookUp(this.id).getType();
            if (val.getType().equals(type)) {
                symbolTable.addKeyValuePair(this.id, val);
            } else {
                throw new StatementException("Declared type of variable " + id + " and type of the assigned expression do not match.");
            }
        } else {
            throw new StatementException("Variable " + id + " was not previously declared.");
        }
        return currentState;
    }

    @Override
    public IStatement deepCopy() {
        return new AssignStatement(this.id, this.expression.deepCopy());
    }

    @Override
    public String toString() {
        return this.id + " = " + this.expression.toString();
    }
}
