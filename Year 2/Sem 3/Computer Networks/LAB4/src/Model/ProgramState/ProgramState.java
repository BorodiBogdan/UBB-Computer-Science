package Model.ProgramState;
import Model.ADT.*;
import Model.Statement.IStatement;
import Model.Value.IValue;
import Model.Value.StringValue;

import java.io.BufferedReader;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class ProgramState {
    private IStack<IStatement> executionStack;
    private IDictionary<String, IValue> symbolTable;
    private IList<IValue> output;
    private IDictionary<StringValue, BufferedReader> fileTable;
    private IHeapTable<IValue> heapTable;
    private IStatement originalProgram;

    public ProgramState(IStack<IStatement> exeStack, IDictionary<String, IValue> symTable, IList<IValue> out,
                        IDictionary<StringValue, BufferedReader> fileTable, IHeapTable<IValue> heapTable, IStatement origPrg) {
        this.executionStack = exeStack;
        this.symbolTable = symTable;
        this.output = out;
        this.fileTable = fileTable;
        this.heapTable = heapTable;
        this.originalProgram = origPrg.deepCopy();
        this.executionStack.push(this.originalProgram);
    }

    public ProgramState(IStatement statement){
        this.executionStack = new MyStack<>();
        this.symbolTable = new MyDictionary<>();
        this.output = new MyList<>();
        this.fileTable = new MyDictionary<>();
        this.heapTable = new MyHeapTable<>();
        this.originalProgram = statement;
        this.executionStack.push(statement);
    }

    public IStack<IStatement> getExecutionStack() {
        return this.executionStack;
    }

    public IDictionary<String, IValue> getSymbolTable() {
        return this.symbolTable;
    }

    public IList<IValue> getOutput() {
        return this.output;
    }

    public IDictionary<StringValue, BufferedReader> getFileTable() { return this.fileTable; }

    public IHeapTable<IValue> getHeapTable() { return this.heapTable; }

    public IStatement getOriginalProgram() {
        return this.originalProgram;
    }

    @Override
    public String toString() {

        return
               "\nExecution Stack:\n" +
               this.executionStack.toString() +
               "\n" +
               "Heap:\n" +
               this.heapTable.toString() +
               "\n" +
               "Symbol Table:\n" +
               this.symbolTable.toString() +
               "\n" +
               "Output:\n" +
               this.output.toString() +
               "\n" +
               "-".repeat(50);
    }
}
