from services.GameService import GameService, HEIGHT, WIDTH
from services.ComputerPlayer import ComputerPlayer
HUMAN = 0
PLAY_HUMAN = "1"
PLAY_COMPUTER = "2"
EASY_MODE = "1"
MEDIUM_MODE = "2"
HARD_MODE = "3"
X_COORDINATE = 0
Y_COORDINATE = 1
EASY_DEPTH = 2
MEDIUM_DEPTH = 4
HARD_DEPTH = 10


class Ui:
    def __init__(self, game_board):
        self.__game_service = GameService(game_board)
        self.__computer_player = ComputerPlayer(game_board)

    def print_board(self):
        matrix_representation_of_board = self.__game_service.get_board()

        print(matrix_representation_of_board)

    def human_move(self):
        print("Please enter your move!")
        x_coordinate = int(input("X: "))
        y_coordinate = int(input("Y: "))

        self.__game_service.make_move(x_coordinate, y_coordinate)

    def ai_move(self, get_best_computer_move_algorithm):
        best_move = self.__computer_player.best_move(get_best_computer_move_algorithm)
        x_coordinate = best_move[X_COORDINATE]
        y_coordinate = best_move[Y_COORDINATE]
        print("Ai moved on the folllowing positions:")
        print(f"X: {x_coordinate}")
        print(f"Y: {y_coordinate}")
        self.__game_service.make_move(x_coordinate, y_coordinate)

    def end_game_if_it_is_over(self):
        if self.__game_service.check_if_game_is_over():
            winning_player = self.__game_service.get_moving_player() + 1
            print(f"Game is over!!\nPlayer number {winning_player} won!")
            exit()

    def play_against_computer_easy(self):
        self.__computer_player.set_depth(EASY_DEPTH)

        while True:
            try:
                if self.__game_service.get_turn == HUMAN:
                    self.human_move()
                else:
                    self.ai_move(self.__computer_player.get_best_move_using_win_and_lose_value)

                self.print_board()

                self.end_game_if_it_is_over()
            except ValueError as ve:
                print(ve)

    def play_against_computer_medium(self):
        while True:
            try:
                if self.__game_service.get_turn == HUMAN:
                    self.human_move()
                else:
                    self.ai_move(self.__computer_player.get_best_move_using_win_and_lose_value)

                self.print_board()

                self.end_game_if_it_is_over()
            except ValueError as ve:
                print(ve)

    def play_against_computer_hard(self):
        while True:
            try:
                if self.__game_service.get_turn == HUMAN:
                    self.human_move()
                else:
                    self.ai_move(self.__computer_player.get_best_move_using_mini_maxi_algorithm)

                self.print_board()

                self.end_game_if_it_is_over()
            except ValueError as ve:
                print(ve)

    def play_against_a_human(self):
        while True:
            try:
                self.human_move()

                self.print_board()

                self.end_game_if_it_is_over()
            except ValueError as ve:
                print(ve)

    def start_game(self):
        while True:
            try:
                print("Choose option: ")
                print("1. Play against a friend")
                print("2. Play against computer")

                chosen_option = input("Choose option: ")

                if chosen_option != PLAY_COMPUTER and chosen_option != PLAY_HUMAN:
                    raise ValueError("Invalid Option")

                if chosen_option == PLAY_HUMAN:
                    self.play_against_a_human()
                elif chosen_option == PLAY_COMPUTER:
                    print("1: Easy mode")
                    print("2: Medium mode")
                    print("3: Hard mode")

                if chosen_option != EASY_MODE and chosen_option != MEDIUM_MODE and chosen_option != HARD_MODE:
                    raise ValueError("Invalid Option")

                game_mode_option = input("Choose option: ")

                if game_mode_option == EASY_MODE:
                    self.__computer_player.set_depth(EASY_DEPTH)
                    self.play_against_computer_easy()
                elif game_mode_option == MEDIUM_MODE:
                    self.__computer_player.set_depth(MEDIUM_DEPTH)
                    self.play_against_computer_medium()
                elif game_mode_option == HARD_MODE:
                    self.__computer_player.set_depth(HARD_DEPTH)
                    self.play_against_computer_hard()
            except ValueError as ve:
                print(ve)
