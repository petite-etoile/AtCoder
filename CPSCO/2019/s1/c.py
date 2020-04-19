def solve(m):
    cnt=0
    for i in reversed(range(9)):
        a = m//(10**i)
        m %= 10**i
        if a>=5:
            a-=4
        cnt+=a
    return cnt

import itertools
N,K=map(int,input().split())
A=[int(i) for i in input().split()]

l = list(itertools.combinations(A, K))
ans=float("inf")
for i in range(len(l)):
    money=sum(l[i])
    ans = min(ans,solve(money))
print(ans)