package Repository;

import Model.Exceptions.FileException;
import Model.ProgramState.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Repository implements IRepository {
    private ArrayList<ProgramState> elems;
    private String logFilePath;
    boolean firstTimeWriting;

    public Repository(ProgramState prgState, String logFilePath) {
        this.elems = new ArrayList<ProgramState>();
        this.elems.add(prgState);
        this.logFilePath = logFilePath;
        this.firstTimeWriting = true;
    }

    @Override
    public ProgramState getCurrentProgramState() {
        return this.elems.get(0);
    }

    @Override
    public void addProgramState(ProgramState newProgramState) {
        this.elems.set(0, newProgramState);
    }

    @Override
    public void logPrgStateExec() throws FileException {
        PrintWriter logFile;
        try {
            if (this.firstTimeWriting) {
                logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, false)));
                this.firstTimeWriting = false;
            }
            else {
                logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
            }
        }
        catch (IOException e) {
            throw new FileException("The file cannot be opened/created/doesn't exist.");
        }
        logFile.println(this.getCurrentProgramState().toString());
        logFile.flush();
        logFile.close();
    }
}
