from random import randint
#
# Write the implementation for A5 in this file
#
PLUS = "+"
MINUS = "-"
# 
# Write below this comment 
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def Create_Complex_Number(RealPartOfTheComplexNumber : int, ImaginaryPartOfTheComplexNumber : int) -> list:
    return (RealPartOfTheComplexNumber, ImaginaryPartOfTheComplexNumber)

def Equal(ComplexNumber1, ComplexNumber2):
    return ComplexNumber1 == ComplexNumber2

def CheckIfTheIntegerIsPositiveOrNegative(Integer : int):
    if(Integer >= 0):
        return PLUS
    else:
        return MINUS

def Real_Part(ComplexNumber : list):
    return ComplexNumber[0]

def Imaginary_Part(ComplexNumber : list):
    return ComplexNumber[1]

def AllDigitsOfAnInteger(Integer : int):
    Integer = abs(Integer)
    DigitsOfTheInteger = set()

    if(Integer < 9):
        DigitsOfTheInteger.add(Integer)
        Integer //= 10

    while(Integer > 0):
        DigitsOfTheInteger.add(Integer % 10)
        Integer //= 10

    return DigitsOfTheInteger


    return DigitsOfTheInteger
def AllDigitsOfTheComplexNumber(complex_number : list):
    digits_of_the_real_part = AllDigitsOfAnInteger(complex_number[0])
    digits_of_the_imaginary_part = AllDigitsOfAnInteger(complex_number[1])

    digits_of_complex_number = digits_of_the_real_part.union(digits_of_the_imaginary_part)

    return digits_of_complex_number

def to_str(complex_number : list) -> str:
    sign_of_the_imaginary_part = CheckIfTheIntegerIsPositiveOrNegative(complex_number[1])

    return str(abs(complex_number[0])) + " " + sign_of_the_imaginary_part + " " + str(abs(complex_number[1])) + "i"

#
# Write below this comment 
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

"""
def Create_Complex_Number(RealPartOfTheComplexNumber : int, ImaginaryPartOfTheComplexNumber : int) -> dict:
    return {"real" : RealPartOfTheComplexNumber, "imaginary" : ImaginaryPartOfTheComplexNumber}

def Equal(ComplexNumber1, ComplexNumber2):
    return ComplexNumber1 == ComplexNumber2

def CheckIfTheIntegerIsPositiveOrNegative(Integer : int):
    if(Integer >= 0):
        return PLUS
    else:
        return MINUS

def Real_Part(ComplexNumber : dict):
    return ComplexNumber["real"]

def Imaginary_Part(ComplexNumber : dict):
    return ComplexNumber["imaginary"]
    
def AllDigitsOfAnInteger(Integer : int):
    Integer = abs(Integer)
    DigitsOfTheInteger = set()

    if(Integer < 9):
        DigitsOfTheInteger.add(Integer)
        Integer //= 10

    while(Integer > 0):
        DigitsOfTheInteger.add(Integer % 10)
        Integer //= 10
        
    return DigitsOfTheInteger
    
def AllDigitsOfTheComplexNumber(complex_number : dict):
    digits_of_the_real_part = AllDigitsOfAnInteger(complex_number["real"])
    digits_of_the_imaginary_part = AllDigitsOfAnInteger(complex_number["imaginary"])

    digits_of_complex_number = digits_of_the_real_part.union(digits_of_the_imaginary_part)

    return digits_of_complex_number

def to_str(complex_number : dict) -> str:
    sign_of_the_imaginary_part = CheckIfTheIntegerIsPositiveOrNegative(complex_number["imaginary"])

    return str(abs(complex_number["real"])) + " " + sign_of_the_imaginary_part + " " + str(abs(complex_number["imaginary"])) + "i"
"""
#
# Write below this comment 
# Functions that deal with subarray/subsequence properties
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

MINIMUM_VALUE = -100
MAXIMUM_VALUE = 100

def generate_complex_numbers(Dimension_Of_The_generated_List: int) -> list:
    Generated_List_Of_Complex_Numbers = []

    while Dimension_Of_The_generated_List > 0:
        RealPartOfTheComplexNumber = randint(MINIMUM_VALUE, MAXIMUM_VALUE)
        ImaginaryPartOfTheComplexNumber = randint(MINIMUM_VALUE, MAXIMUM_VALUE)
        Generated_List_Of_Complex_Numbers.append(Create_Complex_Number(RealPartOfTheComplexNumber, ImaginaryPartOfTheComplexNumber))
        Dimension_Of_The_generated_List -= 1

    return Generated_List_Of_Complex_Numbers
