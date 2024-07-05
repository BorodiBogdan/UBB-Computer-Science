from random import randint
def DisplayAllElementsOfTheGeneratedSubset(Element_Of_The_Subset : list, NumbersList : list, LengthOfTheSubset : int):
    for index in range (0, LengthOfTheSubset):
        print(NumbersList[ Element_Of_The_Subset[index] - 1 ], end = " ")

    print("")
def Verify_If_Subset_Sum_Is_Divisible_By_GivenNumber(Element_Of_The_Subset : list, NumbersList : list, LengthOfTheSubset : int, GivenNumber : int) -> bool:
    sumOfNumbers = 0

    for index in range (0, LengthOfTheSubset):
        sumOfNumbers += NumbersList[ Element_Of_The_Subset[index] - 1 ]

    if(sumOfNumbers % GivenNumber == 0):
        return True
    return False
def GenerateAllSubsetsInAscendingOrderAndDisplayThemIfTheyAreDivisibleByaGivenNumber(LengthOfTheSequence : int, NumbersList : list, GivenNumber : int):
    SubsetToBeChecked = []
    SubsetToBeChecked.append((0 , []))
    while(len(SubsetToBeChecked) > 0):
        nextElementToBeAdded = SubsetToBeChecked[-1][0] + 1
        SubsetOfTheSequence = SubsetToBeChecked[-1][1]
        SubsetToBeChecked.pop()


        if(nextElementToBeAdded <= LengthOfTheSequence):
            if(nextElementToBeAdded + 1 <= LengthOfTheSequence):
                SubsetToBeChecked.append((nextElementToBeAdded, SubsetOfTheSequence[:]))

            SubsetOfTheSequence.append(nextElementToBeAdded)

            if(Verify_If_Subset_Sum_Is_Divisible_By_GivenNumber(SubsetOfTheSequence, NumbersList, len(SubsetOfTheSequence), GivenNumber) == True and len(SubsetOfTheSequence) > 0):
                DisplayAllElementsOfTheGeneratedSubset(SubsetOfTheSequence, NumbersList, len(SubsetOfTheSequence))

            SubsetToBeChecked.append((nextElementToBeAdded, SubsetOfTheSequence[:]))

while True:
    print("Press 1 to generate a test and other key to exit")

    Chosen_Option = input(">>")

    if(Chosen_Option == "1"):
        LengthOfTheArray = randint(1, 7)
        print("n is: " + str(4))
        GeneratedList = [99, 90, 47, 32, 52, 15]

        print("The list is: " + str(GeneratedList))

        GenerateAllSubsetsInAscendingOrderAndDisplayThemIfTheyAreDivisibleByaGivenNumber(6, GeneratedList, 6)
    else:
        exit()