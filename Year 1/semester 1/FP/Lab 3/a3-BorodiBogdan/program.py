from random import  randint
import time
def Heapify(ListToBeSorted : list, ListLength : int, CurrentNode : int) -> list:#tell the node
    LeftSon = 2 * CurrentNode + 1
    RightSon = 2 * CurrentNode + 2
    largestNode = CurrentNode

    if(LeftSon < ListLength and ListToBeSorted[largestNode] < ListToBeSorted[LeftSon]):
        largestNode = LeftSon

    if (RightSon < ListLength and ListToBeSorted[largestNode] < ListToBeSorted[RightSon]):
        largestNode = RightSon

    if(largestNode != CurrentNode):
        ListToBeSorted[largestNode], ListToBeSorted[CurrentNode]  = ListToBeSorted[CurrentNode], ListToBeSorted[largestNode]
        Heapify(ListToBeSorted, ListLength, largestNode)

    return ListToBeSorted
def HeapSort(ListToBeSorted : list, step : int) -> list:
    step_counter = 0

    if(step == -1):
        step = 1e9

    ListLength = len(ListToBeSorted)

    for node in range(ListLength // 2 - 1, -1, -1):#we heapify every node, except the leafes
        Heapify(ListToBeSorted, ListLength, node)          # (because you don't have any another node to compare them with)
        step_counter += 1

        if (step_counter % step == 0):
            print("step " + str(step_counter) + ": " + str(ListToBeSorted))

    for node in range(ListLength - 1, -1, -1):
        ListToBeSorted[0], ListToBeSorted[node] = ListToBeSorted[node], ListToBeSorted[0]
        ListToBeSorted = Heapify(ListToBeSorted, node, 0)
        step_counter += 1

        if(step_counter % step == 0):
            print("step " + str(step_counter) + ": "+ str(ListToBeSorted))

    return ListToBeSorted

def Generate_Best_HeapSort_Case(List_Length : int) -> list:#in order to have the best case, our list have just equal elents in orfer to not perform the heapify
    ListToBeGenerated = []

    for ListElement in range(0, List_Length):
        ListToBeGenerated.append(100)

    return ListToBeGenerated

def Generate_Average_HeapSort_Case(List_Length) -> list:
    ListToBeGenerated = []
    ListToBeGenerated = Generate_Random_Array(List_Length)

    return ListToBeGenerated

def Generate_Worst_HeapSort_Case(List_Length) -> list:#we index the array as a min heap
    ListToBeGenerated = [0] * List_Length
    ListToBeGenerated[0] = List_Length ** 100

    for CurrentNode in range(0, (List_Length - 1) // 2):
        LeftSon = CurrentNode * 2 + 1
        RightSon = CurrentNode * 2 + 2

        if(LeftSon <= List_Length):
            ListToBeGenerated[LeftSon] = ListToBeGenerated[CurrentNode] + 100
        if (RightSon <= List_Length):
            ListToBeGenerated[RightSon] = ListToBeGenerated[CurrentNode] + 200


    return ListToBeGenerated

def Generate_Best_Selection_Case(List_Length : int) -> list:
    ListToBeGenerated = [*range(1, List_Length + 1, 1)]

    return  ListToBeGenerated
def Generate_Worst_Selection_Case(List_Length : int) -> list:
    ListToBeGenerated = []

    for ListElement in range(List_Length, 0, -1):
        ListToBeGenerated.append(ListElement ** 7)

    return ListToBeGenerated

def Generate_Average_Selection_Case(List_Length) -> list:
    ListToBeGenerated = Generate_Random_Array(List_Length)

    return ListToBeGenerated
def Selection_Sort(ListToBeSorted : list, step : int) -> list:
    if (step == -1):
        step = 1e9

    step_counter = 0
    ListLength = len(ListToBeSorted)

    for i in range(0, ListLength):#i
        min_index = i
        min_element = current_element = ListToBeSorted[i]

        step_counter += 1

        for j in range (i + 1, ListLength):#j
            if(min_element > ListToBeSorted[j]):
                min_index = j
                min_element = ListToBeSorted[j]

        ListToBeSorted[i], ListToBeSorted[min_index] = min_element, current_element

        if(step != 1e9 and step_counter % step == 0):
            print("step " + str(step_counter) + ": "+ str(ListToBeSorted))

    return  ListToBeSorted
def Generate_Random_Array(LengthOfTheList : int) -> list:

    ListToBeGenerated = []
    for index in range (0, LengthOfTheList):
        ListToBeGenerated.append(randint(1, 100))

    return ListToBeGenerated

def Count_Time_Taken_To_Execute(ListToBeGenerated : list, Initial_Length : int, Chosen_Case : int, Chosen_Sort : int):
    Length = Initial_Length
    start = time.time()

    if (Chosen_Sort == 4):
        if (Chosen_Case == 1):
            ListToBeGenerated = Generate_Worst_Selection_Case(Length)
            Selection_Sort(ListToBeGenerated, -1)
        elif (Chosen_Case == 2):
            ListToBeGenerated = Generate_Average_Selection_Case(Length)
            Selection_Sort(ListToBeGenerated, -1)
        elif (Chosen_Case == 3):
            ListToBeGenerated = Generate_Best_Selection_Case(Length)
            Selection_Sort(ListToBeGenerated, -1)

    if (Chosen_Sort == 5):
        if (Chosen_Case == 1):
            ListToBeGenerated = Generate_Worst_HeapSort_Case(Length)
            HeapSort(ListToBeGenerated, -1)
        elif (Chosen_Case == 2):
            ListToBeGenerated = Generate_Average_HeapSort_Case(Length)
            HeapSort(ListToBeGenerated, -1)
        elif (Chosen_Case == 3):
            ListToBeGenerated = Generate_Best_HeapSort_Case(Length)
            HeapSort(ListToBeGenerated, -1)

    end = time.time()

    return (end - start)
def ReadInput(Input) -> int:
    try:
        return int(Input)
    except:
        print("Invalid input")
        return ReadInput(input("Enter the input again: "))

while(True):

    Numbers_List = []
    Time_Test_List = []

    print("Choose your option:")
    print("1 - Generate a random array of length n")
    print("2 - Sort the array using Selection Sort it after n steps")
    print("3 - Sort the array using HeapSort and display it after n steps")
    print("4 - Show runtime for Selection Sort in the worst case, average case or best case")
    print("5 - Show runtime for Heap Sort in the worst case, average case or best case")
    print("6 - Display the Array")
    print("7 - Exit program")

    while (True):
        chosen_option = input("Choose your option: ")

        try:
            chosen_option = int(chosen_option)
        except:
            print("Invalid input")

        if (chosen_option == 1):
            Numbers_ListLength = ReadInput(input("Enter the length of the list: "))
            Numbers_List = Generate_Random_Array(Numbers_ListLength)
            print("The random list is: " + str(Numbers_List))
        elif (chosen_option == 2):
            step = ReadInput(input("Enter the number of steps: "))
            Numbers_List = Selection_Sort(Numbers_List, step)
            print("The sorted array is: " + str(Numbers_List))
        elif (chosen_option == 3):
            step = ReadInput(input("Enter the number of steps: "))
            Numbers_List = HeapSort(Numbers_List, step)
            print("The sorted list is: " + str(Numbers_List))
        elif (chosen_option == 4 or chosen_option == 5):
            print("Choose the case you want to study:")
            print("1 - Worst Case")
            print("2 - Average Case")
            print("3 - Best Case")

            chosen_case = ReadInput(input(">>"))

            while(chosen_case > 3 or chosen_case < 0):#for invalid input
                print("Invalid input")
                chosen_case = ReadInput(input("Enter the input again:"))

            LengthToBeTested = 500

            if(chosen_option == 5):#we have heap sort
                LengthToBeTested = 4000

            for multiplier in range (2, 7):
                print("The elapsed time for " +  str(LengthToBeTested) + " elements is: " + str(Count_Time_Taken_To_Execute(Time_Test_List, LengthToBeTested, chosen_case, chosen_option)))
                LengthToBeTested = LengthToBeTested * 2

        elif (chosen_option == 6):
            print("The list is : " + str(Numbers_List))
        elif(chosen_option == 7):
            exit()