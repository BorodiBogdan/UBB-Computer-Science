class Bus:
    def __init__(self, bus_id: int, route_code: int, model: str, times_used_on_the_route: int):
        self.__bus_id = bus_id
        self.__route_code = route_code
        self.__model = model
        self.__times_used_on_the_route = times_used_on_the_route

    def __str__(self):
        return f"{self.__bus_id},{self.__route_code},{self.__model},{self.__times_used_on_the_route}"

    @property
    def bus_id(self):
        return self.__bus_id

    @property
    def route_code(self):
        return self.__route_code

    @property
    def model(self):
        return self.__model

    @property
    def times_used_on_the_route(self):
        return self.__times_used_on_the_route


class BusRoute:
    def __init__(self, route_code: int, length_in_kilometers: int):
        self.__route_code = route_code
        self.__length_in_kilometers = length_in_kilometers

    def __str__(self):
        return f"{self.__route_code},{self.__length_in_kilometers}"

    @property
    def route_code(self):
        return self.__route_code

    @property
    def length_in_kilometers(self):
        return self.__length_in_kilometers
