import random


class StudentService:
    def __init__(self, repository):
        self.__student_repository = repository
        self.__generate_random_students()

    def __generate_random_students(self):
        list_of_names = ["Adelina", "Bogdan", "Claudia", "Doru", "Elena", "Florin", "Georgeta", "Horia", "Ioana",
                        "Jean", "Katia", "Luca", "Maria", "Norbert", "Ofelia", "Paul", "Raluca", "Sergiu", "Tara",
                        "Ulise", "Victoria"]

        RANGE = 20

        for random_number in range(RANGE):
            student_id = str(random.randint(random_number * 10 + 1, (random_number + 1) * 10))
            student_name = random.choice(list_of_names)
            self.add_student(student_id, student_name)

    def add_student(self, student_id, student_name):
        self.__student_repository.add_student(student_id, student_name)

    def get_all_students(self):
        return self.__student_repository.get_all_students()

    def get_student_by_id(self, student_id):
        return self.__student_repository.get_student_by_id(student_id)

    def get_all_students_id(self):
        return self.__student_repository.get_all_students_ids()

    def remove_student(self, student_id):
        self.__student_repository.remove_student(student_id)

    def update_student(self, student_id, name):
        self.__student_repository.update_student_by_id(student_id, name)

    def check_if_student_exist(self, student_id):
        return self.__student_repository.check_if_present(student_id)

    def check_if_student_does_not_exist(self, student_id):
        return self.__student_repository.check_if_not_present(student_id)

    def check_if_name_exists(self, name_to_be_checked):
        return self.__student_repository.check_if_name_exists(name_to_be_checked)

    def get_all_students_by_name(self, searched_name):
        student_list = self.__student_repository.get_all_students()
        desired_students_list = []

        for student in student_list:
            if student.get_discipline_name == searched_name:
                desired_students_list.append(student)

        return desired_students_list
