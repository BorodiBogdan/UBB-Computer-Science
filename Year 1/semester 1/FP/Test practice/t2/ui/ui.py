from services.services import Services


class Ui:
    def __init__(self):
        self.__services = Services()

    def display_taxis(self):
        list_of_taxis = self.__services.get_taxis_in_good_order()

        for taxi in list_of_taxis:
            print(str(taxi))

    def run_ui(self):
        taxis = int(input("Insert how many taxis are there: "))
        self.__services.generate_taxis(taxis)

        print("1. Add ride")
        print("2. Simulate a ride")
        ADD_RIDE = "1"
        SIMULATE_RIDE = "2"

        while True:
            try:
                chosen_option = input("Choose option: ")

                if chosen_option == SIMULATE_RIDE:
                    self.__services.simulate_ride()
                    self.display_taxis()
                elif chosen_option == ADD_RIDE:
                    x_start = int(input("choose x for start location: "))
                    y_start = int(input("choose y for start location: "))
                    x_end = int(input("choose x for end  location: "))
                    y_end = int(input("choose y for end location: "))
                    self.__services.add_ride(x_start, y_start, x_end, y_end)
                    self.display_taxis()
            except ValueError as ve:
                print(ve)