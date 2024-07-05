from src.Service.service import GameService


class Ui:
    def __init__(self):
        self.__service = GameService()

    def make_move(self, list_of_commands):
        command = 0

        if len(list_of_commands) == 2:
            squares = 1

            if list_of_commands[command] != "move":
                raise ValueError("Invalid input!")

            n = int(list_of_commands[squares])

            return self.__service.move_snake(n)
        elif len(list_of_commands) == 1:
            if (list_of_commands[command] != "up" and list_of_commands[command] != "down" and list_of_commands[command] != "right"
                    and list_of_commands[command] != "left" and list_of_commands[command] != "move"):
                raise ValueError("Invalid input!")
            if list_of_commands[command] == "move":
                return self.__service.move_snake(1)
            else:
                self.__service.set_direction(list_of_commands[command])
        else:
            raise ValueError("Invalid input!")

    def run_ui(self):
        self.__service.place_snake()
        self.__service.place_random_apples()
        print(self.__service.get_snake_board())

        while True:
            try:
                command = input()
                list_of_commands = command.split()
                if self.make_move(list_of_commands) == -1:
                    print("Game over!")
                    break
                if len(list_of_commands) == 2 or list_of_commands[0] == "move":
                    print(self.__service.get_snake_board())
            except ValueError as ve:
                print(ve)
