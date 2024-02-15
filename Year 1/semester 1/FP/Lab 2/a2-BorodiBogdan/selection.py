#selection and heap sort

ArrayLength = input("Enter array's length: ")
Array = []

try:
    ArrayLength = int(ArrayLength)
except:
    print("Invalid input")
    exit()

for index in range(0, ArrayLength):
    ArrayElement = input(">>Enter Number: ")
    try:
        Array.append(int(ArrayElement))
    except:
        print("Invalid input")
        exit()


for index1 in range(0, ArrayLength):
    min_index = index1
    min_element = current_element = Array[index1]

    for index2 in range (index1 + 1, ArrayLength):
        if(min_element > Array[index2]):
            min_index = index2
            min_element = Array[index2]

    Array[index1], Array[min_index] = min_element, current_element

for element in Array:
    print(element, end = " ", sep = " ")
