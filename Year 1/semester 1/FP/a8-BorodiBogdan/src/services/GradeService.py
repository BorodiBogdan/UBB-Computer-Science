import random
from copy import deepcopy


class GradeService:
    def __init__(self, repository):
        self.__grade_repository = repository

    def add_grade(self, student_id, discipline_id, grade_value):
        self.__grade_repository.add_grade(student_id, discipline_id, grade_value)

    def get_all_grades(self):
        return self.__grade_repository.get_all()

    def remove_grades_by_student_id(self, student_id):
        self.__grade_repository.remove_grades_by_student_id(student_id)

    def remove_grades_by_discipline_id(self, discipline_id):
        return self.__grade_repository.remove_grades_by_discipline_id(discipline_id)

    def generate_random_grades(self, student_id_list: list, subject_id_list: list):
        RANGE = 50

        for random_number in range(RANGE):
            student_id = random.choice(student_id_list)
            subject_id = random.choice(subject_id_list)
            grade = random.randint(1, 10)

            self.__grade_repository.add_grade(subject_id, student_id, grade)

    def __transform_data_to_dictionary_with_keys_student_id_and_discipline_id(self):
        """
        we make this transformation to be easier to work with the data
        It's easier to compute the statitstics this way
        :return: a dictionary with the keys being the student.txt id and the discipline.txt id
        """
        student_dictionary = {}

        for grade in self.__grade_repository.get_all():
            student_id_and_discipline = (grade.get_student_id, grade.get_discipline_id)

            if student_id_and_discipline not in student_dictionary.keys():
                #in case we do not have the key in the dictionary
                student_dictionary[student_id_and_discipline] = []

            student_dictionary[student_id_and_discipline].append(grade.get_grade_value)

        return deepcopy(student_dictionary)

    def get_failing_students(self):
        transformed_data_to_dictonary = deepcopy(self.__transform_data_to_dictionary_with_keys_student_id_and_discipline_id())
        failing_students = []
        STUDENT_ID_INDEX = 0

        for student_id_and_discipline in transformed_data_to_dictonary:
            discipline_average_mean = 0

            for grade in transformed_data_to_dictonary[student_id_and_discipline]:
                discipline_average_mean += grade

            number_of_grades = len(transformed_data_to_dictonary[student_id_and_discipline])

            discipline_average_mean /= number_of_grades

            id_of_failing_student = student_id_and_discipline[STUDENT_ID_INDEX]

            if(discipline_average_mean < 5 and id_of_failing_student not in failing_students):
                failing_students.append(id_of_failing_student)

        return failing_students

    def get_students_with_the_best_school_situation_in_descending_order(self):
        transformed_data_to_dictionary = deepcopy(self.__transform_data_to_dictionary_with_keys_student_id_and_discipline_id())
        student_average_grades = {}
        STUDENT_ID_INDEX = 0

        for student_id_and_discipline in transformed_data_to_dictionary:
            discipline_grades_mean = 0

            for grade in transformed_data_to_dictionary[student_id_and_discipline]:
                discipline_grades_mean += grade

            number_of_grades = len(transformed_data_to_dictionary[student_id_and_discipline])

            discipline_grades_mean /= number_of_grades

            id_of_student = student_id_and_discipline[STUDENT_ID_INDEX]

            if id_of_student not in student_average_grades.keys():
                #in case the student.txt has no grades
                student_average_grades[id_of_student] = []

            student_average_grades[id_of_student].append(discipline_grades_mean)

        #now we need to calculate the average of the averages
        final_student_average_grades = {}

        for student_id in student_average_grades:
            discipline_grades_mean = 0

            for grade in student_average_grades[student_id]:
                discipline_grades_mean += grade

            number_of_grades = len(student_average_grades[student_id])

            discipline_grades_mean /= number_of_grades

            final_student_average_grades[student_id] = discipline_grades_mean

        AGREGATED_AVERAGE_GRADE_INDEX = 1
        sorted_student_list = sorted(final_student_average_grades.items(), key=lambda item: item[AGREGATED_AVERAGE_GRADE_INDEX], reverse=True)

        return sorted_student_list

    def get_disciplines_sorted_by_average(self):
        transformed_data_to_dictionary = deepcopy(self.__transform_data_to_dictionary_with_keys_student_id_and_discipline_id())
        discipline_average_grades = {}
        DISCIPLINE_ID_INDEX = 1

        for student_id_and_discipline in transformed_data_to_dictionary:
            mean = 0

            for grade in transformed_data_to_dictionary[student_id_and_discipline]:
                mean += grade

            number_of_grades = len(transformed_data_to_dictionary[student_id_and_discipline])

            mean /= number_of_grades

            discipline_id = student_id_and_discipline[DISCIPLINE_ID_INDEX]

            if discipline_id not in discipline_average_grades.keys():
                discipline_average_grades[discipline_id] = mean
            else:
                discipline_average_grades[discipline_id] += mean
                discipline_average_grades[discipline_id] /= 2

        AVERAGE_GRADE = 1
        return sorted(discipline_average_grades.items(), key=lambda item: item[AVERAGE_GRADE], reverse=True)
