class Assignment:
    def __init__(self, student_id, name, solution):
        self.__student_id = student_id
        self.__name = name
        self.__solution = solution

    def __str__(self):
        return f"{self.__student_id},{self.__name},{self.__solution}"

    @property
    def student_id(self):
        return self.__student_id

    @property
    def name(self):
        return self.__name

    @property
    def solution(self):
        return self.__solution
