from src.services.DisciplineService import DisciplineService
from src.services.StudentService import StudentService
from src.services.GradeService import GradeService
from src.repository.RepositoryError import RepositoryError

class Test:
    def __init__(self):
        self.__student_service = StudentService()
        self.__discipline_service = DisciplineService()
        self.__grade_service = GradeService()

    def test_add_student(self):
        self.__student_service.add_student("1", "John")
        assert len(self.__student_service.get_all_students()) == 21
        self.__student_service.add_student("2", "Mary")
        assert len(self.__student_service.get_all_students()) == 22
        try:
            self.__student_service.add_student("1", "John")
            assert True
        except RepositoryError:
            assert False

    def test_remove_student(self):
        self.__student_service.add_student("1000", "John")
        self.__student_service.add_student("2", "Mary")
        self.__student_service.remove_student("1000")
        assert len(self.__student_service.get_all_students()) == 24

    def test_add_discipline(self):
        self.__discipline_service.add_discipline("1", "Math")
        assert len(self.__discipline_service.get_all_disciplines()) == 15
        self.__discipline_service.add_discipline("2", "English")
        assert len(self.__discipline_service.get_all_disciplines()) == 16

    def test_remove_discipline(self):
        self.__discipline_service.add_discipline("1111", "Math")
        self.__discipline_service.add_discipline("21", "English")
        self.__discipline_service.remove_discipline("1111")
        assert len(self.__discipline_service.get_all_disciplines()) == 17

    def test_all(self):
        self.test_add_student()
        self.test_remove_student()
        self.test_add_discipline()
        self.test_remove_discipline()
        print("All tests passed")