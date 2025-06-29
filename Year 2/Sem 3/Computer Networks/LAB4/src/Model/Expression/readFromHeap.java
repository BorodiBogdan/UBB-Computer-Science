package Model.Expression;

import Model.ADT.IDictionary;
import Model.ADT.IHeapTable;
import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Type.RefType;
import Model.Value.IValue;
import Model.Value.RefValue;

public class readFromHeap implements IExpression{
    private IExpression expression;

    public readFromHeap(IExpression exp) {
        this.expression = exp;
    }

    @Override
    public IValue eval(IDictionary<String, IValue> symbolTable, IHeapTable<IValue> heapTable) throws ExpressionException, DictionaryException, HeapException {
        IValue expressionValue = this.expression.eval(symbolTable, heapTable);


        if (!(expressionValue.getType().equals(new RefType(null)))) {
            throw new ExpressionException("ERROR: The given expression(" + this.expression.toString() + ") does not evaluate to a RefValue.");
        }


        RefValue refValue = (RefValue) expressionValue;


        int address = refValue.getAddress();


        if (!heapTable.isDefined(address)) {
            throw new ExpressionException("ERROR: The address of the given RefValue(" + this.expression.toString() + ") is not available in the heap.");
        }

        return heapTable.getHeapValue(address);
    }

    @Override
    public IExpression deepCopy() {
        return new readFromHeap(this.expression.deepCopy());
    }

    @Override
    public String toString() {
        return "readFromHeap(" + this.expression.toString() + ")";
    }
}
