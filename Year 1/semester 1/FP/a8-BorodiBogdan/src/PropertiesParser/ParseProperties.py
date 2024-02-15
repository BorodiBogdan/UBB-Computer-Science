from src.repository.DisciplineRepository import *
from src.repository.GradeRepository import *
from src.repository.StudentRepository import *
from jproperties import Properties


def find_grade_repo():
    configs = Properties()

    with open("settings.properties", "rb") as config_file:
        configs.load(config_file)

        repository = configs.get("REPOSITORY").data
        location = configs.get("GRADE").data

        if(repository == "InMemory"):

            return GradeRepository()
        elif(repository == "TextFile"):
            return TextFileGradeRepository(location)
        elif(repository == "PickleFile"):
            return GradeRepositoryBinaryFile(location)

def find_student_repo():
    configs = Properties()

    with open("settings.properties", "rb") as config_file:
        configs.load(config_file)

        repository = configs.get("REPOSITORY").data
        location = configs.get("STUDENT").data

        if(repository == "InMemory"):
            return StudentRepository()
        elif(repository == "TextFile"):
            return TextFileStudentRepository(location)
        elif(repository == "PickleFile"):
            return StudentRepositoryBinaryFile(location)

def find_discipline_repo():
    configs = Properties()

    with open("settings.properties", "rb") as config_file:
        configs.load(config_file)

        repository = configs.get("REPOSITORY").data
        location = configs.get("DISCIPLINE").data
        if(repository == "InMemory"):

            return DisciplineRepository()
        elif(repository == "TextFile"):
            return TextFileDisciplineRepository(location)
        elif(repository == "PickleFile"):
            return DisciplineRepositoryBinaryFile(location)

print(find_grade_repo())