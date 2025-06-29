package Model.Type;

import Model.Value.IValue;
import Model.Value.RefValue;

public class RefType implements IType{
    IType inner;

    public RefType(IType inner) {
        this.inner = inner;
    }

    IType getInner() {
        return this.inner;
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof RefType otherRefType) {
            if (otherRefType.getInner() == null) {
                return true;
            }
            else {
                return inner.equals(otherRefType.getInner());
            }
        }
        else {
            return false;
        }
    }

    @Override
    public String toString() {
        return "Ref " + this.inner.toString();
    }

    @Override
    public IValue getDefaultValue() {
        return new RefValue(0, this.inner);
    }

    @Override
    public IType deepCopy() {
        return new RefType(this.inner);
    }
}
