from repository.repository import Repository
from copy import deepcopy
import random


class Service:
    def __init__(self):
        self.__repository = Repository("file.txt")

    def get_all_player_by_strength(self):
        list_of_players = self.__repository.get_all_players()

        new_list_of_players = sorted(list_of_players, key=lambda x: x.strength)
        return new_list_of_players

    def add_player(self, player_id, name, strenght):
        self.__repository.add_player(player_id, name, strenght)

    def play_round(self, player1, player2, winner):
        self.__repository.remove_player(player1)
        self.__repository.remove_player(player2)

    def set_player_list(self, list_of_players):
        self.__repository.set_player_list(list_of_players)

    def get_lowest_score_players(self, how_many):
        list_of_players = deepcopy(self.__repository.get_all_players())
        list_of_players = sorted(list_of_players, key=lambda x: x.strength)
        list_of_players_by_lowest_score = []
        counter = 0

        for player in list_of_players:
            counter += 1
            list_of_players_by_lowest_score.append(player)
            if counter == how_many:
                break

        return list_of_players_by_lowest_score

    @staticmethod
    def make_pairs_of_players(list_of_players: list):
        """
        :param list_of_players:
        :return: a pair of players that will play in tournament
        """
        lenght_of_list = len(list_of_players)

        first_player = random.randint(0, lenght_of_list - 1)
        second_player = random.randint(0, lenght_of_list - 1)

        while second_player == first_player:
            second_player = random.randint(0, lenght_of_list - 1)

        return list_of_players[first_player], list_of_players[second_player]

    def play_qualifying_rounds(self):
        how_many_players = len(self.__repository.get_all_players())

        power_of_two = 1

        while power_of_two * 2 < how_many_players:
            power_of_two *= 2

        how_many_players = how_many_players - power_of_two

        list_of_qualifying_players = self.get_lowest_score_players(how_many_players * 2)

        return list_of_qualifying_players

    def get_how_many(self):
        return len(self.__repository.get_all_players())
