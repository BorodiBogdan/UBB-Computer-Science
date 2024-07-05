"""
Determine the longest common subsequence of two given sequences.
Subsequence elements are not required to occupy consecutive positions.
For example, if X = "MNPNQMN" and Y = "NQPMNM", the longest common subsequence has length 4,
and can be one of "NQMN", "NPMN" or "NPNM". Determine and display both the length of the longest
common subsequence as well as at least one such subsequence.
"""

#MNPNQMN
#NQPMNM

# dp[i][j] --> the longest common subsequence that is ending on i(meaning the i th place of the first string)
# and on j (j th place of the second)
# if X[i] == Y[j] dp[i][j] = dp[i - 1][j - 1] + 1
# else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
# for constructing the longest common subsequence we can use a dad vector

if __name__ == "__main__":
    X = input("Enter first string: ")
    Y = input("Enter second string: ")
    dp = [[0 for column in range(100)] for row in range(100)]
    dad = [["" for column in range(100)] for row in range(100)]
    n = len(X)
    m = len(Y)

    for i in range(n):
        for j in range(m):
            if X[i] == Y[j]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                dad[i][j] = dad[i - 1][j - 1] + X[i]
            else:
                if dp[i - 1][j] > dp[i][j - 1]:
                    dad[i][j] = dad[i - 1][j]
                else:
                    dad[i][j] = dad[i][j - 1]
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    print(dp[n - 1][m - 1])

    print(dad[n - 1][m - 1])
