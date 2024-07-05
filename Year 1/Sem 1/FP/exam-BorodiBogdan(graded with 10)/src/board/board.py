from texttable import Texttable
up = 0


class Board:
    def __init__(self):
        self.__size = int(self.get_size_and_apples("getn.txt")[0])
        self.__apples = int(self.get_size_and_apples("getn.txt")[1])
        self.__apples_list = []
        self.__game_board = [["" for i in range(self.size)] for j in range(self.size)]
        self.__snakes_body = []
        self.__direction = up

    @property
    def get_direction(self):
        """
        just a getter for the direction we are heading in
        :return:
        """
        return self.__direction

    def set_direction(self, direction):
        """
        just a setter for the direction we are heading in
        :return:
        """
        self.__direction = direction

    def make_good_board(self):
        """
        here we update the board based on the apples and snakes body
        a -> apple
        + -> snake body
        * -> snake head
        :return:
        """
        for i in range(self.size):
            for j in range(self.size):
                if (i, j) in self.__apples_list:
                    self.__game_board[i][j] = "a"
                elif (i, j) in self.__snakes_body:
                    self.__game_board[i][j] = "+"
                else:
                    self.__game_board[i][j] = ""

        x = int(self.__snakes_body[0][0])
        y = int(self.__snakes_body[0][1])
        self.__game_board[x][y] = "*"

    def get_apples_list(self):
        return self.__apples_list

    @property
    def size(self):
        return self.__size

    @property
    def snake_body(self):
        return self.__snakes_body

    def add_to_snakes_body(self, i, j):
        self.__snakes_body.append((i, j))

    @property
    def get_apples(self):
        return self.__apples

    def get_board(self):
        return self.__game_board

    @staticmethod
    def get_size_and_apples(file_path):
        """
        we read from the file the inputs
        :param file_path:
        :return:
        """
        size = 0
        apples = 0

        with open(file_path, "r") as file:
            for line in file:
                n = int(line.split()[2])

                if size == 0:
                    size = n
                else:
                    apples = n

                if apples > 0 and size > 0:
                    break
            file.close()

        return size, apples

    def __str__(self):
        """
        here we draw the table
        :return:
        """
        printed_board = Texttable()

        for i in range(self.__size):
            row = []
            for j in range(self.__size):
                row.append(self.__game_board[i][j])

            printed_board.add_row(row)

        return printed_board.draw()
