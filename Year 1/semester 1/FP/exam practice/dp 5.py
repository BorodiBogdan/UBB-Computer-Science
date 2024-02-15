if __name__ == "__main__":
    price = [0, 1, 5, 8, 9, 10, 17, 17]

    n = 7

    # dp[j] -> maximum profit obtained by selling the first j th part of the rod
    dp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    l =  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    for i in range(1, n + 1):
        for j in range(1, i + 1):
            if dp[i] < dp[i - j] + price[j]:
                dp[i] = max(dp[i], dp[i - j] + price[j])
                l[i] = l[i - j] + 1
            elif dp[i] == dp[i - j] + price[j]:
                l[i] = max(l[i - j] + 1, l[i])

    print(dp[n])
    print(l[n])