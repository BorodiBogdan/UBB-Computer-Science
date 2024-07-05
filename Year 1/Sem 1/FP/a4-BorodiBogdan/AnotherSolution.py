def FindTheResult(index, op):
    if(index == 0):
        memo[index][0] = SetOfPositiveIntegers[index]
        memo[index][1] = -SetOfPositiveIntegers[index]
        return SetOfPositiveIntegers[index]

    Add = SetOfPositiveIntegers[index]

    if(memo[index - 1][0] != 0):
        sum1 = memo[index - 1][0]
    else:
        sum1 = FindTheResult(index - 1, 0)

    if (memo[index - 1][1] != 0):
        sum2 = memo[index - 1][1]
    else:
        sum2 = FindTheResult(index - 1, 1)

    if(abs(sum2-Add) < abs(sum1- Add)):
        memo[index][1] = sum2 - Add
    else:
        memo[index][1] = sum1 - Add

    if(abs(sum2 + Add) < abs(sum1 + Add)):
        memo[index][0] = sum2 + Add
    else:
        memo[index][0] = sum1 + Add

    if(abs(memo[index][1]) < abs(memo[index][0])):
        return memo[index][1]
    else:
        return memo[index][0]

sub = []
memo = [ [0, 0] for _ in range (0, 256)]

SetOfPositiveIntegers = [1, 2, 3, 4, 5]

print (FindTheResult(4,0))

index = len(SetOfPositiveIntegers) - 1

if(abs(memo[index][0]) < abs(memo[index][1])):
    sum = memo[index][0]
    op = 0
else:
    sum = memo[index][1]
    op = 1

while index >= 0:
    Add = SetOfPositiveIntegers[index]

    if(op == 1):
        sum -= Add
    else:
        sum += Add

    if(memo[index - 1][0] == sum):
        op = 0
    elif(memo[index - 1][1] == sum):
        op = 1

    index -= 1

print (memo[1][0])