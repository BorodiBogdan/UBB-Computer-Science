from random import  randint
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
def HeapSort(ListToBeSorted : list, step : int) -> list:
    step_counter = 0
    ListLength = len(ListToBeSorted)

    for node in range(ListLength // 2 - 1, -1, -1):#we heapify every node, except the leafes
        Heapify(ListToBeSorted, ListLength, node)          # (because you don't have any another node to compare them with)
        step_counter += 1

        if (step_counter % step == 0):
            print("step " + str(step_counter) + ": " + str(ListToBeSorted))

    for node in range(ListLength - 1, -1, -1):
        ListToBeSorted[0], ListToBeSorted[node] = ListToBeSorted[node], ListToBeSorted[0]
        Heapify(ListToBeSorted, node, 0)
        step_counter += 1

        if(step_counter % step == 0):
            print("step " + str(step_counter) + ": "+ str(ListToBeSorted))

    return ListToBeSorted

def Selection_Sort(ListToBeSorted : list, step : int) -> list:
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

        if(step_counter % step == 0):
            print("step " + str(step_counter) + ": "+ str(ListToBeSorted))

    return  ListToBeSorted
def Generate_Random_Array(ListToBeGenerated : list, LengthOfTheList : int) -> list:
    ListToBeGenerated.clear()
    for index in range (0, LengthOfTheList):
        ListToBeGenerated.append(randint(1, 100))

    return ListToBeGenerated

def ReadInput(Input) -> int:
    try:
        return int(Input)
    except:
        print("Invalid input")
        return ReadInput(input("Enter the input again: "))

print("Choose your option:")
print("1 - Generate a random array of length n")
print("2 - Sort the array using Selection Sort it after n steps")
print("3 - Sort the array using HeapSort and display it after n steps")
print("4 - Display the Array")
print("5 - Exit program")



while(True):

    Numbers_List = []

    while (True):
        chosen_option = input("Choose your option: ")

        try:
            chosen_option = int(chosen_option)
        except:
            print("Invalid input")

        if (chosen_option == 1):
            Numbers_ListLength = ReadInput(input("Enter the length of the list: "))
            Numbers_List = Generate_Random_Array(Numbers_List, Numbers_ListLength)
            print("The random list is: " + str(Numbers_List))
        elif (chosen_option == 2):
            step = ReadInput(input("Enter the number of steps: "))
            Numbers_List = Selection_Sort(Numbers_List, step)
            print("The sorted array is: " + str(Numbers_List))
        elif (chosen_option == 3):
            step = ReadInput(input("Enter the number of steps: "))
            Numbers_List = HeapSort(Numbers_List, step)
            print("The sorted list is: " + str(Numbers_List))
        elif (chosen_option == 4):
            print("The list is : " + str(Numbers_List))
        elif(chosen_option == 5):
            exit()