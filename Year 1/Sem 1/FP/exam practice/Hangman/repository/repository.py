from domain.sentence import Sentence


class Repository:
    def __init__(self):
        """
        we initialise a list of sentences
        we read from file
        """
        self.__list_of_sentences = []
        self.read_from_file()

    def get_all_sentences(self):
        """
        :return: list of sentences
        """
        return self.__list_of_sentences

    def add_sentence(self, sentence):
        """
        we make a new sentence object and at it to the list
        :param sentence: a string entered by the user
        :return: None
        """
        new_sentence = Sentence(sentence)
        self.__list_of_sentences.append(new_sentence)
        self.write_to_file()

    def read_from_file(self):
        """
        we open the file and then we parse it
        we read the sentences and then we create the Sentence object that will be added to the list
        :return: None
        """
        data = []

        with open("sentences.txt", "r") as file:
            for line in file:
                line = line.strip()

                if line == "":
                    continue

                line = line.split()
                sentence = ""

                for word in line:
                    sentence += word + " "

                data.append(Sentence(sentence))

            file.close()

        self.__list_of_sentences = data

    def write_to_file(self):
        """
        here we save the information
        we write it to a text file
        :return: None
        """
        formatt = ""

        for sentence in self.__list_of_sentences:
            formatt += sentence.sentence + "\n"

        with open("sentences.txt", "w") as file:
            file.truncate(0)
            file.write(formatt)
            file.close()
