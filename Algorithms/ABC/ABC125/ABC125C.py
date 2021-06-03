from fractions import gcd
N = int(input())
A = [int(i) for i in input().split()]
left = []
right = [0]*N
for i in range(N):
    if i == 0:
        left.append(A[i])
    else:
        left.append(gcd(left[i - 1], A[i]))
for i in reversed(range(N)):
    if i == N - 1:
        right[i] = A[i]
    else:
        right[i] = gcd(right[i+1], A[i])

ans = 0
for i in range(N):
    if i == 0:
        an_ = right[i + 1]
    elif i == N - 1:
        an_ = left[i-1]
    else:
        an_ = gcd(left[i-1], right[i+1])
    ans = max(ans, an_)
print(ans)
"""# 一見O(N^2)に見えるけどO(Nlog(max(A)))です
from fractions import gcd
N = int(input())
A = [int(i) for i in input().split()]
g = A[0]
mini_index_1 = 0
mini_index_2 = 0
glist = [0]
for i in range(N):
    ng = gcd(g, A[i])
    if ng < g:
        mini_index_1 = i
        mini_index_2 = i-1
        g = ng
        glist.append(i)
# print(mini_index_1)

ans = 1
gcddd = 0

for gindex in glist:
    gcddd = 0
    for i in range(N):
        if gindex == i:
            continue
        else:
            if gcddd == 0:
                gcddd = A[i]
            else:
                gcddd = gcd(gcddd, A[i])
    ans = max(ans, gcddd)
print(ans)
"""
