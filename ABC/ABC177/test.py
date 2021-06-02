n,m = map(int,input().split())
f = [[] for i in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    
    f[a].append(b)
    f[b].append(a)
    
import collections
q = collections.deque()

for i in range(n):
    for j in f[i]:
        q.append(j)
        
    while q:
        p = q.popleft()
        
        if p != i:
            f[i] += f[p]

            for k in f[p]:
                q.append(k)

            f[p] = []
        
    f[i] = sorted(set(f[i]))
            
ans = 0

for i in f:
    res = len(i)
    ans = max(ans,res)
    
print(ans)
