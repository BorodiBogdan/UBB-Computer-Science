from src.services import Services


class Ui:
    def __init__(self):
        self.__service = Services()

    def run_ui(self):
        print("0. Exit")
        print("1. Add assignment")
        print("2. Display assignment")
        print("3. Dishonesty check")

        ADD_ASSIGNMENT = "1"
        DISPLAY_ASSIGNMENTS = "2"
        DISHONESTY_CHECK = "3"
        EXIT = "0"

        while True:
            try:
                chosen_option = input("Choose option: ")

                if chosen_option == ADD_ASSIGNMENT:
                    student_id = input("Enter student id: ")
                    name = input("Enter name: ")
                    solution = input("Enter solution: ")

                    self.__service.add_assignment(student_id, name, solution)
                elif chosen_option == DISPLAY_ASSIGNMENTS:
                    assignments = self.__service.get_all()

                    for assignment in assignments:
                        print(str(assignment))
                elif chosen_option == DISHONESTY_CHECK:
                    list_of_dishonest_assignments = self.__service.get_list_of_dishonest_students()

                    student1 = 0
                    student2 = 1
                    percentage = 2

                    for dishonest_information in list_of_dishonest_assignments:
                        print(f"{dishonest_information[student1]}, {dishonest_information[student2]} -> ({dishonest_information[percentage]}% of {dishonest_information[student2]}'s solution)")
                elif chosen_option == EXIT:
                    exit()
                else:
                    print("Invalid input!")
            except ValueError as ve:
                print(ve)
