from math import log, ceil

N, K = map(int, input().split())
ans = 0
for i in range(1, N + 1):
    percent = (1 / 2)**ceil(log(ceil(K / i), 2))
    ans += percent
print(ans/N)
