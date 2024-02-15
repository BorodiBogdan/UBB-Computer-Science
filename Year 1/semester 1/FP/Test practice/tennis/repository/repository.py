from domain.player import Player
from copy import deepcopy

class Repository:
    def __init__(self, path):
        self.__path = path
        self.__list_of_players = []
        self.__read_from_file()

    def add_player(self, player_id, name, strength):
        new_player = Player(int(player_id), name, int(strength))
        self.__list_of_players.append(new_player)

    def get_all_players(self):
        return self.__list_of_players

    def remove_player(self, player_x):
        new_list_of_players = []
        for player in self.__list_of_players:
            if str(player) != str(player_x):

                new_list_of_players.append(player)

        self.__list_of_players = new_list_of_players

    def set_player_list(self, list_of_players):
        self.__list_of_players = deepcopy(list_of_players)

    def __read_from_file(self):
        with open(self.__path, "r") as file:
            for line in file:
                if line == "":
                    continue

                line = line.strip()

                player_id, name, strength = line.split(",")

                self.add_player(player_id, name, strength)

    def __save_to_file(self):
        with open(self.__path, "w") as file:
            file.truncate(0)
            saved_format = ""

            for player in self.__list_of_players:
                saved_format += str(player) + "\n"

            file.write(saved_format)

    def increase_strength(self, playerX):
        for player in self.__list_of_players:
            if player == playerX:
                player.increase_strenght()
