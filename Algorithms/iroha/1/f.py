from functools import *
from math import sqrt
N, K = map(int, input().split())
ans = []
fact = []
frag = False
for i in range(2, int(sqrt(N) + 1)):
    while N % i == 0:
        N //= i
        fact.append(i)
if N > 2:
    fact.append(N)
if len(fact) < K:
    print(-1)
else:
    while K < len(fact):
        last = fact.pop()
        fact[-1] *= last
    print(*fact, sep=" ")
