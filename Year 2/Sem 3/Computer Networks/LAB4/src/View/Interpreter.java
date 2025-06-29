package View;

import Controller.Controller;
import Model.ADT.MyDictionary;
import Model.ADT.MyHeapTable;
import Model.ADT.MyList;
import Model.ADT.MyStack;
import Model.Expression.*;
import Model.ProgramState.ProgramState;
import Model.Statement.*;
import Model.Type.BoolType;
import Model.Type.IntType;
import Model.Type.RefType;
import Model.Type.StringType;
import Model.Value.BoolValue;
import Model.Value.IValue;
import Model.Value.IntValue;
import Model.Value.StringValue;
import Repository.IRepository;
import Repository.Repository;

import java.io.BufferedReader;

public class Interpreter {
    public static void main(String[] args) {
        // example 1: int v; v=2; Print(v)
        IStatement ex1 = new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(new AssignStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));
        ProgramState prg1 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex1);
        IRepository repo1 = new Repository(prg1, "ex1.txt");
        Controller controller1 = new Controller(repo1);

        // example 2: int a;int b; a=2+3*5;b=a+1;Print(b)
        IStatement ex2 = new CompoundStatement(new VariableDeclarationStatement("a", new IntType()),
                new CompoundStatement(new VariableDeclarationStatement("b", new IntType()),
                        new CompoundStatement(new AssignStatement("a", new ArithmeticExpression(new ValueExpression(new IntValue(2)),
                                new ArithmeticExpression(new ValueExpression(new IntValue(3)),
                                        new ValueExpression(new IntValue(5)), "*"), "+")),
                                new CompoundStatement(new AssignStatement("b",
                                        new ArithmeticExpression(new VariableExpression("a"),
                                                new ValueExpression(new IntValue(1)), "+")),
                                        new PrintStatement(new VariableExpression("b"))))));
        ProgramState prg2 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex2);
        IRepository repo2 = new Repository(prg2, "ex2.txt");
        Controller controller2 = new Controller(repo2);

        // example 3: bool a; int v; a=true;(If a Then v=2 Else v=3);Print(v)
        IStatement ex3 = new CompoundStatement(new VariableDeclarationStatement("a", new BoolType()),
                new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                        new CompoundStatement(new AssignStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompoundStatement(new IfStatement(new VariableExpression("a"), new AssignStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));
        ProgramState prg3 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex3);
        IRepository repo3 = new Repository(prg3, "ex3.txt");
        Controller controller3 = new Controller(repo3);

        // example 4: string varf; varf="test.in"; openRFile(varf); int varc; readFile(varf, varc); print(varc); readFile(varf, varc); print(varc); closeRFile(varf)
        IStatement ex4 = new CompoundStatement(new VariableDeclarationStatement("varf", new StringType()),
                new CompoundStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test.in"))),
                new CompoundStatement(new openRFile(new VariableExpression("varf")),
                new CompoundStatement(new VariableDeclarationStatement("varc", new IntType()),
                new CompoundStatement(new readFile(new VariableExpression("varf"), "varc"),
                new CompoundStatement(new PrintStatement(new VariableExpression("varc")),
                new CompoundStatement(new readFile(new VariableExpression("varf"), "varc"),
                new CompoundStatement(new PrintStatement(new VariableExpression("varc")), new closeRFile(new VariableExpression("varf"))))))))));
        ProgramState prg4 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex4);
        IRepository repo4 = new Repository(prg4, "ex4.txt");
        Controller controller4 = new Controller(repo4);

        // example 5: string varf; varf="test_empty.in"; openRFile(varf); int varc; readFile(varf, varc); print(varc); readFile(varf, varc); print(varc); closeRFile(varf)
        IStatement ex5 = new CompoundStatement(new VariableDeclarationStatement("varf", new StringType()),
                new CompoundStatement(new AssignStatement("varf", new ValueExpression(new StringValue("test_empty.in"))),
                new CompoundStatement(new openRFile(new VariableExpression("varf")),
                new CompoundStatement(new VariableDeclarationStatement("varc", new IntType()),
                new CompoundStatement(new readFile(new VariableExpression("varf"), "varc"),
                new CompoundStatement(new PrintStatement(new VariableExpression("varc")),
                new CompoundStatement(new readFile(new VariableExpression("varf"), "varc"),
                new CompoundStatement(new PrintStatement(new VariableExpression("varc")), new closeRFile(new VariableExpression("varf"))))))))));
        ProgramState prg5 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex5);
        IRepository repo5 = new Repository(prg5, "ex5.txt");
        Controller controller5 = new Controller(repo5);

        // example 6: print(2 + 3 < 1); (false)
        IStatement ex6 = new PrintStatement(new RelationalExpression(
                new ArithmeticExpression(new ValueExpression(new IntValue(2)), new ValueExpression(new IntValue(3)), "+"),
                new ValueExpression(new IntValue(1)), "<"));
        ProgramState prg6 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex6);
        IRepository repo6 = new Repository(prg6, "ex6.txt");
        Controller controller6 = new Controller(repo6);

        // example 7: print(51 / 3 == 15 + 2); (true)
        IStatement ex7 = new PrintStatement(new RelationalExpression(new ArithmeticExpression(
                new ValueExpression(new IntValue(51)), new ValueExpression(new IntValue(3)), "/"),
                new ArithmeticExpression(new ValueExpression(new IntValue(15)), new ValueExpression(new IntValue(2)), "+"),
                "=="));
        ProgramState prg7 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex7);
        IRepository repo7 = new Repository(prg7, "ex7.txt");
        Controller controller7 = new Controller(repo7);

        // example 8: Ref int v;new(v, 20); Ref Ref int a; new(a, v); print(v); print(a)
        IStatement ex8 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new New("v", new ValueExpression(new IntValue(20))),
                new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                new CompoundStatement(new New("a", new VariableExpression("v")),
                new CompoundStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new VariableExpression("a")))))));
        ProgramState prg8 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex8);
        IRepository repo8 = new Repository(prg8, "ex8.txt");
        Controller controller8 = new Controller(repo8);

        // example 9: Ref int v; new(v, 20); Ref Ref int a; new(a, v); print(rH(v)); print(rH(rH(a)) + 5)
        IStatement ex9 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new New("v", new ValueExpression(new IntValue(20))),
                new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                new CompoundStatement(new New("a", new VariableExpression("v")),
                new CompoundStatement(new PrintStatement(new readFromHeap(new VariableExpression("v"))),
                        new PrintStatement(new ArithmeticExpression(new readFromHeap(new readFromHeap(new VariableExpression("a"))), new ValueExpression(new IntValue(5)), "+")))))));
        ProgramState prg9 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex9);
        IRepository repo9 = new Repository(prg9, "ex9.txt");
        Controller controller9 = new Controller(repo9);

        // example 10: Ref int v; new(v, 20); print(rH(v)); wH(v, 30); print(rH(v) + 5);

        IStatement ex10 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new New("v", new ValueExpression(new IntValue(20))),
                new CompoundStatement(new PrintStatement(new readFromHeap(new VariableExpression("v"))),
                new CompoundStatement(new writeToHeap("v", new ValueExpression(new IntValue(30))),
                        new PrintStatement(new ArithmeticExpression(new readFromHeap(new VariableExpression("v")), new ValueExpression(new IntValue(5)), "+"))))));


        ProgramState prg10 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex10);


        IRepository repo10 = new Repository(prg10, "ex10.txt");


        Controller controller10 = new Controller(repo10);

        // example 11: Ref int v; new(v, 20); Ref Ref int a; new(a, v); new(v, 30); print(rH(rH(a)))
        IStatement ex11 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new New("v", new ValueExpression(new IntValue(20))),
                new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                new CompoundStatement(new New("a", new VariableExpression("v")),
                new CompoundStatement(new New("v", new ValueExpression(new IntValue(30))),
                        new PrintStatement(new readFromHeap(new readFromHeap(new VariableExpression("a")))))))));


        ProgramState prg11 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex11);


        IRepository repo11 = new Repository(prg11, "ex11.txt");


        Controller controller11 = new Controller(repo11);

        // example 12: int v; v=4; (while (v>0) print(v); v=v-1); print(v)


        IStatement ex12 = new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(new AssignStatement("v", new ValueExpression(new IntValue(4))),
                new CompoundStatement(new WhileStatement(new RelationalExpression(new VariableExpression("v"), new ValueExpression(new IntValue(0)), ">"),
                                                        new CompoundStatement(new PrintStatement(new VariableExpression("v")),
                                                                new AssignStatement("v", new ArithmeticExpression(new VariableExpression("v"), new ValueExpression(new IntValue(1)), "-")))),
                                      new PrintStatement(new VariableExpression("v")))));



        ProgramState prg12 = new ProgramState(new MyStack<IStatement>(), new MyDictionary<String, IValue>(),
                new MyList<IValue>(), new MyDictionary<StringValue, BufferedReader>(), new MyHeapTable<IValue>(), ex12);


        IRepository repo12 = new Repository(prg12, "ex12.txt");



        Controller controller12 = new Controller(repo12);

        TextMenu menu = new TextMenu();

        menu.addCommand(new ExitCommand("0", "Exit"));

        menu.addCommand(new RunExample("1", "int v; v = 2; print(x)", controller1));

        menu.addCommand(new RunExample("2", "int a; int b; a = 2 + 3 * 5; b = a + 1; print(b)", controller2));

        menu.addCommand(new RunExample("3", "bool a; int v; a = true; IF (a) THEN (v = 2) ELSE (v = 3); print(v)", controller3));

        menu.addCommand(new RunExample("4", "string varf; varf = \"test.in\"; openRFile(varf); int varc; readFile(varf, varc); print(varc); readFile(varf, varc); print(varc); closeRFile(varf)", controller4));

        menu.addCommand(new RunExample("5", "string varf; varf = \"test_empty.in\"; openRFile(varf); int varc; readFile(varf, varc); print(varc); readFile(varf, varc); print(varc); closeRFile(varf)", controller5));

        menu.addCommand(new RunExample("6", "print(2 + 3 < 1);", controller6));

        menu.addCommand(new RunExample("7", "print(51 / 3 == 15 + 2);", controller7));

        menu.addCommand(new RunExample("8", "Ref int v;new(v, 20); Ref Ref int a; new(a, v); print(v); print(a)", controller8));

        menu.addCommand(new RunExample("9", "Ref int v; new(v, 20); Ref Ref int a; new(a, v); print(rH(v)); print(rH(rH(a)) + 5)", controller9));

        menu.addCommand(new RunExample("10", "Ref int v; new(v, 20); print(rH(v)); wH(v, 30); print(rH(v) + 5);", controller10));

        menu.addCommand(new RunExample("11", "Ref int v; new(v, 20); Ref Ref int a; new(a, v); new(v, 30); print(rH(rH(a)))", controller11));

        menu.addCommand(new RunExample("12", "int v; v=4; (while (v>0) print(v); v=v-1); print(v)", controller12));

        menu.show();
    }
}
