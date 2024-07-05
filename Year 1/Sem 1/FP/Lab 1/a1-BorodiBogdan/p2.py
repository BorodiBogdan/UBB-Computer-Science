# Solve the problem from the second set here

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

def IsTwin(x : int):
    if(IsPrime(x) and IsPrime(x + 2)):
        return [x, x + 2]
    else:
        return IsTwin(x + 1)

x = input()

try:
    x = int(x)
except:
    print ("Invalid input")
    exit()

twin_numbers = IsTwin(x + 1)

print(twin_numbers[0], twin_numbers[1], sep = " | ")
