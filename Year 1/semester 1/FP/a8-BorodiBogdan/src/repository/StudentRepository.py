from src.domain.student import Student
from src.repository.RepositoryError import RepositoryError
import pickle

class StudentRepository:
    def __init__(self):
        self._list_of_students = []

    def check_if_present(self, checked_id):
        for student in self._list_of_students:
            if student.get_student_id == checked_id:
                raise RepositoryError("This instance is already in the repository")

    def check_if_not_present(self, checked_id):
        for student in self._list_of_students:
            if student.get_student_id == checked_id:
                return True

        raise RepositoryError("Id does not exist")

    def check_if_name_exists(self, checked_name):
        for student in self._list_of_students:
            if student.get_discipline_name == checked_name:
                return True

        raise RepositoryError("This name does not exist")

    def add_student(self, student_id, name):
        student = Student(student_id, name)
        self._list_of_students.append(student)
        self._save_to_file()

    def remove_student(self, removed_id):
        updated_student_list = []

        for student in self._list_of_students:
            if student.get_student_id != removed_id:
                updated_student_list.append(student)

        self._list_of_students = updated_student_list
        self._save_to_file()

    def get_all_students(self):
        return self._list_of_students

    def get_student_by_id(self, student_id):
        for student in self._list_of_students:
            if student.get_student_id == student_id:
                return student

    def get_all_students_ids(self):
        list_of_student_ids = []

        for student in self._list_of_students:
            list_of_student_ids.append(student.get_student_id)

        return list_of_student_ids

    def get_all_students_by_name(self, student_name):
        student_name = student_name.lower()
        list_of_students_filtered_by_name = []

        for student in self._list_of_students:
            if student_name in student.get_discipline_name.lower():
                list_of_students_filtered_by_name.append(student)

        return list_of_students_filtered_by_name

    def update_student_by_id(self, student_id, new_name):
        new_student = Student(student_id, new_name)
        updated_student_list = []

        for element in self._list_of_students:
            if element.get_student_id == student_id:
                element = new_student

            updated_student_list.append(element)

        self._list_of_students = updated_student_list
        self._save_to_file()
    def _save_to_file(self):
        pass

class TextFileStudentRepository(StudentRepository):
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

                student_id, student_name = line.split("|")
                read_student = Student(student_id, student_name)
                self._list_of_students.append(read_student)

    def __to_string(self):
        saved_format = ""

        for student in self._list_of_students:
            saved_format += (str(student.get_student_id) + "|" + str(student.get_student_name) + "\n")

        return saved_format

    def _save_to_file(self):
        with open(self.__file_path, "w") as file:
            file.truncate(0)
            file.write(self.__to_string())


class StudentRepositoryBinaryFile(StudentRepository):
    def __init__(self, file_path):
        super().__init__()
        self.__file_path = file_path
        self._save_to_file()

    def __read_from_file(self):
        file = open(self.__file_path, "rb")
        self._list_of_students = pickle.load(file)
        file.close()

    def __len__(self):
        return len(self._list_of_students)

    def _save_to_file(self):
        file = open(self.__file_path, "wb")
        pickle.dump(self._list_of_students, file)
        file.close()