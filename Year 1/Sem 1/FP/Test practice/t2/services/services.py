from repository.repository import Repository
import random
from copy import deepcopy


class Services:
    def __init__(self):
        self.__repository = Repository()

    def check_distance(self, x_taxi, y_taxi):
        list_of_taxis = self.__repository.get_all_taxis()

        for taxi in list_of_taxis:
            x_taxi_from_list = taxi.x_coordinate
            y_taxi_from_list = taxi.y_coordinate

            distance = abs(x_taxi_from_list - x_taxi) + abs(y_taxi_from_list - y_taxi)

            if distance < 5:
                return False

        return True

    def generate_taxis(self, number_of_taxis):
        counter = 0
        aux = 0

        while aux < number_of_taxis:
            x_coordinate = random.randint(0, 100)
            y_coordinate = random.randint(0, 100)
            id = random.randint(counter, counter + 100)

            if self.check_distance(x_coordinate, y_coordinate):
                self.__repository.add_taxi(id, x_coordinate, y_coordinate, 0)
                counter = id
                aux += 1

    @staticmethod
    def distance(x_start, y_start, x_end, y_end) -> int:
        return abs(x_start - x_end) + abs(y_start - y_end)

    def get_closest_taxi_id(self, x, y):
        list_of_taxis = deepcopy(self.__repository.get_all_taxis())
        minimum_distance = 1000000000
        best_option = ""

        for taxi in list_of_taxis:
            if int(self.distance(taxi.x_coordinate, taxi.y_coordinate, x, y)) < int(minimum_distance):
                minimum_distance = int(self.distance(taxi.x_coordinate, taxi.y_coordinate, x, y))
                best_option = taxi

        return best_option.id

    def add_ride(self, x_start, y_start, x_end, y_end):
        closest_taxi_id = self.get_closest_taxi_id(x_start, y_start)
        total_distance = self.distance(x_start, y_end, x_end, y_end)
        self.__repository.modify_taxi(int(closest_taxi_id), int(x_end), int(y_end), total_distance)

    def simulate_ride(self):
        x_start = random.randint(0, 100)
        y_start = random.randint(0, 100)
        x_end = random.randint(0, 100)
        y_end = random.randint(0, 100)

        if self.distance(x_start, x_end, y_start, y_end) < 10:
            self.simulate_ride()
        else:
            self.add_ride(x_start, y_start, x_end, y_end)

    def get_taxis_in_good_order(self):
        list_of_taxis = self.__repository.get_all_taxis()

        new_list_of_taxis = sorted(list_of_taxis, key= lambda x: x.fare)

        return new_list_of_taxis

    def get_all_taxis(self):
        return self.__repository.get_all_taxis()
