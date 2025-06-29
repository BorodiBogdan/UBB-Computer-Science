package Model.Expression;

import Model.ADT.IDictionary;
import Model.ADT.IHeapTable;
import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Value.IValue;

public class ValueExpression implements IExpression{
    private IValue val;

    public ValueExpression(IValue v) {
        this.val = v;
    }

    @Override
    public IValue eval(IDictionary<String, IValue> symbolTable, IHeapTable<IValue> heapTable) throws ExpressionException, DictionaryException {
        return this.val;
    }

    @Override
    public IExpression deepCopy() {
        return new ValueExpression(this.val.deepCopy());
    }

    @Override
    public String toString() {
        return this.val.toString();
    }
}
