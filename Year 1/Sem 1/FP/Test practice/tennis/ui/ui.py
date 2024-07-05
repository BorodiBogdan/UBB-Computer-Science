from service.services import Service


class Ui:
    def __init__(self):
        self.__service = Service()

    def display_players(self):
        print("These are all the players sorted by strength: ")
        players = self.__service.get_all_player_by_strength()

        for player in players:
            print(player)

        print("")
    def run_ui(self):
        self.display_players()

        list_of_qualification_players = self.__service.play_qualifying_rounds()

        print("Qualification rounds: ")
        winners = []

        while len(list_of_qualification_players) > 0:
            player1, player2 = self.__service.make_pairs_of_players(list_of_qualification_players)

            print("1 for " + str(player1))
            print("2 for " + str(player2))
            winner = input("Choose winner: ")

            if winner == "1":
                winners.append(player1)
            else:
                winners.append(player2)

            self.__service.play_round(player1, player2, winner)
            list_of_qualification_players.remove(player1)
            list_of_qualification_players.remove(player2)

        for winner in winners:
            winner.increase_strenght()
            self.__service.add_player(winner.player_id, winner.name, winner.strength)

        final_players_list = self.__service.get_all_player_by_strength()

        while len(final_players_list) > 1:
            print(f"last {len(final_players_list)}")
            how_many_players = self.__service.get_how_many()
            winners = []

            while how_many_players > 0:
                player1, player2 = self.__service.make_pairs_of_players(final_players_list)
                print("1 for " + str(player1))
                print("2 for " + str(player2))
                winner = input("Choose winner: ")

                if winner == "1":
                    winners.append(player1)
                else:
                    winners.append(player2)

                self.__service.play_round(player1, player2, winner)
                how_many_players -= 2

            self.__service.set_player_list(winners)
            final_players_list = self.__service.get_all_player_by_strength()

        final_players_list = self.__service.get_all_player_by_strength()
        print("The final winner is: ", end="")
        print(final_players_list[0])
