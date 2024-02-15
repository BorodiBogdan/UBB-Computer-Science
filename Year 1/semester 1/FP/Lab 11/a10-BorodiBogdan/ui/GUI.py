from services.ComputerPlayer import ComputerPlayer
from services.GameService import GameService
import pygame
import time

SQUARE_SIZE = 110
WIDTH = 6
HEIGHT = 6
X_COORDINATE = 1
Y_COORDINATE = 0
X_BEST_MOVE = 0
Y_BEST_MOVE = 1
HUMAN = 0
COMPUTER = 1
FONT_SIZE = 55
BUTTON_FONT_SIZE = 23
WHITE = (255, 255, 255)
BACKGROUND_COLOR = (102, 204, 255)
GREY = (166, 166, 166)
RED = (255, 0, 0)
BLACK = (0, 0, 0)
EASY_DEPTH = 3
MEDIUM_DEPTH = 4
HARD_DEPTH = 10
DELAY = 1
players = ["Computer", "Human"]
human_players = ["two", "one"]


class Gui:
    def __init__(self, game_board):
        self.__game_board = game_board
        self.__game_service = GameService(game_board)
        self.__computer_player = ComputerPlayer(game_board)
        self.init_window()
        self.__screen = pygame.display.set_mode(((WIDTH * SQUARE_SIZE), (HEIGHT * SQUARE_SIZE)))
        self.__font = pygame.font.SysFont("impact", FONT_SIZE)
        self.__button_font = pygame.font.SysFont("comic sans", BUTTON_FONT_SIZE)
        self.play_with_ai = False

    def get_board(self):
        return self.__game_service.get_board()

    @staticmethod
    def init_window():
        pygame.init()
        pygame.display.set_caption("Obstruction")

    def display_message(self, message: str, x_position: int, y_position: int):
        pygame.draw.rect(self.__screen, BACKGROUND_COLOR, (0, 0, WIDTH * SQUARE_SIZE, SQUARE_SIZE), )
        label = self.__font.render(message, 1, WHITE)
        self.__screen.blit(label, (x_position, y_position))
        pygame.display.update()

    def draw_button(self, message: str, rect_start_height: int, label_width: int, label_height: int, color: tuple, square_space_to_left: int, label_space_to_left):
        pygame.draw.rect(self.__screen, color, (square_space_to_left, rect_start_height, label_width, label_height), 4)
        label = self.__button_font.render(message, 1, WHITE)
        self.__screen.blit(label, (label_space_to_left, rect_start_height + 10))
        pygame.display.update()

    def draw_ai_buttons(self):
        self.draw_button("Easy Level", 370, 160, 50, (0, 15, 0), 240, 260)
        self.draw_button("Medium Level", 430, 160, 50, (0, 15, 0), 240, 245)
        self.draw_button("Hard Level", 490, 160, 50, (0, 15, 0), 240, 260)

    def draw_start_menu(self):
        self.__screen.fill(BACKGROUND_COLOR)
        self.display_message("Welcome to Obstruction!", 50, 30)

        #pygame.display.update()

    def draw_board(self):
        self.__screen.fill(BACKGROUND_COLOR)
        game_board = self.__game_board.board

        for row in range(HEIGHT):
            for column in range(WIDTH):
                pygame.draw.rect(self.__screen, BLACK, (column * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), 1)

                if game_board[row][column] == "X" or game_board[row][column] == "O":
                    label = self.__font.render(game_board[row][column], 1, BLACK)
                    self.__screen.blit(label, (column * SQUARE_SIZE + 35, row * SQUARE_SIZE + 20))
                elif game_board[row][column] == "*":
                    pygame.draw.rect(self.__screen, GREY, (column * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), )
                    pygame.draw.rect(self.__screen, RED, (column * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE), 1)

        pygame.display.update()

    def human_move(self):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.MOUSEBUTTONDOWN:
                    y_coordinate_of_mouse = event.pos[Y_COORDINATE]
                    x_coordinate_of_mouse = event.pos[X_COORDINATE]
                    x_coordinate = x_coordinate_of_mouse // SQUARE_SIZE
                    y_coordinate = y_coordinate_of_mouse // SQUARE_SIZE
                    self.__game_service.make_move(x_coordinate, y_coordinate)
                    self.draw_board()
                    return

    def ai_move(self, get_best_computer_move_algorithm):
        best_move = self.__computer_player.best_move(get_best_computer_move_algorithm)
        x_coordinate = best_move[X_BEST_MOVE]
        y_coordinate = best_move[Y_BEST_MOVE]
        print("Ai moved on the folllowing positions:")
        print(f"X: {x_coordinate}")
        print(f"Y: {y_coordinate}")
        self.__game_service.make_move(x_coordinate, y_coordinate)
        self.draw_board()
        return

    def medium_ai_move(self):
        self.ai_move(self.__computer_player.get_best_move_using_win_and_lose_value)

    def easy_ai_move(self):
        self.ai_move(self.__computer_player.get_best_move_using_win_and_lose_value)

    def hard_ai_move(self):
        self.ai_move(self.__computer_player.get_best_move_using_mini_maxi_algorithm)

    def end_game_if_over(self):
        if self.__game_service.check_if_game_is_over():
            time.sleep(DELAY)

            if self.play_with_ai == True:
                winning_player = players[self.__game_service.get_moving_player()]
            else:
                winning_player = human_players[self.__game_service.get_moving_player()]

            self.draw_game_over_screen(winning_player)
            exit()

    def play_against_human(self):

        while True:
            try:
                self.human_move()

                self.end_game_if_over()
            except Exception as e:
                print(e)
                print("Invalid move!")
                continue

    def play_against_computer_easy(self):
        self.__computer_player.set_depth(EASY_DEPTH)
        while True:
            try:
                if self.__game_service.get_turn == HUMAN:
                    self.human_move()
                else:
                    self.easy_ai_move()

                self.end_game_if_over()
            except ValueError as ve:
                print(ve)

    def play_against_computer_medium(self):
        self.__computer_player.set_depth(MEDIUM_DEPTH)
        while True:
            try:
                if self.__game_service.get_turn == HUMAN:
                    self.human_move()
                else:
                    self.medium_ai_move()

                self.end_game_if_over()
            except ValueError as ve:
                print(ve)

    def play_against_computer_hard(self):
        self.__computer_player.set_depth(HARD_DEPTH)

        while True:
            try:
                if self.__game_service.get_turn == HUMAN:
                    self.human_move()
                else:
                    self.hard_ai_move()

                self.end_game_if_over()
            except ValueError as ve:
                print(ve)

    def draw_game_over_screen(self, winning_player):
        self.__screen.fill(BACKGROUND_COLOR)
        self.display_message(f"Player {winning_player} wins", 110, 250)
        pygame.display.update()
        time.sleep(DELAY)
        exit()

    def run(self):

        self.draw_start_menu()
        self.draw_button("Play against human", 240, 250, 50, (0, 15, 0), 190, 215)
        self.draw_button("Play against computer", 300, 250, 50, (0, 15, 0), 190, 200)
        run = True
        ai_buttons = False

        while run:
            for event in pygame.event.get():
                mouse = pygame.mouse.get_pos()
                X_COORDINATE_OF_MOUSE = 0
                Y_COORDINATE_OF_MOUSE = 1
                x_coordinate_of_mouse = mouse[X_COORDINATE_OF_MOUSE]
                y_coordinate_of_mouse = mouse[Y_COORDINATE_OF_MOUSE]

                if event.type == pygame.MOUSEBUTTONDOWN:
                    print(x_coordinate_of_mouse, y_coordinate_of_mouse)
                    if x_coordinate_of_mouse <= 450 and x_coordinate_of_mouse >= 200:
                        if 240 <= y_coordinate_of_mouse <= 290:
                            self.draw_board()
                            self.play_against_human()
                        if 300 <= y_coordinate_of_mouse <= 350:
                            # start to play against human
                            self.draw_ai_buttons()
                            ai_buttons = True
                        if ai_buttons and 370 <= y_coordinate_of_mouse <= 420:
                            # start to play against computer easy
                            self.draw_board()
                            self.play_against_computer_easy()
                            self.play_with_ai = True
                        if ai_buttons and 430 <= y_coordinate_of_mouse <= 480:
                            # start to play against computer medium
                            self.play_with_ai = True
                            self.draw_board()
                            self.play_against_computer_medium()
                        if ai_buttons and 490 <= y_coordinate_of_mouse <= 540:
                            # start to play against computer hard
                            self.play_with_ai = True
                            self.draw_board()
                            self.play_against_computer_hard()

                if event.type == pygame.QUIT:
                    run = False

        pygame.quit()
