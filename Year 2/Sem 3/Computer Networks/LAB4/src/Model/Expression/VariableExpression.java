package Model.Expression;

import Model.ADT.IDictionary;
import Model.ADT.IHeapTable;
import Model.Exceptions.DictionaryException;
import Model.Value.IValue;

public class VariableExpression implements IExpression{
    private String id;

    public VariableExpression(String id) {
        this.id = id;
    }

    @Override
    public IValue eval(IDictionary<String, IValue> symbolTable, IHeapTable<IValue> heapTable) throws DictionaryException {
        return symbolTable.lookUp(this.id);
    }

    @Override
    public IExpression deepCopy() {
        return new VariableExpression(this.id);
    }

    @Override
    public String toString() {
        return this.id;
    }
}
