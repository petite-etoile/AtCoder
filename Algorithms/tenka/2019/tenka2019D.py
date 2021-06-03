
def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return 0


def main():

    N = int(input())
    A = [int(input()) for _ in range(N)]
    mod = 998244353
    ans = pow(3, N, mod)
    sum_A = sum(A)
    dp = [[0] * (sum_A+1) for i in range(N)]
    # dp[i][j]: i番目までの中から辺をいくつか選んで、長さがjになるパターン数

    # init
    dp[0][A[0]] = 1
    dp[0][0] = 2  # 他の色のうちどちらに入れるかで2通り

    # init2
    dp2 = [[0] * (sum_A+1) for i in range(N)]  # ある二色でsum_Aを等分するパターンを数える
    dp2[0][A[0]] = 1
    dp2[0][0] = 1  # 今度は片方に集中したパターン

    # dp
    sum_now = A[0]
    for i in range(1, N):
        a = A[i]
        sum_now += a
        for length in range(sum_now+1):
            # A[i]を追加しないのなら他の２食のうちどちらに入れるかで2倍選択肢がある
            if length >= a:
                dp[i][length] = dp[i - 1][length - a] + \
                    (dp[i - 1][length] << 1)
            else:
                dp[i][length] = dp[i-1][length] << 1
            dp[i][length] %= mod

        for length in range(min(sum_now + 1, sum_A // 2 + 1)):
            if length >= a:
                dp2[i][length] = dp2[i - 1][length - a] + dp2[i - 1][length]
            else:
                dp2[i][length] = dp2[i-1][length]
            dp2[i][length] %= mod
    # print(sum(dp[N-1][sum_A//2]))
    # print(dp)
    ans -= 3*sum(dp[N-1][(sum_A+1)//2:])
    if sum_A % 2 == 0:
        ans += 3*dp2[N-1][sum_A//2]
    print(ans % mod)


if __name__ == '__main__':
    main()
