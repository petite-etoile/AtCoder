N = int(input())
# DPだと思ったけど、2次元じゃなくて1次元だった
# けんちょんさん曰く、1次元でできないときに2次元で考える
sixes = [6 ** i for i in range(1, 7)]
nines = [9 ** i for i in range(1, 6)]
coin = [1] + sixes + nines
INF = 10**6
dp = [INF] * 100010
dp[0] = 0  # dp[i]:i円引き出すのに必要な回数
for money in range(1, N + 1):
    dp[money] = min([dp[money-i] + 1 for i in coin if i <= money])
    """
    dp_candidate = []
    for coin_ in coin:
        if money < coin_:
            continue
        else:
            dp_candidate.append(dp[money-coin_] + 1)
    dp[money] = min(dp_candidate)
    """

print(dp[N])
