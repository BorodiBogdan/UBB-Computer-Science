"""
Given the set of positive integers S and the natural number k, display one of the subsets of S which sum to k.
For example, if S = { 2, 3, 5, 7, 8 } and k = 14, subset { 2, 5, 7 } sums to 14.

dp[i][j] --> 1 if we can sum the first i elements up to j
2
2 3 5
2 3 5 7 8 10
"""

if __name__ == "__main__":

    n = int(input("enter length: "))
    k = int(input("Enter the sum we add up to: "))
    vector = []

    #dp[i][j] --> we check if we can have the sum j using the first i numbers
    # if we can we retain the last added number in order to reconstruct the subsest

    for _ in range(n):
        nr = int(input())
        vector.append(nr)

    dp = [[0 for column in range(100)] for row in range(100)]

    s = sum(vector)

    dp[0][0] = 1
    dp[0][vector[0]] = 1

    for i in range(1, n):
        for j in range(s + 1, -1, -1):
            if j <= vector[i]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - vector[i]]


    set = []
    i = 0

    while k > 0 and i < n:
        if k >= vector[i]:
            if dp[n - 1][k - vector[i]] == 1:
                k = k - vector[i]
                set.append(vector[i])
                i += 1
            else:
                i += 1
        else:
            i += 1

    print(set)