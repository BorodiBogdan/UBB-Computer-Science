import random


class Student:
    def __init__(self, id, name, group):
        self.__id = id
        self.__group = group
        self.__name = name


class Laboratory:
    def __init__(self, id, name):
        self.__id = id
        self.__name = name

    @property
    def id(self):
        return self.__id


class Grade:
    def __init__(self, student, laboratory, laboratory_problem):
        self.__student = student
        self.__laboratory = laboratory
        self.__laboratory_problem = laboratory_problem
        self.__value = None


def generate_students(n: int):
    list_of_generated_student = []
    list_of_random_names = ["Maria", "Mihnea", "Luca", "Bob", "Cotirla", "Eduard"]
    last_generated_id = 0 # here we should put the greatest id already generated

    for student_index in range(n):
        random_name = random.choice(list_of_random_names)
        new_id = random.randint(last_generated_id, last_generated_id + 10)
        last_generated_id += 10
        group = random.randint(912, 917)
        new_student = Student(new_id, random_name, group)
        list_of_generated_student.append(new_student)

    return list_of_generated_student


def generate_laboratories(n: int) -> list[Laboratory]:
    list_of_generated_labs = []
    list_of_random_names = ["FP", "ASC", "Computer Systems", "Computational Logic", "Mathematical Analysis", "Algebra"]
    last_generated_id = 0 # here we should put the greatest id already generated

    for student_index in range(n):
        random_name = random.choice(list_of_random_names)
        new_id = random.randint(last_generated_id, last_generated_id + 10)
        last_generated_id += 10
        lab = Laboratory(new_id, random_name)

    return list_of_generated_labs


def generate_grades(n: int, list_of_students: list[Student] , list_of_labs: list[Laboratory]) -> list[Grade]:
    already_paired_students = []
    generated_grades = []

    for index in range(n):

        while True:
            student = random.choice(list_of_students)
            lab = random.choice(list_of_labs)
            pair = (student, lab)

            if pair not in already_paired_students:
                grade = Grade(student, lab, lab.id)
                generated_grades.append(grade)
                break

    return generated_grades


