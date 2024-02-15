from repository import Repository


class Services:
    def __init__(self):
        self.__repository = Repository("file.txt")

    def add_assignment(self, student_id, name, solution):
        """

        :param student_id:
        :param name:
        :param solution:
        we check if the parameters are correct and throw an error otherwise
        we use the self.__repository in order to add the assignment to memory
        :return:
        """
        try:
            student_id = int(student_id)
        except ValueError:
            raise ValueError("Id must be an integer")

        if student_id in self.__repository.get_all_ids():
            raise ValueError("Id already in!")

        maximum_name_length = 3

        if len(name) < maximum_name_length:
            raise ValueError("Name too short!")

        if solution == "":
            raise ValueError("Empty string!")

        self.__repository.add_assignment(student_id, name, solution)

    def get_all(self):
        return self.__repository.get_all()

    @staticmethod
    def check_solutions(assignment1, assignment2):
        solution1 = assignment1.solution.split(" ")
        solution2 = assignment2.solution.split(" ")
        len_of_solution = len(solution2)
        word_counter = 0

        for word1 in solution1:
            for word2 in solution2:
                if word2 == word1:
                    word_counter += 1

        HUNDREAD_PERCENT = 100
        percentage = HUNDREAD_PERCENT / len_of_solution * word_counter

        return percentage

    def get_list_of_dishonest_students(self):
        resulting_list = []
        list_of_students = self.__repository.get_all()
        len_of_the_list = len(list_of_students)

        for index1 in range(0, len_of_the_list):
            for index2 in range(index1 + 1, len_of_the_list):
                assignment1 = list_of_students[index1]
                assignment2 = list_of_students[index2]
                MINIMUM_PERCENTAGE = 20

                if self.check_solutions(assignment1, assignment2) >= self.check_solutions(assignment2, assignment1):
                    name1 = assignment1.name
                    name2 = assignment2.name
                    percentage = self.check_solutions(assignment1, assignment2)
                else:
                    name1 = assignment2.name
                    name2 = assignment1.name
                    percentage = self.check_solutions(assignment2, assignment1)

                if percentage >= MINIMUM_PERCENTAGE:
                    resulting_list.append([name1, name2, percentage])

        return resulting_list
