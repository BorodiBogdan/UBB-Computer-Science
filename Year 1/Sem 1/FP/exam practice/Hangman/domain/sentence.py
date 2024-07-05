class Sentence:
    def __init__(self, sentence):
        self.__sentence = sentence
        self.__public_letters = []
        self.get_public_letters()

    def get_public_letters(self):
        for word in self.__sentence.split():
            self.__public_letters.append(word[0])
            self.__public_letters.append(word[-1])

    @property
    def sentence(self):
        return self.__sentence

    @property
    def public_letters(self):
        return self.__public_letters

    def __str__(self):
        sentence = ""

        for word in self.__sentence.split():
            for letter in word:
                if letter in self.__public_letters:
                    sentence += letter
                else:
                    sentence += "_"
            sentence += " "

        return sentence

    def add_public_letter(self, letter):
        self.__public_letters.append(letter)

