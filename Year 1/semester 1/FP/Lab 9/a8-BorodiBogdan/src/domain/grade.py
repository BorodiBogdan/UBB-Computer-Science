class Grade:
    def __init__(self, discipline_id, student_id, grade_value):
        self.__discipline_id = discipline_id
        self.__student_id = student_id
        self.__grade_value = grade_value

    def __str__(self):
        return "Discipline ID: " + str(self.__discipline_id) + "\nStudent ID: " + str(self.__student_id) + "\nGrade value: " + str(self.__grade_value)

    @property
    def get_student_id(self):
        return self.__student_id.lower()

    @property
    def get_discipline_id(self):
        return self.__discipline_id

    @property
    def get_grade_value(self):
        return self.__grade_value
