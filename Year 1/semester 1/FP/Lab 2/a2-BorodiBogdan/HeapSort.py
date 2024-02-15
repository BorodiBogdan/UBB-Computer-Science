def Heapify(Heap, ArrayLength, node):
    LeftSon = 2 * node
    RightSon = 2 * node + 1
    largest = node

    if(LeftSon <= ArrayLength and Heap[largest] < Heap[LeftSon]):
        Heap[largest], Heap[LeftSon] = Heap[LeftSon], Heap[largest]

    if (RightSon <= ArrayLength and Heap[largest] < Heap[RightSon]):
        Heap[largest], Heap[RightSon] = Heap[RightSon], Heap[largest]
        largest = RightSon

    if(largest != node):
        Heapify(Heap, ArrayLength, RightSon)
def HeapSort(Heap, ArrayLength):
    for node in range(int(ArrayLength / 2), 0, -1):#we heapify every node, except the leafes
        Heapify(Heap, ArrayLength, node)          # (because you don't have any another node to compare them with)

    for node in range(ArrayLength, 0, -1):
        Heap[1], Heap[node] = Heap[node], Heap[1]
        Heapify(Heap, node - 1, 1)

#-----------------INPUT------------------------
ArrayLength = input("Enter array's length: ")
Heap = [] #Let us consider that the input array is a binary tree
#Now all that's left to do in order to complete the heapsort is to transform the array in a max or min heap
Heap.append(0)#this is in order to have the elements starting from position 1
#the sons of the node i will be 2 * i and 2 * i + 1

try:
    ArrayLength = int(ArrayLength)
except:
    print("Invalid input")
    exit()

for index in range(0, ArrayLength):
    ArrayElement = input(">>Enter Number: ")
    try:
        Heap.append(int(ArrayElement))
    except:
        print("Invalid input")
        exit()
#-----------------------------------------------

HeapSort(Heap, ArrayLength)

for element in range (1, ArrayLength + 1):
    print(Heap[element], end = " ")