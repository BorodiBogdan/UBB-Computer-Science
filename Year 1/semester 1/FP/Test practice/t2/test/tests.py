from unittest import TestCase
from services.services import Services


class Test(TestCase):
    def setUp(self):
        self.__services = Services()
        self.__services.generate_taxis(10)

    def test_add_ride(self):
        self.__services.add_ride(10, 10, 20, 20)
        self.assertEqual(len(self.__services.get_all_taxis()), 10)
        self.__services.add_ride(10, 10, 20, 20)
        self.assertEqual(len(self.__services.get_all_taxis()), 10)
        self.__services.add_ride(15, 10, 20, 20)
        self.assertEqual(len(self.__services.get_all_taxis()), 10)



