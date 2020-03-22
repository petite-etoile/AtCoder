from math import ceil
N, A, B, C, D = map(int, input().split())
print(min(ceil(N / A) * B, ceil(N / C) * D))
