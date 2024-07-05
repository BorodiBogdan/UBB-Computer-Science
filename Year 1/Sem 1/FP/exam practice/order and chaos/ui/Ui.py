from board.board import Board
from services.order_service import OrderPlayer
from services.chaos_service import ChaosPlayer


class Ui:
    def __init__(self):
        self.__game_board = Board()
        self.__order_player = OrderPlayer(self.__game_board)
        self.__chaos_player = ChaosPlayer(self.__game_board)

    def play_order(self):
        print("Choose X or O")
        symbol = input("Choose your figure: ")

        if symbol != "O" and symbol != "X":
            raise ValueError("Invalid input!")
        else:
            print("Choose coordinates")
            x = int(input("X: "))
            y = int(input("Y: "))

            self.__order_player.make_move(x, y, symbol)
            return x, y

    def play_chaos(self):
        return self.__chaos_player.make_move()

    def check_game_winner(self):
        if self.__order_player.check_if_is_win():
            print(self.__game_board)
            print("Order has won!")
            return 1
        if self.__chaos_player.check_if_is_win():
            print(self.__game_board)
            print("Chaos has won!")
            return 2

        return 0

    def choose_mode(self):
        print("1.Load an existing game")
        print("2.Load a new game")

        chosen_option = input("Choose option: ")

        if chosen_option != "1" and chosen_option != "2":
            print("Invalid input!")
            self.choose_mode()
        elif chosen_option == "2":
            self.__order_player.empty_board()

    def run_ui(self):
        self.choose_mode()

        print(self.__game_board)

        while True:
            try:
                x1, y1 = self.play_order()

                if self.check_game_winner() != 0:
                    break


                x2, y2 = self.play_chaos()

                if self.check_game_winner() != 0:
                    break

                print(self.__game_board)
                print(f"Human: X: {x1}, Y: {y1}   Computer: X: {x2}, Y: {y2}")
            except ValueError as ve:
                print(ve)
