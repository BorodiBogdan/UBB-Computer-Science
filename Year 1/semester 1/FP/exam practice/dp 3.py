"""
Given the set of positive integers S, partition this set into two subsets S1 and S2 so that the difference between
the sum of the elements in S1 and S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two subsets could
be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.
"""

if __name__ == "__main__":

    n = int(input("enter length: "))

    vector = []

    #dp[i][j] --> we check if we can have the sum j using the first i numbers
    # if we can we retain the last added number in order to reconstruct the subsest

    for _ in range(n):
        nr = int(input())
        vector.append(nr)

    dp = [[0 for column in range(100)] for row in range(100)]

    s = sum(vector)

    dp[0][vector[0]] = vector[0]

    for i in range(1, n):
        for j in range(s, -1, -1):
            #we check if we can compute the sum
            if dp[i - 1][j - vector[i]] != 0:
                dp[i][j] = vector[i]
            else:
                dp[i][j] = dp[i - 1][j]


    minimum = int(2e9)
    reconstruct = 0

    #now we find the minimal difference between sums
    for verify in range(0, s // 2 + 1):
        if int(dp[n - 1][verify]) != 0:
            if minimum > s - verify:
                minimum = min(minimum, s - verify)
                reconstruct = verify

    set1 = []
    set2 = []
    i = 0

    while minimum > 0 and i < n:
        if minimum >= vector[i]:
            if dp[n - 1][minimum - vector[i]]:
                minimum = minimum - vector[i]
                print(vector[i])
                set1.append(vector[i])
                i += 1
            else:
                set2.append(vector[i])
                i += 1
        else:
            set2.append(vector[i])
            i += 1

    print(set1)
    print(set2)