def Length_and_elements_of_a_longest_subarray_of_numbers_where_both_their_real_and_imaginary_parts_can_be_written_using_the_same_base_10_digits(List_Of_Complex_Numbers : list):
    MaximumLengthOfASubarrayOfNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits = 0
    SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits = []
    good_subarray = []
    DigitsStorage = {}

    for complex_number in List_Of_Complex_Numbers:
        digits = tuple(AllDigitsOfTheComplexNumber(complex_number))

        if(digits not in DigitsStorage):
            DigitsStorage.clear()
            SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits.clear()
            SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits.append(to_str(complex_number))
            DigitsStorage[digits] = 1
        else:
            SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits.append(to_str(complex_number))

        if(len(SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits) > MaximumLengthOfASubarrayOfNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits):
            MaximumLengthOfASubarrayOfNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits = len(SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits)
            good_subarray = SubarrayOfMaximumLengthWithNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits[:]

    return { "max_length" : MaximumLengthOfASubarrayOfNumbersWhereBothTheirReaAndImaginaryPartsCanBeWrittenUsingTheSameBase10Digits, "subarray": good_subarray}

def LengthAndElementsOfTheLongestAlternatingSubsequence(List_Of_Complex_Numbers : list):
    LengthOfComplexNumberList = len(List_Of_Complex_Numbers)
    MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition = [[0 for j in range(LengthOfComplexNumberList)] for i in range(2)]
    MaximumLengthAlternatingSubarrayEndingOnThIthPosition = [[[] for j in range(LengthOfComplexNumberList)] for i in range(2)]

    RealPartOfTheComplexNumber = [Real_Part(Complex_number) for Complex_number in List_Of_Complex_Numbers]

    MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][0] = MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][0] = 1
    MaximumLengthAlternatingSubarrayEndingOnThIthPosition[0][0].append(List_Of_Complex_Numbers[0])
    MaximumLengthAlternatingSubarrayEndingOnThIthPosition[1][0].append(List_Of_Complex_Numbers[0])

    for i in range (1, LengthOfComplexNumberList):
        for j in range (i - 1, -1, -1):
            if(RealPartOfTheComplexNumber[i] < RealPartOfTheComplexNumber[j]):
                if(MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][i] < MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][j] + 1):
                    MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][i] = MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][j] + 1
                    MaximumLengthAlternatingSubarrayEndingOnThIthPosition[0][i] = MaximumLengthAlternatingSubarrayEndingOnThIthPosition[1][j][:]
                    MaximumLengthAlternatingSubarrayEndingOnThIthPosition[0][i].append(List_Of_Complex_Numbers[i])
            elif(RealPartOfTheComplexNumber[i] > RealPartOfTheComplexNumber[j]):
                if (MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][i] < MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][j] + 1):
                    MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][i] = MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][j] + 1
                    MaximumLengthAlternatingSubarrayEndingOnThIthPosition[1][i] = MaximumLengthAlternatingSubarrayEndingOnThIthPosition[0][j][:]
                    MaximumLengthAlternatingSubarrayEndingOnThIthPosition[1][i].append(List_Of_Complex_Numbers[i])

    MaximumLengthOfAnAlternatingSubarray = 0
    MaximumLengthAlternatingSubarray = []

    for i in range(0, LengthOfComplexNumberList):
        if(MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][i] > MaximumLengthOfAnAlternatingSubarray):
            MaximumLengthOfAnAlternatingSubarray = MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[0][i]
            MaximumLengthAlternatingSubarray = MaximumLengthAlternatingSubarrayEndingOnThIthPosition[0][i][:]

        if (MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][i] > MaximumLengthOfAnAlternatingSubarray):
            MaximumLengthOfAnAlternatingSubarray = MaximumLengthOfAnAlternatingSubarrayEndingOnTheIthPosition[1][i]
            MaximumLengthAlternatingSubarray = MaximumLengthAlternatingSubarrayEndingOnThIthPosition[1][i][:]

    return MaximumLengthOfAnAlternatingSubarray, MaximumLengthAlternatingSubarray
