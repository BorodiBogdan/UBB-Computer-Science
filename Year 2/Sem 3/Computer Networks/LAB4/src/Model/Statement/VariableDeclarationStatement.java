package Model.Statement;

import Model.ADT.IDictionary;
import Model.Exceptions.StatementException;
import Model.ProgramState.ProgramState;
import Model.Type.IType;
import Model.Value.IValue;

public class VariableDeclarationStatement implements IStatement{
    private String name;
    private IType type;

    public VariableDeclarationStatement(String name, IType type) {
        this.name = name;
        this.type = type;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws StatementException {
        IDictionary<String, IValue> symbolTable = currentState.getSymbolTable();
        if (symbolTable.isDefined(this.name)) {
            throw new StatementException("Variable " + this.name + " is already declared.");
        } else {
            symbolTable.addKeyValuePair(this.name, this.type.getDefaultValue());
        }
        return null;
    }

    @Override
    public IStatement deepCopy() {
        return new VariableDeclarationStatement(this.name, this.type.deepCopy());
    }

    @Override
    public String toString() {
        return this.type.toString() + " " + this.name;
    }
}
