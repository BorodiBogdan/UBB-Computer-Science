from repository.repository import Repository


class Service:
    def __init__(self):
        self.__repository = Repository("file.txt")

    def add_assignment(self, id: int, student_name: str, solution: str):
        """
        here  we add students to the repository
        we check if the parameters respect the task
        :param id: id of student
        :param student_name:
        :param solution:
        :return:
        """

        if id in self.__repository.get_ids():
            raise ValueError("id already exists!")

        if len(student_name) < 3:
            raise ValueError("incorrect name!")

        if len(solution) == 0:
            raise ValueError("String is empty!")

        self.__repository.add_assignment(id, student_name, solution)

    def get_all_assignments(self):
        return self.__repository.get_assignments()

    def honesty_check_array(self):
        length_of_assignment_array = len(self.__repository.get_assignments())
        assignment_list = self.__repository.get_assignments()
        honesty_array = []

        for index1 in range(length_of_assignment_array):
            for index2 in range(index1 + 1, length_of_assignment_array):
                student1 = assignment_list[index1]
                student2 = assignment_list[index2]
                words_for_first_student = student1.solution.split(" ")
                words_for_second_student = student2.solution.split(" ")
                words_used = 0

                for word in words_for_second_student:
                    if word in words_for_first_student:
                        words_used += 1

                percentage = (100 / len(words_for_second_student)) * words_used

                if percentage > 20:
                    honesty_array.append((student1.student_name, student2.student_name, percentage))
                    continue

                words_used = 0

                for word in words_for_first_student:
                    if word in words_for_second_student:
                        words_used += 1

                percentage = (100 / len(words_for_first_student)) * words_used

                if percentage > 20:
                    honesty_array.append((student2.student_name, student1.student_name, percentage))
                    continue

        return honesty_array
