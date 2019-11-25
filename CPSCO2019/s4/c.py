from bisect import bisect_right
from math import factorial
from functools import lru_cache


@lru_cache(maxsize=None)
def combination(n, r):  # n個からr個選ぶ場合の数
    if n < r:
        return 0
    else:
        return fact[n]//(fact[r] * fact[n-r])


N, D, *R = map(int, open(0).read().split())
R.sort()


# 組めるやつら何個あるか
listtt = [0]*N
for i in range(N):
    listtt[i] = bisect_right(R, R[i] + D) - i-1
ans = 0

fact = [1]
fact_append = fact.append
for i in range(1, N):
    fact_append(fact[i-1]*i)

for i in range(N):
    ans += listtt[i]*(listtt[i]-1)//2
    #ans += combination(listtt[i], 2)


print(ans)
