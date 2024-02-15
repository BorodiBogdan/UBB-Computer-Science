from src.services.DisciplineService import DisciplineService
from src.services.StudentService import StudentService
from src.services.GradeService import GradeService
from src.repository.RepositoryError import RepositoryError
from src.PropertiesParser import ParseProperties


class Ui:
    @staticmethod
    def print_elements(list_of_elements):
        print("---------------------------------------------")
        for element in list_of_elements:
            print(str(element))
            print("---------------------------------------------")

    def __init__(self):
        self.__discipline_service = DisciplineService(ParseProperties.find_discipline_repo())
        self.__student_service = StudentService(ParseProperties.find_student_repo())
        self.__grade_service = GradeService(ParseProperties.find_grade_repo())
        list_of_student_ids = self.__student_service.get_all_students_id()
        list_of_discipline_ids = self.__discipline_service.get_all_disciplines_ids()
        self.__grade_service.generate_random_grades(list_of_student_ids, list_of_discipline_ids)

    def menage_students(self):
        print("1. Add student")
        print("2. Remove student")
        print("3. Update student")
        print("4. List all students")
        ADD_STUDENT = '1'
        REMOVE_STUDENT = '2'
        UPDATE_STUDENT = '3'
        LIST_ALL_STUDENTS = '4'

        chosen_option = input("Enter option: ")
        try:
            if chosen_option == ADD_STUDENT:
                student_id = input("Enter student id: ")
                self.__student_service.check_if_student_exist(student_id)
                name = input("Enter name: ")
                self.__student_service.add_student(student_id, name)
            elif chosen_option == REMOVE_STUDENT:
                student_id = input("Enter student id: ")
                self.__grade_service.remove_grades_by_student_id(student_id)
                self.__student_service.remove_student(student_id)
            elif chosen_option == UPDATE_STUDENT:
                student_id = input("Enter student id: ")
                name = input("Enter the new name: ")
                self.__student_service.update_student(student_id, name)
            elif chosen_option == LIST_ALL_STUDENTS:
                student_list = self.__student_service.get_all_students()
                self.print_elements(student_list)
        except RepositoryError as re:
            print(re)

    def menage_disciplines(self):
        print("1. Add discipline")
        print("2. Remove discipline")
        print("3. Update discipline")
        print("4. List all disciplines")

        chosen_option = input("Enter option: ")

        ADD_DISCIPLINE = '1'
        REMOVE_DISCIPLINE = '2'
        UPDATE_DISCIPLINE = '3'
        LIST_ALL_DISCIPLINES = '4'

        try:
            if chosen_option == ADD_DISCIPLINE:
                discipline_id = input("Enter discipline id: ")
                self.__discipline_service.check_if_discipline_does_not_exists(discipline_id)
                name = input("Enter name: ")
                self.__discipline_service.add_discipline(discipline_id, name)
            elif chosen_option == REMOVE_DISCIPLINE:
                discipline_id = input("Enter discipline id: ")
                self.__grade_service.remove_grades_by_discipline_id(discipline_id)
                self.__discipline_service.remove_discipline(discipline_id)
            elif chosen_option == UPDATE_DISCIPLINE:
                discipline_id = input("Enter discipline id: ")
                name = input("Enter the new name: ")
                self.__discipline_service.update_discipline(discipline_id, name)
            elif chosen_option == LIST_ALL_DISCIPLINES:
                discipline_list = self.__discipline_service.get_all_disciplines()
                self.print_elements(discipline_list)
        except RepositoryError as re:
            print(re)

    def grade_student(self):
        try:
            student_id = input("Enter student id: ")
            discipline_id = input("Enter discipline id: ")
            grade_value = input("Enter grade value: ")

            self.__student_service.check_if_student_does_not_exist(student_id)
            self.__discipline_service.check_if_discipline_exist(discipline_id)
            self.__grade_service.add_grade(discipline_id, student_id, grade_value)

        except RepositoryError as re:
            print(re)
        except ValueError:
            print("Invalid grade value")

    def search_for_students(self):
        print("1. Search for students based on ID")
        print("2. Search for students based on name")
        chosen_option = input("Choose an option: ")

        SEARCH_BY_ID = '1'
        SEARCH_BY_NAME = '2'

        try:
            if chosen_option == SEARCH_BY_ID:
                chosen_id = input("Enter id: ")
                self.__student_service.check_if_student_does_not_exist(chosen_id)
                desired_student = self.__student_service.get_student_by_id(chosen_id)

                print(str(desired_student))

            if chosen_option == SEARCH_BY_NAME:
                chosen_name = input("Enter name: ").lower()
                self.__student_service.check_if_name_exists(chosen_name)
                desired_students = self.__student_service.get_all_students_by_name(chosen_name)
                self.print_elements(desired_students)

        except RepositoryError as re:
            print(re)

    def search_for_disciplines(self):
        print("1. Search for disciplines based on ID")
        print("2. Search for disciplines based on name")
        chosen_option = input("Choose an option: ")

        SEARCH_BY_ID = '1'
        SEARCH_BY_NAME = '2'

        try:
            if chosen_option == SEARCH_BY_ID:
                chosen_id = input("Enter id: ").lower()
                self.__discipline_service.check_if_discipline_exist(chosen_id)
                desired_discipline = self.__discipline_service.get_discipline_by_id(chosen_id)

                print(str(desired_discipline))
            if chosen_option == SEARCH_BY_NAME:
                chosen_name = input("Enter name: ").lower()
                self.__discipline_service.check_if_name_of_discipline_does_not_exist(chosen_name)
                list_of_desired_disciplines = self.__discipline_service.get_all_disciplines_by_name(chosen_name)

                self.print_elements(list_of_desired_disciplines)
        except RepositoryError as re:
            print(re)

    def display_statistics(self):
        print("1. Display failing students")
        print("2. Display students with the best school situation")
        print("3. Display all disciplines at which there is at least one grade, sorted in descending order of the "
              "average grades received by all students")

        chosen_option = input("Choose an option: ")

        DISPLAY_FAILING_STUDENTS = '1'
        DISPLAY_STUDENTS_WITH_BEST_SCHOOL_SITUATION = '2'
        DISPLAY_DISCIPLINES_SORTED_BY_AVERAGE = '3'

        try:
            if chosen_option == DISPLAY_FAILING_STUDENTS:
                failing_students_id = self.__grade_service.get_failing_students()

                print("---------------------------------------------")
                for student_id in failing_students_id:
                    print(str(self.__student_service.get_student_by_id(student_id)))
                    print("---------------------------------------------")
            if chosen_option == DISPLAY_STUDENTS_WITH_BEST_SCHOOL_SITUATION:
                best_students_id = self.__grade_service.get_students_with_the_best_school_situation_in_descending_order()
                print("---------------------------------------------")
                for student_id_and_grade in best_students_id:
                    print("Mean: " + str(student_id_and_grade[1]))
                    print(str(self.__student_service.get_student_by_id(student_id_and_grade[0])))
                    print("---------------------------------------------")
            if chosen_option == DISPLAY_DISCIPLINES_SORTED_BY_AVERAGE:
                disciplines_id_and_mean = self.__grade_service.get_disciplines_sorted_by_average()

                print("---------------------------------------------")

                for discipline_id_and_mean in disciplines_id_and_mean:
                    print("Mean: " + str(discipline_id_and_mean[1]))
                    print(str(self.__discipline_service.get_discipline_by_id(discipline_id_and_mean[0])))
                    print("---------------------------------------------")

        except RepositoryError as re:
            print(re)

    def print_ui(self):
        MENAGE_STUDENTS = '1'
        MENAGE_DISCIPLINES = '2'
        GRADE_STUDENT = '3'
        SEARCH_FOR_STUDENTS = '4'
        SEARCH_FOR_DISCIPLINES = '5'
        DISPLAY_STATISTICS = '6'
        EXIT = '0'

        while True:
            print("1. Manage students")
            print("2. Manage disciplines")
            print("3. Grade student")
            print("4. Search for students")
            print("5. Search for disciplines")
            print("6. Display statistics")

            chosen_option = input("Enter option: ")

            if chosen_option == MENAGE_STUDENTS:
                self.menage_students()
            elif chosen_option == MENAGE_DISCIPLINES:
                self.menage_disciplines()
            elif chosen_option == GRADE_STUDENT:
                self.grade_student()
            elif chosen_option == SEARCH_FOR_STUDENTS:
                self.search_for_students()
            elif chosen_option == SEARCH_FOR_DISCIPLINES:
                self.search_for_disciplines()
            elif chosen_option == DISPLAY_STATISTICS:
                self.display_statistics()
            elif chosen_option == EXIT:
                exit()