#
# Write below this comment 
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities
#
def Print_longest_subarray_and_his_length_where_both_their_real_and_imaginary_parts_can_be_written_using_the_same_base_10_digits(List_Of_Complex_Numbers):
    InfomationAboutTheLongestSubarrayWhereRealAndImaginaryPartOfCanBeWrittenUsingTheSameBase10Digits = Length_and_elements_of_a_longest_subarray_of_numbers_where_both_their_real_and_imaginary_parts_can_be_written_using_the_same_base_10_digits(List_Of_Complex_Numbers)

    print("The maximum length is: " + str(InfomationAboutTheLongestSubarrayWhereRealAndImaginaryPartOfCanBeWrittenUsingTheSameBase10Digits['max_length']))

    print("The subarray is: ", end = "")

    for ElementOfTheSubarray in InfomationAboutTheLongestSubarrayWhereRealAndImaginaryPartOfCanBeWrittenUsingTheSameBase10Digits["subarray"]:
        print(ElementOfTheSubarray, end = ", ")

    print()

def PrintLengthAndElementsOfTheLongestAlternatingSubsequence(List_Of_Complex_Numbers):
    StoreLengthAndElementsOfTheLongestAlternatingSubsequence = LengthAndElementsOfTheLongestAlternatingSubsequence(List_Of_Complex_Numbers)

    print ("The length and elements of a longest alternating subsequence, when considering each number's real part is: " + str(StoreLengthAndElementsOfTheLongestAlternatingSubsequence[0]))

    print("This is the longest alternating subsequence, when considering each number's real part: ", end = "")

    Show_List_Of_Complex_Numbers(StoreLengthAndElementsOfTheLongestAlternatingSubsequence[1])

def Read_Complex_Number():
    print("Read complex number as z = a + bi: ")

    RealPartOfComplexNumber = int(input("a = "))
    ImaginaryPartOfComplexNumber = int(input("b = "))

    return Create_Complex_Number(RealPartOfComplexNumber, ImaginaryPartOfComplexNumber)

def Print_Complex_Number(ComplexNumber):
    print(to_str(ComplexNumber), end ="")

def Add_Complex_Number_In_A_List(ListOfComplexNumbers : list):
    try:
        new_complex_number = Read_Complex_Number()

        for complex_number in ListOfComplexNumbers:
            if(Equal(new_complex_number, complex_number)):
                print("Duplicate complex number")
                return

        ListOfComplexNumbers.append(new_complex_number)
    except:
        print("Error reading rectangle")

def Show_List_Of_Complex_Numbers(ListOfComplexNumbers : list):
    for complex_number in ListOfComplexNumbers:
        Print_Complex_Number(complex_number)
        print(", ", end = "")

    print()

def ComplexNumbersApplicationMenu():
    List_Of_Complex_Numbers = generate_complex_numbers(10)

    ADD_COMPLEX_NUMBER = "1"
    SHOW_LIST_OF_COMPLEX_NUMBERS = "2"
    PRINT_LENGTH_AND_ELEMENTS_OF_LONGEST_SUBARRAY_FROM_TASK_3 = "3"
    PRINT_LONGEST_ALTERNATING_SUBSEQUENCE_AND_THE_LENGTH_OF_IT = "4"
    EXIT = "0"

    while True:
        # main program loop
        print("ADD_COMPLEX_NUMBER: Read a complex number (in z = a + bi form) from the console and add into to the list")
        print("SHOW_LIST_OF_COMPLEX_NUMBERS: Display the entire list of numbers on the console.")
        print("PRINT_LENGTH_AND_ELEMENTS_OF_LONGEST_SUBARRAY_FROM_TASK_3: Print length and elements of a longest subarray of numbers where both their real and imaginary parts can be written using the same base 10")
        print("PRINT_LONGEST_ALTERNATING_SUBSEQUENCE_AND_THE_LENGTH_OF_IT: Print the length and elements of a longest alternating subsequence, when considering each number's real part")
        print("0. Exit")

        option = input(">")
        print()

        if option == ADD_COMPLEX_NUMBER:
            Add_Complex_Number_In_A_List(List_Of_Complex_Numbers)
        elif option == SHOW_LIST_OF_COMPLEX_NUMBERS:
            Show_List_Of_Complex_Numbers(List_Of_Complex_Numbers)
        elif option == PRINT_LENGTH_AND_ELEMENTS_OF_LONGEST_SUBARRAY_FROM_TASK_3:
            Print_longest_subarray_and_his_length_where_both_their_real_and_imaginary_parts_can_be_written_using_the_same_base_10_digits(List_Of_Complex_Numbers)
        elif option == PRINT_LONGEST_ALTERNATING_SUBSEQUENCE_AND_THE_LENGTH_OF_IT:
            PrintLengthAndElementsOfTheLongestAlternatingSubsequence(List_Of_Complex_Numbers)
        elif option == EXIT:
            exit()
        else:
            print("Invalid input")

        print()

if __name__ == "__main__":
    ComplexNumbersApplicationMenu()