from Services import *


class Ui:
    def __init__(self):
        self.__service = Services()

    def run_ui(self):
        while True:
            try:
                print("1. Display all buses travelling across a certain route")
                print("2. Given a bus id display how many km has travelled")
                print("3. Display all bus routes, sorted descending by the total milleage of all buses in that route")

                chosen_option = input("Chose option: ")

                if chosen_option == "1":
                    route_code = int(input("Enter route code: "))
                    list_of_buses = self.__service.get_all_buses_from_a_certain_route(route_code)

                    for bus in list_of_buses:
                        print(str(bus))
                elif chosen_option == "2":
                    bus_id = int(input("Enter bus id: "))

                    print(self.__service.get_traversed_kilometers(bus_id))
                elif chosen_option == "3":
                    sorted_list_of_routes = self.__service.get_sorted_list_of_routes()

                    for route in sorted_list_of_routes:
                        print("Information about the route: " + str(route))
    
                        print("Buses on the route: ")
                        list_of_buses = self.__service.get_all_buses_from_a_certain_route(route.route_code)

                        for bus in list_of_buses:
                            print(str(bus))

                        print("")
            except Exception as ve:
                print(ve)
