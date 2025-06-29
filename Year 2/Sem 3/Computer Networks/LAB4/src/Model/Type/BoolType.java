package Model.Type;

import Model.Value.BoolValue;
import Model.Value.IValue;

public class BoolType implements IType{
    public BoolType() {}

    @Override
    public IValue getDefaultValue() {
        return new BoolValue(false);
    }

    @Override
    public IType deepCopy() {
        return new BoolType();
    }

    @Override
    public String toString() {
        return "bool";
    }

    @Override
    public boolean equals(Object other) {
        return other instanceof BoolType;
    }
}
