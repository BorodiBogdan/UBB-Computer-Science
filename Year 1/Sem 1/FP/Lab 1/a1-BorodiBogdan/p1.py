# Solve the problem from the first set here
#5 7 12
#https://github.com/cs-ubbcluj-ro/a1-BorodiBogdan

def IsPrime(x: int) -> int:
    if(x == 1 or x == 0):
        return 0
    if(x == 2):
        return 1
    if(x % 2 == 0):
        return 0
    for d in range(3, x, 2):
        if(x % d == 0):
            return 0
    return 1

def IsSmaller(x : int) -> int:
    if(x <= 1):
        return -1

    if(IsPrime(x)):
        return x
    else:
        return IsSmaller(x - 1)

x = input()

try:
    x = int(x)
except:
    print("Invalid Input")
    exit()



print(IsSmaller(x - 1))