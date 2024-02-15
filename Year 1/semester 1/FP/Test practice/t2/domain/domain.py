

class Taxi:
    def __init__(self, id, x, y, fare):
        self.__id = id
        self.__fare = fare
        self.__coordinates = (x, y)

    @property
    def id(self):
        return self.__id

    @property
    def fare(self):
        return self.__fare

    @property
    def coordinates(self):
        return self.__coordinates

    def set_coordinates(self, x, y):
        self.__coordinates = (x, y)

    def set_fare(self, fare):
        self.__fare = fare

    @property
    def x_coordinate(self):
        return self.__coordinates[0]

    @property
    def y_coordinate(self):
        return self.__coordinates[1]

    def __str__(self):
        return "Taxi with id: " + str(self.__id) + " has coordinates: " + str(self.__coordinates) + " and fare: " + str(self.__fare)
