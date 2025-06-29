package Model.Type;

import Model.Value.IValue;

public interface IType {
    IValue getDefaultValue();
    IType deepCopy();
}
