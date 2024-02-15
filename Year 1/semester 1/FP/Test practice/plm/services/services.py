from repository.repository import Repository


class Service:
    def __init__(self):
        self.__repository = Repository("binary.pickle")

    def add_student(self, id: int, name: str, attendance: int, grade):
        if attendance < 0:
            raise ValueError("Attendance must be greater or equal to 0!")
        if grade > 10 or grade < 0:
            raise ValueError("Invalid grade range!")

        if len(name.split(" ")) < 2 or len(name.split(" ")[0]) < 3 or len(name.split(" ")[1]) < 3:
            raise ValueError("Name must have two or more words")

        self.__repository.add_student(id, name, attendance, grade)

    def get_decreasing_sorted_student_list(self):
        student_list = self.__repository.get_student_list()

        new_student_list = sorted(student_list, key=lambda x: (x.grade, x.name),  reverse=True)
        return new_student_list

    def give_bonus(self, attendance_limit, bonus):
        student_list = self.__repository.get_student_list()

        for student in student_list:
            if student.attendance > attendance_limit:
                self.__repository.give_bonus(student, bonus)

    def get_students_that_include_a_given_string_in_name(self, string):
        student_list = self.__repository.get_student_list()
        displayed_students = []

        for student in student_list:
            if string in student.name:
                displayed_students.append(student)

        return displayed_students
