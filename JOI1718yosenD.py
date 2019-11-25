def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return None


from numpy import cumsum
N, *L = map(int, open(0).read().split())
cum_L = cumsum(L)
dp = dp_table(N, cum_L[-1])  # dp[i][j]:iまでの羊羹でj以上の大きさにうまくカットしたときの大きさ
dp[0] = [L[0]] * cum_L[-1]
for i in range(N - 1):
    for j in range(1, i+1):
        dp[]
