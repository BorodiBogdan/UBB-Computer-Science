package View;

import Controller.Controller;
import Model.Exceptions.*;

import java.io.IOException;

public class RunExample extends Command{
    private Controller controller;

    public RunExample(String k, String desc, Controller c) {
        super(k, desc);
        this.controller = c;
    }

    @Override
    public void execute() {
        try {
            this.controller.reinitialiseProgramState();
            this.controller.allSteps();
        } catch (HeapException | ControllerException | StatementException | ListException | StackException |
                ExpressionException | DictionaryException | FileException | IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
