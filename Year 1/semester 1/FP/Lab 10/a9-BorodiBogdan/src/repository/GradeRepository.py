from src.domain.grade import Grade
from src.repository.RepositoryError import RepositoryError
import pickle


class GradeRepository:
    def __init__(self):
        self._grades = []

    def add_grade(self, discipline_id, student_id, grade_value):
        if int(grade_value) < 1 or int(grade_value) > 10:
            raise RepositoryError("Invalid grade value")

        grade = Grade(discipline_id, student_id, grade_value)
        self._grades.append(grade)
        self._save_to_file()

    def remove_grade(self, discipline_id, student_id, grade_value):
        new_grade_list = []
        grade_to_be_removed = Grade(discipline_id, student_id, grade_value)

        for grade in self._grades:
            if grade != grade_to_be_removed:
                new_grade_list.append(grade)

        self._grades = new_grade_list

    def get_all(self):
        return self._grades

    def remove_grades_by_student_id(self, student_id):
        desired_grades_list = []

        for grade in self._grades:
            if grade.get_student_id != student_id:
                desired_grades_list.append(grade)

        self._grades = desired_grades_list

        self._save_to_file()
        return self._grades

    def remove_grades_by_discipline_id(self, discipline_id):
        desired_grades_list = []

        for grade in self._grades:
            if grade.get_discipline_id != discipline_id:
                desired_grades_list.append(grade)

        self._grades = desired_grades_list

        self._save_to_file()
        return self._grades

    def _save_to_file(self):
        pass


class TextFileGradeRepository(GradeRepository):
    def __init__(self, file_path):
        super().__init__()
        self.__file_path = file_path
        self._save_to_file()

    def __read_from_file(self):
        with open(self.__file_path, 'r') as file:
            for line in file:
                line = line.strip()

                if line == "":
                    continue

                discipline_id, student_id, grade_value = line.split("|")
                read_grade = Grade(discipline_id, student_id, grade_value)
                self._grades.append(read_grade)

    def __to_string(self):
        saved_format = ""

        for grade in self._grades:
            saved_format += (str(grade.get_discipline_id) + "|" + str(grade.get_student_id) +
                             "|" + str(grade.get_grade_value) + "\n")

        return saved_format

    def _save_to_file(self):
        with open(self.__file_path, "w") as file:
            file.truncate(0)
            file.write(self.__to_string())


class GradeRepositoryBinaryFile(GradeRepository):
    def __init__(self, file_path):
        super().__init__()
        self.__file_path = file_path
        self._save_to_file()

    def __read_from_file(self):
        file = open(self.__file_path, "rb")
        self._grades = pickle.load(file)
        file.close()

    def __len__(self):
        return len(self._grades)

    def _save_to_file(self):
        file = open(self.__file_path, "wb")
        pickle.dump(self._grades, file)
        file.close()
