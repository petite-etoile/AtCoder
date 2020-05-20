N, K = map(int, input().split())
A = [int(i) for i in input().split()]
max_bit = 40
dp = [[-1] * 2 for i in range(41)]  # dp[i][j] = 上からi bitまで、j smaller

dp[0][0] = 0
for d in range(max_bit):
    mask = 1 << (max_bit-d-1)

    # Aでもともとd bit目にbitが立っているものの個数
    num = len([1 for i in range(N) if A[i] & mask])
    #print([1 for i in range(N) if A[i] & mask])

    # Xのbit bit目を0,1にしたときのコスト
    cost0 = mask * num
    cost1 = mask * (N - num)
    # smaller -> smaller
    if dp[d][1] != -1:
        # 0でも1でもいい！
        dp[d + 1][1] = max(dp[d + 1][1], dp[d][1] + max(cost0, cost1))

    # exact -> smaller
    if dp[d][0] != -1:
        if K & mask:  # kのd桁目が1だったらXのd桁目は0にする
            dp[d + 1][1] = max(dp[d + 1][1], dp[d][0] + cost0)

    # exact -> exact
    if dp[d][0] != -1:
        if K & mask:
            dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + cost1)
        else:
            dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + cost0)

# print(dp)
print(max(dp[max_bit][0], dp[max_bit][1]))

"""max_bit = 40
ans = 0
zeros = [0] * max_bit
ones = [0]*max_bit
for bit in range(max_bit):
    num = 1 << bit
    bit_cnt = 0
    for a in A:
        if a & num == 0:  # aのbit bit目が0
            zeros[bit] += 1
        else:
            ones[bit] += 1
"""

"""import math


def solve(dp, N: str, index: int = 0, tight: bool = True):
    if len(N) == index:
        return something
    elif dp[index][tight] is not None:
        return dp[index][tight]
    else:
        if tight:
            for_max = int(N[index])+1
        else:
            for_max = 10
        return_ = 0
        for i in range(for_max):
            return_ += solve(dp, N, index + 1, tight and i ==
                             int(N[index]))
        dp[index][tight] = return_
        return return_


def main():
    N, K = map(int, input().split())
    A = [int(i) for i in input().split()]


if __name__ == '__main__':
    main()
"""
