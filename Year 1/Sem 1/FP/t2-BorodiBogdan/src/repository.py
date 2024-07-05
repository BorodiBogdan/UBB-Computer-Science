from src.domain import Assignment


class Repository:
    def __init__(self, file_path):
        self.__list_of_assignments = []
        self.__file_path = file_path
        self.__read_from_file()

    def get_all(self):
        return self.__list_of_assignments

    def get_all_ids(self):
        list_of_ids = []

        for assignment in self.__list_of_assignments:
            list_of_ids.append(assignment.student_id)

        return list_of_ids

    def add_assignment(self, student_id, name, solution):
        """
        we create a new student
        all parameters are already verified
        we save the new student in memory
        we save to file because we need all students
        new_student = the student we need to add
        :param student_id:
        :param name:
        :param solution:
        :return:
        """
        new_student = Assignment(int(student_id), name, solution)
        self.__list_of_assignments.append(new_student)
        self.__save_to_file()

    def __read_from_file(self):
        with open(self.__file_path, "r") as file:
            for line in file:
                line = line.strip()

                if line == "":
                    continue

                student_id, name, solution = line.split(",")
                self.add_assignment(student_id, name, solution)

            file.close()

    def __save_to_file(self):
        """
        we parse the file where we store the information
        saved_format = the format in which we store the information
        file = the opened file in writing mode
        :return none
        """
        with open(self.__file_path, "w") as file:
            file.truncate(0)
            saved_format = ""

            for assignment in self.__list_of_assignments:
                saved_format += str(assignment) + "\n"

            file.write(saved_format)
            file.close()
