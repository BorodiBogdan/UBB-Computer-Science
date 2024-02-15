from src.domain.discipline import Discipline
from src.repository.RepositoryError import RepositoryError
import pickle


class DisciplineRepository:
    def __init__(self):
        self._list_of_disciplines = []

    def check_if_the_id_is_not_present(self, checked_id):#error if the id is present
        for discipline in self._list_of_disciplines:
            if discipline.get_discipline_id == checked_id:
                raise RepositoryError("This instance is already in the repository")

    def check_if_the_id_is_present(self, checked_id):#error if the id is not present
        for discipline in self._list_of_disciplines:
            if discipline.get_discipline_id == checked_id:
                return True

        raise RepositoryError("This instance is not in the repository")

    def check_if_the_name_is_present(self, chosen_name):#Error if the name is not present
        for discipline in self._list_of_disciplines:
            if discipline.get_discipline_name == chosen_name:
                return True

        raise RepositoryError("Invalid name!!")

    def add_discipline(self, discipline_id, name):
        student = Discipline(discipline_id, name)
        self._list_of_disciplines.append(student)
        self._save_to_file()

    def remove_discipline_with_given_id(self, removed_id):
        updated_discipline_list = []

        for discipline in self._list_of_disciplines:
            if discipline.get_discipline_id != removed_id:
                updated_discipline_list.append(discipline)

        self._list_of_disciplines = updated_discipline_list
        self._save_to_file()

    def get_all_disciplines(self):
        return self._list_of_disciplines

    def get_discipline_by_id(self, discipline_id):
        for discipline in self._list_of_disciplines:
            if discipline.get_discipline_id == discipline_id:
                return discipline


    def get_all_disciplines_ids(self):
        list_of_ids = []
    
        for discipline in self._list_of_disciplines:
            list_of_ids.append(discipline.get_discipline_id)
    
        return list_of_ids

    def get_all_disciplines_with_a_particular_name(self, name):
        name = name.lower()
        list_filtered_by_name = []

        for discipline in self._list_of_disciplines:
            if name in discipline.get_discipline_name.lower():
                list_filtered_by_name.append(discipline)

        return list_filtered_by_name

    def update_disciplines_id(self, discipline_id, new_name):
        new_discipline = Discipline(discipline_id, new_name)
        updated_list = []

        for element in self._list_of_disciplines:
            if element.get_discipline_id == discipline_id:
                element = new_discipline

            updated_list.append(element)

        self._save_to_file()
        self._list_of_disciplines = updated_list

    def _save_to_file(self):
        pass


class TextFileDisciplineRepository(DisciplineRepository):
    def __init__(self, file_path):
        super().__init__()
        self.__file_path = file_path
        self._save_to_file()

    def __read_from_file(self):
        with open(self.__file_path, 'r') as file:
            for line in file:
                line = line.strip()

                if line == "":
                    continue

                discipline_id, discipline_name = line.split("|")
                read_discipline = Discipline(discipline_id, discipline_name)
                self._list_of_disciplines.append(read_discipline)

    def __to_string(self):
        saved_format = ""

        for discipline in self._list_of_disciplines:
            saved_format += (str(discipline.get_discipline_id) + "|" + str(discipline.get_discipline_name) + "\n")

        return saved_format

    def _save_to_file(self):
        with open(self.__file_path, "w") as file:
            file.truncate(0)
            file.write(self.__to_string())


class DisciplineRepositoryBinaryFile(DisciplineRepository):
    def __init__(self, file_path):
        super().__init__()
        self.__file_path = file_path
        self._save_to_file()

    def __read_from_file(self):
        file = open(self.__file_path, "rb")
        self._list_of_disciplines = pickle.load(file)
        file.close()

    def __len__(self):
        return len(self._list_of_disciplines)

    def _save_to_file(self):
        file = open(self.__file_path, "wb")
        pickle.dump(self._list_of_disciplines, file)
        file.close()
