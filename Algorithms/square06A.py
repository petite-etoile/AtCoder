from math import ceil
N, T, *A = map(int, open(0).read().split())
ans = ceil(sum(A) / T)
print(ans)
