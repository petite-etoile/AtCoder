import math
N, K = map(int, input().split())
A = [int(i) for i in input().split()]
print(math.ceil((N-1)/(K-1)))
