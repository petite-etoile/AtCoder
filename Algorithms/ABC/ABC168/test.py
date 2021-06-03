n,m = map(int,input().split())
AB = []
ans = [-1] * (n) #####

edge = [[] for _ in range(n)] #edge[i] := 頂点iから伸びてる辺の行き先のリスト #####

for i in range(m):
    a,b = map(int,input().split())
    a-=1; b-=1 #####
    edge[a].append(b)    
    edge[b].append(a)    
    
import collections
que = collections.deque()
que.append(0) #####
    
while que:
    x = que.popleft()
    
    for to in edge[x]:
        a = x
        b = to
        
        if ans[b] == -1: #####
            ans[b] = x + 1 #####
            que.append(b)
            
print("Yes")
print(*ans[1:],sep="\n")
