from board.board import Board


class OrderPlayer:
    def __init__(self, board_table: Board):
        self.__board = board_table

    def make_move(self, x: int, y: int, symbol: str):
        if x >= 6 or y >= 6 or y < 0 or x < 0:
            raise ValueError("Invalid input!")

        self.__board.set_square(x, y, symbol)

    def check_row_column_diagonal(self, i: int, j: int):
        win = 0

        # we verify on the column
        if j <= 1:
            win = 1

            for pos in range(j, j + 4):
                if self.__board.get_square(i, pos) != self.__board.get_square(i, pos + 1):
                    win = 0

        if win == 1:
            return True

        if i <= 1:
            win = 1

            for pos in range(i, i + 4):
                if self.__board.get_square(pos, j) != self.__board.get_square(pos + 1, j):
                    win = 0

        if win == 1:
            return True

        if i <= 1 and j <= 1:
            win = 1

            for pos in range(0, 4):
                if self.__board.get_square(i + pos, j + pos) != self.__board.get_square(i + pos + 1, j + pos + 1):
                    win = 0

        if win == 1:
            return True

        return False

    def check_if_is_win(self):
        for i in range(6):
            for j in range(6):
                current_symbol = self.__board.get_square(i, j)

                if current_symbol == "":
                    continue

                if self.check_row_column_diagonal(i, j):
                    return True

        return False

    def empty_board(self):
        for i in range(6):
            for j in range(6):
                self.__board.set_square_for_clear(i, j)
