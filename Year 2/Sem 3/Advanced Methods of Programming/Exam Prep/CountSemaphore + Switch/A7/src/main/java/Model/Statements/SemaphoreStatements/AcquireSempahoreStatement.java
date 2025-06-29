package Model.Statements.SemaphoreStatements;

import Exceptions.InterpreterException;
import Model.Collections.IDictionary;
import Model.ProgramState.ProgramState;
import Model.Statements.Statement;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;
import Model.Values.Value;
import javafx.util.Pair;

import java.util.List;

public class AcquireSempahoreStatement implements Statement {
    private String variableName;
    public AcquireSempahoreStatement(String variableName) {
        this.variableName = variableName;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeEnv) throws InterpreterException {
        try {
            Type var_type = typeEnv.lookUp(variableName);
            if (var_type == null)
                throw new InterpreterException(String.format("Variable '%s' has not been declared!", variableName));
            if (!var_type.equals(new IntType()))
                throw new InterpreterException(String.format("Variable '%s' should have integer type!", variableName));
        } catch (InterpreterException e) {
            throw new InterpreterException(e.getMessage());
        }
        return typeEnv;
    }

    @Override
    public ProgramState execute(ProgramState state) throws InterpreterException {
        try {
            Value variableValue = state.getSymTable().lookUp(variableName);
            if (variableValue == null)
                throw new InterpreterException(String.format("Variable '%s' has not been declared!", variableName));
            if (!variableValue.getType().equals(new IntType()))
                throw new InterpreterException(String.format("Variable '%s' should have integer type!", variableName));

            int semaphoreLocation = ((IntValue) variableValue).getValue();
            state.semaphoreLock.lock();

            Pair<Integer, List<Integer>> semaphore_entry = state.getSemaphoreTable().lookUp(semaphoreLocation);
            if (semaphore_entry == null) {
                ProgramState.semaphoreLock.unlock();
                throw new InterpreterException("Invalid semaphore location!");
            }

            Integer semaphore_n = semaphore_entry.getKey();
            List<Integer> acquired_programs = semaphore_entry.getValue();
            if (semaphore_n > acquired_programs.size()) {
                if (!acquired_programs.contains(state.getId()))
                    acquired_programs.add(state.getId());
            }
            else
                state.getExeStack().push(this);
            ProgramState.semaphoreLock.unlock();
            return null;
        } catch (InterpreterException e) {
            throw new InterpreterException(e.getMessage());
        }
    }

    @Override
    public Statement deepCopy() {
        return new AcquireSempahoreStatement(variableName);
    }

    @Override
    public String toString() {
        return String.format("acquireSemaphore(%s)", variableName);
    }
}
