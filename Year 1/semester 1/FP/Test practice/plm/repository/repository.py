from domain.student import Student
import pickle


class Repository:
    def __init__(self, file_path):
        self.__file_path = file_path
        self.__student_list = []
        self.__read_from_file()

    def get_student_list(self):
        return self.__student_list

    @property
    def __student_ids(self):
        id_list = []

        for student in self.__student_list:
            id_list.append(student.id)

        return id_list

    def add_student(self, id, name, attendance, grade):
        if id in self.__student_ids:
            raise ValueError("id already entered!")

        new_student = Student(id, name, attendance, grade)
        self.__student_list.append(new_student)
        self.__save_to_file()

    def __save_to_file(self):
        with open(self.__file_path, "wb") as file:
            pickle.dump(self.__student_list, file)
            file.close()

    def __read_from_file(self):
        with open(self.__file_path, "rb") as file:
            self.__student_list = pickle.load(file)
            file.close()

    def give_bonus(self, given_student, bonus):
        for student in self.__student_list:
            if student == given_student:
                student.change_grade(min(student.grade + bonus, 10))

