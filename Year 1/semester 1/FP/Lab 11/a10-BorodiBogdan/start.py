from domain.gameboard import GameBoard
from ui.Ui import Ui
from ui.GUI import Gui


if __name__ == "__main__":
    ui = Ui(GameBoard())
    ui.start_game()
    gui = Gui(GameBoard())
    gui.run()