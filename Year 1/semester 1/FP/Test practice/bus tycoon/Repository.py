from domain import *


class BusRepository:
    def __init__(self, file_path):
        self._list_of_objects = []
        self._file_path = file_path
        self.read_from_file()

    def get_all(self):
        """
        we return the list with all objects from the repository
        :return:
        """
        return self._list_of_objects

    def add_object(self, line):
        bus_id, route_code, model, times_used = line.split(",")
        new_bus = Bus(int(bus_id), int(route_code), model, int(times_used))
        self._list_of_objects.append(new_bus)

    def read_from_file(self):
        with open(self._file_path, "r") as file:
            for line in file:
                line = line.strip()

                if line == "":
                    continue

                self.add_object(line)


class RouteRepository(BusRepository):
    def __init__(self, file_path):
        super().__init__(file_path)

    def add_object(self, line):
        route_code, length = line.split(",")
        new_route = BusRoute(int(route_code), length)
        self._list_of_objects.append(new_route)
