from Repository import *


class Services:
    def __init__(self):
        self.__bus_repository = BusRepository("buses.txt")
        self.__route_repository = RouteRepository("bus_routes.txt")

    def get_all_buses_from_a_certain_route(self, route_code: int):
        list_of_buses = self.__bus_repository.get_all()
        displayed_list_of_buses = []

        for bus in list_of_buses:
            if bus.route_code == route_code:
                displayed_list_of_buses.append(bus)

        return displayed_list_of_buses

    def get_traversed_kilometers(self, bus_id):
        """
        we have a list of buses and a list of routes
        we find the route code of the bus based on the bus_id
        we iterate trough route_list and find the kilometers
        we multiply bus.times_on_the_route with the milleage of the route
        :param bus_id:
        :return: traversed kilometers
        """
        bus_id = int(bus_id)

        list_of_buses = self.__bus_repository.get_all()

        route_code = ""
        times_used = 0
        kilometers = 0

        list_of_routes = self.__route_repository.get_all()

        for bus in list_of_buses:
            if bus.bus_id == bus_id:
                route_code = bus.route_code
                times_used = bus.times_used_on_the_route

        for route in list_of_routes:
            if route.route_code == route_code:
                kilometers = int(times_used) * int(route.length_in_kilometers)

        return kilometers

    def get_milleage_dict(self):
        """
        we return a dict where we store the milleage in bus id
        it is easier to sort with this
        :return:
        """
        list_of_buses = self.__bus_repository.get_all()
        list_of_routes = self.__route_repository.get_all()

        milleage_dict = {}

        for route in list_of_routes:
            milleage_dict[route.route_code] = 0

        for bus in list_of_buses:
            milleage_dict[bus.route_code] += self.get_traversed_kilometers(bus.bus_id)

        return milleage_dict

    def get_sorted_list_of_routes(self):
        list_of_routes = self.__route_repository.get_all()
        help_for_sorting = self.get_milleage_dict()

        sorted_list_of_routes = sorted(list_of_routes, key=lambda x: help_for_sorting[x.route_code], reverse=True)

        return sorted_list_of_routes
