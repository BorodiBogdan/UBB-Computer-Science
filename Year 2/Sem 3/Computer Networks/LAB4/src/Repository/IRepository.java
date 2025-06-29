package Repository;

import Model.Exceptions.FileException;
import Model.ProgramState.ProgramState;

import java.io.IOException;

public interface IRepository {
    ProgramState getCurrentProgramState();
    void addProgramState(ProgramState newProgramState);
    void logPrgStateExec() throws IOException, FileException;
}
