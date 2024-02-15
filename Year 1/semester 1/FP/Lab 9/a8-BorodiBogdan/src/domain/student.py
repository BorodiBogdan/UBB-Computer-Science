class Student:
    def __init__(self, student_id, name):
        self.__student_id = student_id
        self.__name = name

    @property
    def get_student_id(self):
        return self.__student_id.lower()

    @property
    def get_student_name(self):
        return self.__name.lower()

    def __str__(self):
        return "Student ID: " + str(self.__student_id) + "\nname: " + self.__name
