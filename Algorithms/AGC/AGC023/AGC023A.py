from math import factorial
from itertools import accumulate


def combination(n, r):  # n個からr個選ぶ場合の数
    if n < r:
        return 0
    else:
        return factorial(n)//(factorial(r) * factorial(n-r))


N = int(input())
A = [int(i) for i in input().split()]
ans = 0
cumsum = sorted(list(accumulate(A)))
now = None
cnt = 1
for a in cumsum:
    if now is None:
        now = a
    elif now == a:
        cnt += 1
    else:
        ans += combination(cnt, 2)
        cnt = 1
        now = a
ans += combination(cnt, 2)
ans += cumsum.count(0)
print(ans)
