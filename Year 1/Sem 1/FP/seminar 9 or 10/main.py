from datetime import date
from unittest import TestCase
class Car:
    pass
class Client:
    """
    class Client has the following read-only properties
        -> id : int
        -> name : str

    class Client has the following methods
        __str__
        __eq__ (two clients are equal iif they have the same id)
    """
    def __init__(self, id : int, name : str):
        if type(id) != int:
            raise ValueError("id must be an integer")

        if type(name) != str:
            raise ValueError("name must be a string")

        self.__id = id
        self.__name = name

    def __eq__(self, other):
           return self.__id == other.__id

    def __str__(self):
        return str(self.__id) + " " + self.__name

    @property
    def id(self):
        return self.__id

    @property
    def name(self):
        return self.__name


class TestClient(TestCase):
    def testClient(self):
        c1 = Client(100, 'Bob')
        c2 = Client(11, 'Mihnea')

        self.assertEquals(c1.id, 100)
        self.assertEquals(c2.name, 'Mihnea')

        self.assertTrue(c1 == c2)
        self.assertEquals(str(c1), 'ID: 100; Name: Bob')
class Rental:
    def __init__(self, id : int, car : Car, client : Client , start : date, end : date):

        if type(id) != int:
            raise ValueError("id must be an integer")

        if type(start) != date:
            raise ValueError("start must be a date")

        if type(end) != date:
            raise ValueError("end must be a date")

        if type(car) != Car:
            raise ValueError("car must be a Car")

        if type(client) != Client:
            raise ValueError("client must be a Client")

        self.__id = id
        self.__car = car
        self.__client = client
        self.__start = start
        self.__end = end

    def __str__(self):
        return str(self.__id) + " " + str(self.__car) + " " + str(self.__client) + " " + str(self.__start) + " " + str(self.__end)

    def __len__(self):
        return (self.__end - self.__start).days + 1

    @property
    def id(self):
        return self.__id

    @property
    def car(self):
        return self.__car

    @property
    def client(self):
        return self.__client

    @property
    def start(self):
        return self.__start

    @property
    def end(self):
        return self.__end

    """
    class Rental has the following read-only properties
        -> id : int
        -> car : Car
        -> client : Client
        -> start, end : date

    class Rental has the following methods
        __str__
        __len__ (number of days for this Rental)
    """

class TestRental(TestCase):
    def testRental(self):
        c1 = Client(100, 'Bob')
        c2 = Client(11, 'Mihnea')
        car1 = Car(1, 'Audi')
        car2 = Car(2, 'BMW')
        r1 = Rental(1, car1, c1, date(2017, 12, 1), date(2017, 12, 5))
        r2 = Rental(2, car2, c2, date(2017, 12, 1), date(2017, 12, 5))

        self.assertEquals(r1.id, 1)
        self.assertEquals(r2.car, car2)
        self.assertEquals(r1.client, c1)
        self.assertEquals(r2.start, date(2017, 12, 1))
        self.assertEquals(r1.end, date(2017, 12, 5))

        self.assertEquals(str(r1), 'ID: 1; Car: Audi; Client: Bob; Start: 2017-12-01; End: 2017-12-05')
        self.assertEquals(len(r2), 5)