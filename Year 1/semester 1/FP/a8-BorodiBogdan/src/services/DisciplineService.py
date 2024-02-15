import random


class DisciplineService:
    def __init__(self, repository):
        self.__discipline_repository = repository
        self.generate_random_subjects()

    def generate_random_subjects(self):
        list_of_disciplines = ["Mathematical Analysis", "Computational Logic", "Algebra", "Fundamentals of Programming",
                               "Computer System Architecture", "Object Oriented Programming", "Dynamical Systems",
                               "Geometry", "Operating Systems", "Data Structures and Algorithms", "Graphs",
                               "Advanced Programming Methods", "Databases", "Statistics"]

        RANGE = 14

        for random_number in range(RANGE):
            random_id = str(random.randint(random_number * 10 + 1, (random_number + 1) * 10))
            self.add_discipline(random_id, list_of_disciplines[random_number])

    def add_discipline(self, discipline_id, discipline_name):
        self.__discipline_repository.add_discipline(discipline_id, discipline_name)

    def remove_discipline(self, discipline_id):
        self.__discipline_repository.remove_discipline_with_given_id(discipline_id)

    def update_discipline(self, discipline_id, new_name):
        self.__discipline_repository.update_disciplines_id(discipline_id, new_name)

    def get_all_disciplines(self):
        return self.__discipline_repository.get_all_disciplines()

    def check_if_discipline_does_not_exists(self, discipline_id):
        return self.__discipline_repository.check_if_the_id_is_not_present(discipline_id)

    def check_if_discipline_exist(self, discipline_id):
        return self.__discipline_repository.check_if_the_id_is_present(discipline_id)

    def get_discipline_by_id(self, chosen_id):
        return self.__discipline_repository.get_discipline_by_id(chosen_id)

    def get_all_disciplines_ids(self):
        return self.__discipline_repository.get_all_disciplines_ids()

    def check_if_name_of_discipline_does_not_exist(self, chosen_name):
        return self.__discipline_repository.check_if_the_name_is_present(chosen_name)

    def get_all_disciplines_by_name(self, chosen_name):
        return self.__discipline_repository.get_all_disciplines_with_a_particular_name(chosen_name)
