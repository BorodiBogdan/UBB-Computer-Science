from domain.gameboard import WIDTH, HEIGHT

PLAYER_ONE_TURN = 0
PLAYER_TWO_TURN = 1
BORDER_LIMIT = 0
FREE_SPACE = " "
PLAYER_ONE_CHARACTER = "X"
PLAYER_TWO_CHARACTER = "O"


class GameService:
    def __init__(self, game_board):
        self.__game_board = game_board
        self.__turn = PLAYER_ONE_TURN

    @property
    def get_turn(self):
        return self.__turn

    def get_board(self):
        return self.__game_board

    def decide_playing_character(self):
        if self.__turn == PLAYER_ONE_TURN:
            return PLAYER_ONE_CHARACTER
        elif self.__turn == PLAYER_TWO_TURN:
            return PLAYER_TWO_CHARACTER

    def object_can_be_placed_on_given_position(self, x_coordinate, y_coordinate):
        if x_coordinate >= WIDTH or x_coordinate < BORDER_LIMIT or y_coordinate >= HEIGHT or y_coordinate < BORDER_LIMIT:
            return False

        return self.__game_board.get_square(x_coordinate, y_coordinate) == FREE_SPACE

    def switch_turn(self):
        self.__turn ^= 1

    def obstruct_squares_near_given_coordinates(self, x_coordinate, y_coordinate):
        allowed_moves = [(1, 0), (1, 1), (1, -1), (-1, 0), (-1, 1), (-1, -1), (0, 1), (0, -1)]

        for move in allowed_moves:
            change_of_x_coordinate = move[0]
            change_of_y_coordinate = move[1]
            obstructed_x_coordinate = x_coordinate + change_of_x_coordinate
            obstructed_y_coordinate = y_coordinate + change_of_y_coordinate

            if self.object_can_be_placed_on_given_position(obstructed_x_coordinate, obstructed_y_coordinate):
                self.__game_board.board[obstructed_x_coordinate][obstructed_y_coordinate] = "*"

    def get_moving_player(self):
        return self.__turn

    def get_last_moving_player(self):
        return 1 ^ self.__turn   # if it is not player one is player two, and vice versa

    def check_if_game_is_over(self):
        for row in range(HEIGHT):
            for column in range(WIDTH):
                if self.__game_board.board[row][column] == FREE_SPACE:
                    return False
        return True

    def make_move(self, x_coordinate, y_coordinate):
        if not self.object_can_be_placed_on_given_position(x_coordinate, y_coordinate):
            raise ValueError("Not an valid move!")

        self.__game_board.board[x_coordinate][y_coordinate] = self.decide_playing_character()
        self.obstruct_squares_near_given_coordinates(x_coordinate, y_coordinate)
        self.switch_turn()
