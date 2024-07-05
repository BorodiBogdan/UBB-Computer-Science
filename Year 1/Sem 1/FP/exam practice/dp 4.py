"""
Given an n * n square matrix with integer values, find the maximum length of a snake sequence.
A snake sequence begins on the matrix's top row (coordinate (0, i), 0 <= i < n). Each element of
the sequence, except the first one, must have a value ±1 from the previous one and be located directly
below, or directly to the right of the previous element. For example, element (i, j) can be succeded by
one of the (i, j + 1) or (i + 1, j) elements. Display the length as well as the sequence of coordinates for
one sequence of maximum length.
"""

if __name__ == "__main__":
    dp = [[0 for column in range(100)] for row in range(100)]

    n = int(input("Enter the size of the matrix: "))

    for i in range(n):
        line = input()
        line = line.split(' ')
        j = 0

        for el in line:
            dp[i][j] = int(el)
            j += 1

    len = [[0 for column in range(100)] for row in range(100)]

    for i in range(1, n):
        for j in range(n):
            if dp[i - 1][j] == dp[i][j] - 1:
                len[i][j] = max(len[i][j], len[i - 1][j] + 1)
            if dp[i][j - 1] == dp[i][j] - 1:
                len[i][j] = max(len[i][j], len[i][j - 1] + 1)

    maximum = 0

    for j in range(n):
        if len[n - 1][j] > maximum:
            maximum = len[n - 1][j]

    print(maximum)

