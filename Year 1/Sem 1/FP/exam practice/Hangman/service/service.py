from repository.repository import Repository
import random


class Service:
    def __init__(self, repository):
        """
        init function
        repository stores all the sentences
        selected sentence is the sentence we try tu guess when playing
        """
        self.__repository = repository
        self.__selected_sentence = random.choice(self.__repository.get_all_sentences())

    @property
    def get_sentence(self):
        """
        :return: selected sentence for playing
        """
        return self.__selected_sentence

    def get_random_sentence(self):
        """
        here we get a random sentence in order to play the game
        :return:
        """
        self.__selected_sentence = random.choice(self.__repository.get_all_sentences())

    def add_sentence(self, sentence):
        """
        we check if the sentence is valid
        if so we add it to the repository
        :param sentence:
        :return:
        """
        if sentence in self.__repository.get_all_sentences():
            raise ValueError("Sentence already in!")

        for word in sentence.split():
            if len(word) < 3:
                raise ValueError("Words are too short")

        self.__repository.add_sentence(sentence)

    def guess_letter(self, letter):
        """
        here we verify if the user has guessed the letter
        :param letter: the guessed letter
        :return: 1 if the letter is correct or 0 therwise
        """
        if letter in self.__selected_sentence.public_letters:
            return 1
        if letter not in self.__selected_sentence.sentence:
            return 1

        self.__selected_sentence.add_public_letter(letter)
        return 0

    def check_if_won(self):
        """
        if all letters are public we won the game
        :return: True if the game is won False otherwise
        """
        for letter in self.__selected_sentence.sentence:
            if letter not in self.__selected_sentence.public_letters and letter != " ":
                return False

        return True

