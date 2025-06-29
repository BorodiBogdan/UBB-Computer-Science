package Model.Expression;

import Model.ADT.IDictionary;
import Model.ADT.IHeapTable;
import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Type.IntType;
import Model.Value.BoolValue;
import Model.Value.IValue;
import Model.Value.IntValue;

public class RelationalExpression implements IExpression{
    private IExpression exp1;
    private IExpression exp2;
    private String operation;

    public RelationalExpression(IExpression e1, IExpression e2, String op) {
        this.exp1 = e1;
        this.exp2 = e2;
        this.operation = op;
    }

    @Override
    public IValue eval(IDictionary<String, IValue> symbolTable, IHeapTable<IValue> heapTable) throws ExpressionException, DictionaryException, HeapException {
        IValue val1, val2;
        val1 = this.exp1.eval(symbolTable, heapTable);
        if (val1.getType().equals(new IntType())) {
            val2 = this.exp2.eval(symbolTable, heapTable);
            if (val2.getType().equals(new IntType())) {
                IntValue intVal1 = (IntValue) val1;
                IntValue intVal2 = (IntValue) val2;
                int num1, num2;
                num1 = intVal1.getValue();
                num2 = intVal2.getValue();
                return switch (this.operation) {
                    case ">" -> new BoolValue(num1 > num2);
                    case ">=" -> new BoolValue(num1 >= num2);
                    case "==" -> new BoolValue(num1 == num2);
                    case "<=" -> new BoolValue(num1 <= num2);
                    case "<" -> new BoolValue(num1 < num2);
                    case "!=" -> new BoolValue(num1 != num2);
                    default -> throw new ExpressionException("Invalid relational operation given.");
                };
            }
            else {
                throw new ExpressionException("Second operand is not an integer");
            }
        }
        else {
            throw new ExpressionException("First operand is not an integer");
        }
    }

    @Override
    public IExpression deepCopy() {
        return new RelationalExpression(this.exp1.deepCopy(), this.exp2.deepCopy(), this.operation);
    }

    @Override
    public String toString() {
        return this.exp1.toString() + " " + this.operation + " " + this.exp2.toString();
    }
}
