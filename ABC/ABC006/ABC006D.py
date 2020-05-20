# 最長増加部分列(Longest Increasing Subsequence)
# "抜き取り、挿入する"という操作をしないカードはもともと昇順になっている
# それらの操作をしないカードが最大になるように操作するカードを選ぶことが最小回数で済ませる条件
# つまり、もともと昇順になっているカード群を最大化すればよい
# これをDPで行うのだが、データの持ち方を工夫して、カード群の大きさがiのときのカード群内の最大値が一番小さいものを格納
from bisect import bisect_left
N = int(input())
c = [int(input()) for i in range(N)]
dp = [c[0]]  # dp[i]:i枚カード群の中で、最大値が一番小さいカード群の、最後のカード
for i in range(1, N):
    # 二分探索使いましょう
    # dpの最後の要素よりc[i]が大きいならc[i]を最後に付けて、一つ大きい部分列になる
    if c[i] > dp[-1]:
        dp.append(c[i])
    # そうじゃないなら、c[i]より大きいのと小さいのの間のところにいれる(大きいのを上書き)
    else:
        dp[bisect_left(dp, c[i])] = c[i]

    """
    これだとO(n)になるのでpypyでも間に合わない
    for j in range(len(dp)):
        if dp[j] < c[i]:
            if j + 1 == len(dp):
                dp.append(c[i])
            else:
                dp[j + 1] = min(c[i], dp[j + 1])

    dp[0] = min(dp[0], c[i])
    """
    """
    これなら間に合いました(100点)
    for j in reversed(range(len(dp))):
        if dp[j] < c[i]:
            if j + 1 == len(dp):
                dp.append(c[i])
            else:
                dp[j + 1] = min(c[i], dp[j + 1])
            break
    dp[0] = min(dp[0], c[i])
    """
    """
# print(dp)
print(N-len(dp))

"""
部分点50点回答
# "抜き取り、挿入する"という操作をしないカードはもともと昇順になっている
# それらの操作をしないカードが最大になるように操作するカードを選ぶことが最小回数で済ませる条件
# つまり、もともと昇順になっているカード群を最大化すればよい
# これをDPで行う
N = int(input())
c = [int(input()) for i in range(N)]
dp = [1]  # dp[i]:i番目までのカードでの昇順カード群の大きさの最大
for i in range(1, N):
    # dp[i]=max([dp[j] for j in range(len(dp)) if c[j]<c[i] ])+1
    # print([0]+[dp[j] for j in range(len(dp)) if c[j] < c[i]])
    dp.append(max([0]+[dp[j] for j in range(len(dp)) if c[j] < c[i]])+1)
# print(dp)
print(N-max(dp))
"""
"""N = int(input())
now = 1
for i in range(1, N+1):
    c = int(input())
    if now < c:
        ans += 1
        now += 1
print(ans)
"""
"""
嘘
N = int(input())
c = [int(input()) for i in range(N)]
ans = 0
for i in range(N - 1):
    if c[i] > c[i + 1]:
        ans += 1
print(ans)
"""
