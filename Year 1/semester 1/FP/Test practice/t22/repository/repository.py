from domain.domain import Homework


class Repository:
    def __init__(self, file_path):
        self.__list_of_assignments = []
        self.__file_path = file_path
        self.read_from_file()

    def add_assignment(self, id: int, name: str, solution: str):
        """

        :param id:
        :param name:
        :param solution:
        we create a homework object using id name and solution and add it to the list
        then we save it to the file
        """
        self.__list_of_assignments.append(Homework(id, name, solution))
        self.save_to_file()

    def read_from_file(self):
        with open(self.__file_path, "r") as file:
            for line in file:
                line = line.strip()

                if line == "":
                    continue

                id, name, solution = line.split(",")

                self.add_assignment(id, name, solution)

            file.close()

    def save_to_file(self):
        """
        we save to a file the list of homeworks
        :return:
        """
        saved_format = ""

        for assignment in self.__list_of_assignments:
            saved_format += str(assignment) + "\n"

        with open(self.__file_path, "w") as file:
            file.truncate(0)
            file.write(saved_format)
            file.close()

    def get_ids(self):
        ids = []

        for assignment in self.__list_of_assignments:
            ids.append(int(assignment.id))

        return ids

    def get_assignments(self):
        return self.__list_of_assignments
