class Discipline:
    def __init__(self, discipline_id, name):
        self.__discipline_id = discipline_id
        self.__name = name

    def __str__(self):
        return "Name of discipline.txt: " + str(self.__name) + "\nDiscipline id: " + str(self.__discipline_id)

    @property
    def get_discipline_id(self):
        return self.__discipline_id.lower()

    @property
    def get_discipline_name(self):
        return self.__name.lower()