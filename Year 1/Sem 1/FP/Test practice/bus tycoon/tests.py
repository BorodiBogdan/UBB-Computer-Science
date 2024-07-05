from Services import Services
import unittest


class Test(unittest.TestCase):
    def setUp(self):
        self.__services = Services()

    def test_get_traversed_kilometers(self):
        self.assertEqual(self.__services.get_traversed_kilometers(3), 91)
        self.assertEqual(self.__services.get_traversed_kilometers(2), 130)
        self.assertEqual(self.__services.get_traversed_kilometers(1), 30)

    def test_milleage(self):
        self.assertTrue(self.__services.get_milleage_dict())
        self.assertEqual(len(self.__services.get_milleage_dict()), 3)

