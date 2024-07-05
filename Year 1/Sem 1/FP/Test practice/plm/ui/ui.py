from services.services import Service
ADD_STUDENT = "1"
DISPLAY_STUDENTS_DECREASINGLY = "2"
GIVE_BONUSES = "3"
DISPLAY_ALL_STUDENTS_PARTIAL_STRING = "4"
EXIT = "0"


class UI:
    def __init__(self):
        self.__service = Service()

    def ui_menu(self):
        print("1. Add a new_student")
        print("2. Display students in decreasing order of their grade")
        print("3 Give bonuses")
        print("4 Display all students whose name include a given string")
        print("0. Exit")
        chosen_option = input("Chose:option: ")

        if chosen_option == ADD_STUDENT:
            id = int(input("Id: "))
            name = input("Name: ")
            attendance = int(input("Attendance: "))
            grade = int(input("Grade "))

            self.__service.add_student(id, name, attendance, grade)
        elif chosen_option == DISPLAY_STUDENTS_DECREASINGLY:
            student_list = self.__service.get_decreasing_sorted_student_list()

            for student in student_list:
                print(student)
        elif chosen_option == GIVE_BONUSES:
            number_of_attendances = int(input("Minimum attendance number: "))
            bonus = int(input("Bonus points: "))

            self.__service.give_bonus(number_of_attendances, bonus)
        elif chosen_option == DISPLAY_ALL_STUDENTS_PARTIAL_STRING:
            given_string = input("Partial string: ")
            student_list = self.__service.get_students_that_include_a_given_string_in_name(given_string)

            for student in student_list:
                print(student)

    def run_ui(self):
         while True:
            try:
                self.ui_menu()
            except ValueError as ve:
                print(ve)
