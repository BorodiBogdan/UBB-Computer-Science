

class Student:
    def __init__(self, id: int, name: str, attendance: int, grade: int):
        self.__id = id
        self.__name = name
        self.__attendance = attendance
        self.__grade = grade

    @property
    def grade(self):
        return self.__grade

    def change_grade(self, new_value):
        self.__grade = new_value

    @property
    def id(self):
        return self.__id

    @property
    def attendance(self):
        return self.__attendance

    @property
    def name(self):
        return self.__name

    def __eq__(self, another):
        return self.__id == another.id and self.__attendance == another.attendance and self.__grade == another.grade and self.__name == another.name

    def __str__(self):
        return f"{self.__id}, {self.__name}, {self.attendance}, {self.grade}"