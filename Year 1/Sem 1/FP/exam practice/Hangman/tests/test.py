from service.service import Service
from repository.repository import Repository
import unittest


class Test(unittest.TestCase):
    def setUp(self):
        self.repository = Repository()
        self.service = Service(self.repository)

    def test_get_sentence(self):
        self.assertTrue(self.service.get_sentence in self.repository.get_all_sentences())
        self.assertTrue(self.service.get_sentence in self.repository.get_all_sentences())
        self.assertTrue(self.service.get_sentence in self.repository.get_all_sentences())

    def test_get_random_sentence(self):
        self.service.get_random_sentence()
        self.assertTrue(self.service.get_sentence in self.repository.get_all_sentences())
        self.service.get_random_sentence()
        self.assertTrue(self.service.get_sentence in self.repository.get_all_sentences())

    def test_add_sentence(self):
        length = len(self.repository.get_all_sentences())

        self.service.add_sentence("test test test")
        self.assertEqual(len(self.repository.get_all_sentences()), length + 1)

        try:
            self.service.add_sentence("yt t t")
            assert False
        except ValueError as ve:
            assert True

    def test_guess_letter(self):
        letter = self.service.get_sentence.sentence

        self.assertTrue(letter in self.service.get_sentence.sentence)
        self.service.guess_letter(letter)
        self.assertTrue(letter in self.service.get_sentence.public_letters)

    def test_check_if_won(self):
        self.assertFalse(self.service.check_if_won())

    def test_all_sentences(self):
        self.assertTrue(len(self.repository.get_all_sentences()) >= 5)
        self.repository.add_sentence("adas asd asd")
        self.assertTrue(len(self.repository.get_all_sentences()) >= 6)

    def repo_add_sentence(self):
        length = len(self.repository.get_all_sentences())
        self.repository.add_sentence("adas asd asd")
        self.assertTrue(length + 1 == self.repository.get_all_sentences())
