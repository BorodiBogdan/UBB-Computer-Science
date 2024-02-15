from domain.domain import Taxi


class Repository:
    def __init__(self):
        self.__list_of_taxis = []

    def add_taxi(self, id, x, y, fare):
        if x < 0 or x > 100 or y < 0 or y > 100:
            raise ValueError("coordinates not in range")

        new_taxi = Taxi(id, x, y, fare)
        self.__list_of_taxis.append(new_taxi)

    def get_all_taxis(self):
        return self.__list_of_taxis

    def modify_taxi(self, id, x, y, fare):
        if x < 0 or x > 100 or y < 0 or y > 100:
            raise ValueError("coordinates not in range")

        for taxi in self.__list_of_taxis:
            if str(taxi.id) == str(id):
                taxi.set_coordinates(x, y)
                taxi.set_fare(taxi.fare + fare)
