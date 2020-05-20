from numpy import cumsum
N = int(input())
A1 = [0] + [int(i) for i in input().split()]
A2 = [0] + [int(i) for i in input().split()]
cum_A1 = cumsum(A1)
cum_A2 = cumsum(A2)
ans = 0
for i in range(N):
    ans = max(ans, cum_A1[i + 1] + (cum_A2[-1] - cum_A2[i]))
print(ans)
