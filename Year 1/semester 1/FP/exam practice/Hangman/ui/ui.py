from service.service import Service
from repository.repository import Repository


class Ui:
    def __init__(self):
        self.__service = Service(Repository())

    def start_game(self):
        self.__service.get_random_sentence()
        mistakes = 0
        hangman = "Hangman"
        sentence = self.__service.get_sentence
        print(sentence)

        while True:
            try:
                letter = input("Guess letter: ")

                if len(letter) != 1:
                    raise ValueError("Invalid input (enter a letter)")

                mistakes += self.__service.guess_letter(letter)

                print(sentence, "-", end="")

                if mistakes == len(hangman):
                    print("YOU LOST")
                    break
                elif self.__service.check_if_won():
                    print("YOU WON")
                    break
                else:
                    print(hangman[:mistakes])
            except ValueError as ve:
                print(ve)

    def print_menu(self):
        print("1. Add a sentence")
        print("2. Start the game")

        chosen_option = input("Choose option: ")

        if chosen_option != "1" and chosen_option != "2":
            raise ValueError("Invalid input")

        if chosen_option == "1":
            question = input("Sentence: ")
            self.__service.add_sentence(question)
        elif chosen_option == "2":
            self.start_game()

    def run_ui(self):
        while True:
            try:
                self.print_menu()
            except ValueError as ve:
                print(ve)
