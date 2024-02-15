import random
from src.domain.commandthatcanbecalled import *


class DisciplineService:
    def __init__(self, discipline_repository, grade_repository, undo_service):
        self.__discipline_repository = discipline_repository
        self.UndoRedoService = undo_service
        self.__grade_repository = grade_repository
        self.generate_random_subjects()

    def generate_random_subjects(self):
        list_of_disciplines = ["Mathematical Analysis", "Computational Logic", "Algebra", "Fundamentals of Programming",
                               "Computer System Architecture", "Object Oriented Programming", "Dynamical Systems",
                               "Geometry", "Operating Systems", "Data Structures and Algorithms", "Graphs",
                               "Advanced Programming Methods", "Databases", "Statistics"]

        RANGE = 14

        for random_number in range(RANGE):
            random_id = str(random.randint(random_number * 10 + 1, (random_number + 1) * 10))
            self.add_discipline(random_id, list_of_disciplines[random_number])

    def add_discipline(self, discipline_id, discipline_name):
        UndoCommand = CommandThatCanBeCalled(self.remove_discipline, (discipline_id))
        RedoCommand = CommandThatCanBeCalled(self.add_discipline, *(discipline_id, discipline_name))
        UndoRedoCommand = [Operation(UndoCommand, RedoCommand)]
        self.UndoRedoService.register_operation(OperationThatCascades(UndoRedoCommand))

        self.__discipline_repository.add_discipline(discipline_id, discipline_name)

    def remove_discipline(self, discipline_id):
        list_of_commands = []
        UndoOperation = CommandThatCanBeCalled(self.__discipline_repository.add_discipline, *(discipline_id, self.get_discipline_name(discipline_id)))
        RedoOperation = CommandThatCanBeCalled(self.__discipline_repository.remove_discipline_with_given_id, *(discipline_id))
        UndoRedoCommand = Operation(UndoOperation, RedoOperation)
        self.__discipline_repository.remove_discipline_with_given_id(discipline_id)

        list_of_commands.append(UndoRedoCommand)
        self.__discipline_repository.remove_discipline_with_given_id(discipline_id)
        grades_list = self.__grade_repository.get_all()

        for grade in grades_list:
            if str(grade.get_discipline_id) == str(discipline_id):
                UndoOperation = CommandThatCanBeCalled(self.__grade_repository.add_grade, *(grade.get_discipline_id, grade.get_student_id, grade.get_grade_value))
                RedoOperation = CommandThatCanBeCalled(self.__grade_repository.remove_grade, *(grade.get_discipline_id, grade.get_student_id, grade.get_grade_value))
                UndoRedoCommand = Operation(UndoOperation, RedoOperation)
                list_of_commands.append(UndoRedoCommand)

                self.__grade_repository.remove_grade(grade.get_discipline_id, grade.get_student_id, grade.get_grade_value)

        self.UndoRedoService.register_operation(OperationThatCascades(list_of_commands))

    def update_discipline(self, discipline_id, new_name):
        RedoCommand = CommandThatCanBeCalled(self.update_discipline, *(discipline_id, new_name))
        UndoCommand = CommandThatCanBeCalled(self.update_discipline, *(discipline_id, self.get_discipline_name(discipline_id)))

        UndoRedoCommand = [Operation(UndoCommand, RedoCommand)]
        self.UndoRedoService.register_operation(OperationThatCascades(UndoRedoCommand))

        self.__discipline_repository.update_disciplines_id(discipline_id, new_name)

    def get_discipline_name(self, discipline_id):
        list_of_disciplines = self.__discipline_repository.get_all_disciplines()

        for discipline in list_of_disciplines:
            if str(discipline.get_discipline_id) == str(discipline_id):
                return discipline.get_discipline_name

    def get_all_disciplines(self):
        return self.__discipline_repository.get_all_disciplines()

    def check_if_discipline_does_not_exists(self, discipline_id):
        return self.__discipline_repository.check_if_the_id_is_not_present(discipline_id)

    def check_if_discipline_exist(self, discipline_id):
        return self.__discipline_repository.check_if_the_id_is_present(discipline_id)

    def get_discipline_by_id(self, chosen_id):
        return self.__discipline_repository.get_discipline_by_id(chosen_id)

    def get_all_disciplines_ids(self):
        return self.__discipline_repository.get_all_disciplines_ids()

    def check_if_name_of_discipline_does_not_exist(self, chosen_name):
        return self.__discipline_repository.check_if_the_name_is_present(chosen_name)

    def get_all_disciplines_by_name(self, chosen_name):
        return self.__discipline_repository.get_all_disciplines_with_a_particular_name(chosen_name)
