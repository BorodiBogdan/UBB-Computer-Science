from  random import  randint
def DisplayAllElementsOfTheGeneratedSubset(Element_Of_The_Subset : list, NumbersList : list, NumbersListLength : int, LengthOfTheSubset : int):
    for index in range (0, LengthOfTheSubset + 1):
        print(NumbersList[ Element_Of_The_Subset[index] ], end = " ")

    print("")

def Verify_If_Subset_Sum_Is_Divisible_By_GivenNumber(Element_Of_The_Subset : list, NumbersList : list, LengthOfTheSubset : int, GivenNumber : int) -> bool:
    sumOfNumbers = 0

    for index in range (0, LengthOfTheSubset + 1):
        sumOfNumbers += NumbersList[ Element_Of_The_Subset[index] ]

    if(sumOfNumbers % GivenNumber == 0):
        return True
    return False

def Generate_All_SubSets_Divisible_By_GivenNumber(GeneratedSubset : list, NumbersList : list, NumbersListLength : int, LengthOfTheSubset : int, GivenNumber : int):
    for Element_Index in range (GeneratedSubset[LengthOfTheSubset - 1] + 1, NumbersListLength):
        GeneratedSubset[LengthOfTheSubset] = Element_Index

        if(Verify_If_Subset_Sum_Is_Divisible_By_GivenNumber(GeneratedSubset, NumbersList, LengthOfTheSubset, GivenNumber)):
            DisplayAllElementsOfTheGeneratedSubset(GeneratedSubset, NumbersList, NumbersListLength, LengthOfTheSubset)

        if(LengthOfTheSubset + 1 < NumbersListLength):
            Generate_All_SubSets_Divisible_By_GivenNumber(GeneratedSubset, NumbersList, NumbersListLength, LengthOfTheSubset + 1, GivenNumber)

        GeneratedSubset[LengthOfTheSubset] = 0


while True:
    print("Press 1 to generate a test and other key to exit")

    Chosen_Option = input(">>")

    if(Chosen_Option == "1"):
        LengthOfTheArray = 6

        GeneratedSubset = [0] * (LengthOfTheArray + 2)
        GeneratedSubset[-1] = -1

        print("n is: " + str(LengthOfTheArray))
        GeneratedList = [99, 90, 47, 32, 52, 15]

        print("The list is: " + str(GeneratedList))

        Generate_All_SubSets_Divisible_By_GivenNumber(GeneratedSubset, GeneratedList, len(GeneratedList), 0, LengthOfTheArray)
    else:
        exit()