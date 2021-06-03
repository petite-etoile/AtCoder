#dp[i][k] := 頂点iを根とする部分技内の辺をk本着るのに必要な操作回数の最小値

"""WA
def ret_minindex_not_zero(g):
    mini_index=-1
    mini=float("inf")
    for i in range(1,len(g)):
        if mini>g[i][1] and g[i][1]!=0:
            mini = g[i][1]
            mini_index = i
    return mini_index
N = int(input())
g=[None]
for i in range(N-1):
    pi,Hi = map(int,input().split())
    if pi==0:
        g.append([[pi],Hi])
    else:
        g.append([g[pi][0]+[pi] ,Hi])
#print(g)
ret_minindex_not_zero(g)
ans=0
while 1:
    m_index = ret_minindex_not_zero(g)
    print(g,)
    if m_index==-1:
        break
    else:
        mini = g[m_index][1]
    for i in reversed(range(1,N)):
        if m_index in g[i][0]:
            g[i][1]-=mini
            if g[i][1]==0:
                ans+=1
            for j in g[i][0]:
                if j==0:
                    continue
                g[j][1]-=mini
                if g[j][1]==0:
                    ans+=1"""