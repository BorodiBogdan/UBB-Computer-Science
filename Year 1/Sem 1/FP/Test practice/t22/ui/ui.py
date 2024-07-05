from services.services import Service


class Ui:
    def __init__(self):
        self.__services = Service()

    def run_ui(self):
        print("1. Add an assignment")
        print("2. Display all assignments")
        print("3. Dishonesty check")
        print("0. Exit")

        ADD_ASSIGNMENT = "1"
        DISPLAY_ASSIGNMENTS = "2"
        DISHONESTY_CHECK = "3"
        EXIT = "0"

        while True:
            try:
                chosen_option = input("Choose option: ")

                if chosen_option == ADD_ASSIGNMENT:
                    id = int(input("Enter id: "))
                    name = input("Enter name: ")
                    solution = input("Enter solution: ")

                    self.__services.add_assignment(id, name, solution)
                elif chosen_option == DISPLAY_ASSIGNMENTS:
                    list_of_assignments = self.__services.get_all_assignments()

                    for assignment in list_of_assignments:
                        print(str(assignment))
                elif chosen_option == DISHONESTY_CHECK:
                    list_of_dishonest_students = self.__services.honesty_check_array()

                    for element in list_of_dishonest_students:
                        print(element[0] + " " + element[1] + "(" + str(element[2]) + "% of " + element[1] + "'s solution)")
                elif chosen_option == EXIT:
                    exit()
            except ValueError as ve:
                print(ve)