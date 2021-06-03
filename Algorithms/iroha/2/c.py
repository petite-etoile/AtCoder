from bisect import bisect_right
N = int(input())
H = [int(input()) for _ in range(N)]
x = sorted(set(H))
for h in H:
    print(bisect_right(x, h))

"""
from itertools import accumulate
from collections import defaultdict
N = int(input())
H = []
for i in range(N):
    h = int(input())
    H.append([h, i])
H.sort(key=lambda x: x[0])
ans = [0] * N
num = 1
ans[H[0][1]] = num
for i in range(1, N):
    if H[i][0] == H[i - 1][0]:
        ans[H[i][1]] = num
    else:
        num += 1
        ans[H[i][1]] = num
print(*ans, sep="\n")
"""
