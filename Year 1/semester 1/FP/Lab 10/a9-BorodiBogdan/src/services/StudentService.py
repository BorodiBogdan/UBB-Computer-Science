import random
from src.domain.commandthatcanbecalled import *

class StudentService:
    def __init__(self, student_repository, grade_repository, undo_service):
        self.__student_repository = student_repository
        self.__grade_repository = grade_repository
        self.UndoRedoService = undo_service
        self.__generate_random_students()

    def __generate_random_students(self):
        list_of_names = ["Adelina", "Bogdan", "Claudia", "Doru", "Elena", "Florin", "Georgeta", "Horia", "Ioana",
                        "Jean", "Katia", "Luca", "Maria", "Norbert", "Ofelia", "Paul", "Raluca", "Sergiu", "Tara",
                        "Ulise", "Victoria"]

        RANGE = 20

        for random_number in range(RANGE):
            student_id = str(random.randint(random_number * 10 + 1, (random_number + 1) * 10))
            student_name = random.choice(list_of_names)
            self.add_student(student_id, student_name)

    def add_student(self, student_id, student_name):
        self.__student_repository.add_student(student_id, student_name)
        UndoCommand = CommandThatCanBeCalled(self.__student_repository.remove_student, (student_id))
        RedoCommand = CommandThatCanBeCalled(self.__student_repository.add_student, *(student_id, student_name))
        UndoRedoCommand = [Operation(UndoCommand, RedoCommand)]
        self.UndoRedoService.register_operation(OperationThatCascades(UndoRedoCommand))

    def get_all_students(self):
        return self.__student_repository.get_all_students()

    def get_student_by_id(self, student_id):
        return self.__student_repository.get_student_by_id(student_id)

    def get_all_students_id(self):
        return self.__student_repository.get_all_students_ids()

    def get_student_name(self, student_id):
        list_of_student = self.__student_repository.get_all_students()

        for student in list_of_student:
            if student.get_student_id == student_id:
                return student.get_student_name


    def remove_student(self, student_id):
        list_of_commands = []
        UndoOperation = CommandThatCanBeCalled(self.__student_repository.add_student, *(student_id, self.get_student_name(student_id)))
        RedoOperation = CommandThatCanBeCalled(self.__student_repository.remove_student, student_id)
        OperationForRedoUndo = Operation(UndoOperation, RedoOperation)

        list_of_commands.append(OperationForRedoUndo)

        self.__student_repository.remove_student(student_id)
        grades_list = self.__grade_repository.get_all()

        for grade in grades_list:
            if grade.get_student_id == student_id:
                UndoOperation = CommandThatCanBeCalled(self.__grade_repository.add_grade, *(grade.get_discipline_id, grade.get_student_id, grade.get_grade_value))
                RedoOperation = CommandThatCanBeCalled(self.__grade_repository.remove_grade, *(grade.get_discipline_id, grade.get_student_id, grade.get_grade_value))
                OperationForRedoUndo = Operation(UndoOperation, RedoOperation)
                list_of_commands.append(OperationForRedoUndo)
                self.__grade_repository.remove_grade(grade.get_discipline_id, grade.get_student_id, grade.get_grade_value)


        self.UndoRedoService.register_operation(OperationThatCascades(list_of_commands))

    def update_student(self, student_id, name):
        RedoCommand = CommandThatCanBeCalled(self.__student_repository.update_student_by_id, *(student_id, name))
        UndoCommand = CommandThatCanBeCalled(self.__student_repository.update_student_by_id, *(student_id, self.get_student_name(student_id)))

        UndoRedoCommand = [Operation(UndoCommand, RedoCommand)]
        self.UndoRedoService.register_operation(OperationThatCascades(UndoRedoCommand))

        self.__student_repository.update_student_by_id(student_id, name)

    def check_if_student_exist(self, student_id):
        return self.__student_repository.check_if_present(student_id)

    def check_if_student_does_not_exist(self, student_id):
        return self.__student_repository.check_if_not_present(student_id)

    def check_if_name_exists(self, name_to_be_checked):
        return self.__student_repository.check_if_name_exists(name_to_be_checked)

    def get_all_students_by_name(self, searched_name):
        student_list = self.__student_repository.get_all_students()
        desired_students_list = []

        for student in student_list:
            if student.get_student_name == searched_name:
                desired_students_list.append(student)

        return desired_students_list
