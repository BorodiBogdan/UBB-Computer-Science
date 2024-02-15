from src.board.board import Board
import random


class GameService:
    def __init__(self):
        up = 0
        """
        we have the board we play on and the last entered direction by the user
        the direction is by default up
        """
        self.game_board = Board()
        self.__last_direction = up

    def set_direction(self, direction):
        """
        here we check if the direction is valid
        if not we raise an error
        we won't set the board direction to this one because the move has nt been done
        :param direction: the direction we move in
        up, down, left, right --> 0, 1, 2, 3
        :return:
        """
        up = 0
        down = 1
        left = 2
        right = 3

        if direction == "up" and self.game_board.get_direction == down:
            raise ValueError("Invalid direction!")

        if direction == "down" and self.game_board.get_direction == up:
            raise ValueError("Invalid direction!")

        if direction == "left" and self.game_board.get_direction == right:
            raise ValueError("Invalid direction!")

        if direction == "right" and self.game_board.get_direction == left:
            raise ValueError("Invalid direction!")

        if direction == "up":
            self.__last_direction = up
        if direction == "down":
            self.__last_direction = down
        if direction == "left":
            self.__last_direction = left
        if direction == "right":
            self.__last_direction = right

    def place_snake(self):
        """
        Here we place the snake on the board when the game is starting
        We place it in the middle of the board
        + means it s body
        * means it s head
        :return:
        """
        mid_row = self.game_board.size // 2
        mid_column = self.game_board.size // 2

        self.game_board.get_board()[mid_row][mid_column] = "+"
        self.game_board.add_to_snakes_body(mid_row - 1, mid_column)
        self.game_board.add_to_snakes_body(mid_row, mid_column)
        self.game_board.add_to_snakes_body(mid_row + 1, mid_column)
        self.game_board.get_board()[mid_row + 1][mid_column] = "+"
        self.game_board.get_board()[mid_row - 1][mid_column] = "*"

    def verify_if_position_is_good(self, i, j):
        """
        here we look if the snake can go on position i, j
        if so we return true else we return false
        :param i: x_coordinate
        :param j: y_coordinate
        :return:
        """
        if self.game_board.get_board()[i][j] != "":
            return False

        if i + 1 < self.game_board.size:
            if self.game_board.get_board()[i + 1][j] == "a":
                return False

        if i - 1 >= 0:
            if self.game_board.get_board()[i - 1][j] == "a":
                return False

        if j + 1 < self.game_board.size:
            if self.game_board.get_board()[i][j + 1] == "a":
                return False

        if j - 1 >= 0:
            if self.game_board.get_board()[i][j - 1] == "a":
                return False

        return True

    def get_snake_board(self):
        self.game_board.make_good_board()
        return self.game_board

    def place_random_apples(self):
        """
        here we place the apples when the game is starting we
        need a finite number of apples on the board
        :return:
        """
        for i in range(self.game_board.get_apples):
            self.generate_an_apple()

    def check_if_apples(self, i, j):
        if self.game_board.get_board()[i][j] == 'a':
            return True

    def generate_an_apple(self):
        for i in range(1000): # if we can not add an apple in 1000 iterations it can not be added
            x = random.randint(0, self.game_board.size - 1)
            y = random.randint(0, self.game_board.size - 1)

            if self.verify_if_position_is_good(x, y):
                self.game_board.get_apples_list().append((x, y))
                break

    def move_one_square(self):
        """
        here we move on square
        the moves are performed this way:
        we have a list that's containing snakes coordinates
        on the first position we have it's head
        on the last we have it's tail
        if we move a position the coordinates remain the same, excepting the tail and the head
        the head moves in the specified direction and the tail(last +) is lost
        we pop the tail and insert the head at the square it must be
        here we also check if we ate an apple
        if so the tail is not deleted and a new apple is added
        :return:
        """
        i = 0
        j = 0
        self.game_board.set_direction(self.__last_direction)

        if self.game_board.get_direction == 0:
            i = -1
        if self.game_board.get_direction == 1:
            i = 1
        if self.game_board.get_direction == 2:
            j = -1
        if self.game_board.get_direction == 3:
            j = 1

        last_x = self.game_board.snake_body[0][0]
        last_y = self.game_board.snake_body[0][1]
        tail = self.game_board.snake_body[-1]

        if self.check_game_end(last_x + i, last_y + j):
            return -1

        self.game_board.snake_body.pop(len(self.game_board.snake_body) - 1)
        self.game_board.snake_body.insert(0, (last_x + i, last_y + j))

        if self.check_if_apples(last_x + i, last_y + j):
            self.game_board.snake_body.append((tail[0], tail[1]))
            self.game_board.get_apples_list().remove((last_x + i, last_y + j))
            self.game_board.make_good_board()
            self.generate_an_apple()

        self.game_board.make_good_board()

    def move_snake(self, squares):
        """
        we perform square moves in a direction
        :param squares: how many squares we move
        :return:
        """
        for i in range(squares):
            if self.move_one_square() == -1:
                return -1

        return 0

    def check_game_end(self, i, j):
        """
        here we check if the game ends if we move on i, j coordinate
        :param i: coordinate of row
        :param j: coordinate of column
        :return: True if the game ends, False otherwise
        """
        if (i, j) in self.game_board.snake_body:
            return True

        if i >= self.game_board.size or j >= self.game_board.size or i < 0 or j < 0:
            return True

        return False
