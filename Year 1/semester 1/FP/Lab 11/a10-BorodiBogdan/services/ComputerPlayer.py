from domain.gameboard import GameBoard, WIDTH, HEIGHT
from copy import deepcopy
INFINITY = (1 << 63) - 1
X_COORDINATE = 0
Y_COORDINATE = 1
WIN_VALUE = 1
LOSE_VALUE = -20
WIN = 1
LOSE = -1
NOT_CONCLUSIVE_GAME = 0
FREE_SPACE = " "
NON_HUMAN_PLAYER = "O"
OBSTRUCTED_SPACE = "*"
AI_PLAYER = 1
HUMAN_PLAYER = 0
INITIAL_DEPTH = 5


class ComputerPlayer:
    def __init__(self, game_board):
        self.__game_board = game_board
        self._AI = AI_PLAYER
        self._Human = HUMAN_PLAYER
        self.game_algorithm_search_depth = INITIAL_DEPTH

    def _get_board_score(self, game_board: GameBoard, last_player):
        # -1 for loss, 1 for win, 0 for neither of them
        for row in range(HEIGHT):
            for column in range(WIDTH):
                if game_board.board[row][column] == FREE_SPACE:
                    return 0

        if last_player == self._AI:
            return WIN
        else:
            return LOSE

    def set_depth(self, depth_value):
        self.game_algorithm_search_depth = depth_value

    @staticmethod
    def is_full(game_board: GameBoard):
        for row in range(HEIGHT):
            for column in range(WIDTH):
                if game_board.get_square(row, column) == FREE_SPACE:
                    return False
        return True

    @staticmethod
    def __get_free_squares(game_board: GameBoard) -> list:
        free_squares = []

        for row in range(HEIGHT):
            for column in range(WIDTH):
                if game_board.board[row][column] == FREE_SPACE:
                    free_squares.append((row, column))

        return free_squares

    @staticmethod
    def _obstruct_after_a_move(game_board: GameBoard, x_coordinate, y_coordinate) -> GameBoard:
        allowed_moves = [(0, 0), (1, 0), (1, 1), (1, -1), (-1, 0), (-1, 1), (-1, -1), (0, 1), (0, -1)]
        new_game_board = deepcopy(game_board)
        new_game_board.board[x_coordinate][y_coordinate] = NON_HUMAN_PLAYER

        for move in allowed_moves:
            change_of_x_coordinate = move[X_COORDINATE]
            change_of_y_coordinate = move[Y_COORDINATE]
            obstructed_x_coordinate = x_coordinate + change_of_x_coordinate
            obstructed_y_coordinate = y_coordinate + change_of_y_coordinate

            if obstructed_x_coordinate < WIDTH and obstructed_y_coordinate < HEIGHT:
                if new_game_board.get_square(obstructed_x_coordinate, obstructed_y_coordinate) == FREE_SPACE:
                    new_game_board.board[obstructed_x_coordinate][obstructed_y_coordinate] = OBSTRUCTED_SPACE

        return new_game_board

    def best_move(self, get_best_move_algorithm):
        board = deepcopy(self.__game_board)
        best_move = get_best_move_algorithm(board, self.game_algorithm_search_depth, True)
        return best_move

    def get_best_move_using_mini_maxi_algorithm(self, game_board: GameBoard, depth: int, maximizing_player: bool):
        if self.is_full(game_board):
            if not maximizing_player:
                return WIN
            return LOSE

        if depth == 0:
            return NOT_CONCLUSIVE_GAME

        list_of_free_squares = self.__get_free_squares(game_board)

        best_move = (0, 0)

        if maximizing_player:
            maxim_value = -INFINITY

            for square in list_of_free_squares:
                x_coordinate = square[X_COORDINATE]
                y_coordinate = square[Y_COORDINATE]

                obstructed_game_board = self._obstruct_after_a_move(deepcopy(game_board), x_coordinate, y_coordinate)

                score = self.get_best_move_using_mini_maxi_algorithm(deepcopy(obstructed_game_board), depth - 1, False)

                if depth == self.game_algorithm_search_depth:
                    if maxim_value < score:
                        maxim_value = score
                        best_move = (x_coordinate, y_coordinate)

                    if maxim_value == WIN:
                        return best_move

                maxim_value = max(score, maxim_value)

                if maxim_value == WIN and depth != self.game_algorithm_search_depth:
                    return maxim_value

            if depth == self.game_algorithm_search_depth:
                return best_move

            return maxim_value
            # we suppose it is AI turn to move

        if not maximizing_player:
            minim_value = INFINITY

            for square in list_of_free_squares:
                x_coordinate = square[X_COORDINATE]
                y_coordinate = square[Y_COORDINATE]

                obstructed_game_board = self._obstruct_after_a_move(deepcopy(game_board), x_coordinate, y_coordinate)

                score = self.get_best_move_using_mini_maxi_algorithm(deepcopy(obstructed_game_board), depth - 1, True)
                minim_value = min(score, minim_value)

                if minim_value == LOSE:
                    return minim_value

            return minim_value

    def get_best_move_using_win_and_lose_value(self, game_board: GameBoard, search_depth: int, maximizing_player: bool):
        if self.is_full(game_board):
            if not maximizing_player:
                return WIN_VALUE
            return LOSE_VALUE

        if search_depth == 0:
            return NOT_CONCLUSIVE_GAME

        list_of_free_squares = self.__get_free_squares(game_board)

        max_value = -INFINITY
        score = 0
        best_move = (0, 0)

        for square in list_of_free_squares:
            x_coordinate = square[X_COORDINATE]
            y_coordinate = square[Y_COORDINATE]

            obstructed_game_board = self._obstruct_after_a_move(deepcopy(game_board), x_coordinate, y_coordinate)

            if search_depth == self.game_algorithm_search_depth:
                move_score = self.get_best_move_using_win_and_lose_value(obstructed_game_board, search_depth - 1, False)
                if move_score > max_value:
                    max_value = move_score
                    best_move = (x_coordinate, y_coordinate)
            elif maximizing_player:
                score += self.get_best_move_using_win_and_lose_value(obstructed_game_board, search_depth - 1, False)
            else:
                score += self.get_best_move_using_win_and_lose_value(obstructed_game_board, search_depth - 1, True)

        if search_depth == self.game_algorithm_search_depth:
            return best_move

        return score
