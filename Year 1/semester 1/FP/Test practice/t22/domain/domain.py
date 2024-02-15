class Homework:
    def __init__(self, id: int, student_name: str, solution: str):
        self.__id = id
        self.__student_name = student_name
        self.__solution = solution

    @property
    def id(self):
        return self.__id

    @property
    def student_name(self):
        return self.__student_name

    @property
    def solution(self):
        return self.__solution

    def __str__(self):
        return f"{self.__id},{self.__student_name},{self.__solution}"
