#
# 　　  ⋀_⋀　 
#　　  (･ω･)  
# .／ Ｕ ∽ Ｕ＼
#  │＊　合　＊│
#  │＊　格　＊│ 
#  │＊　祈　＊│ 
#  │＊　願　＊│ 
#  │＊　　　＊│ 
#      ￣
#
import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf=float('inf')
mod = 10**9+7
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [I() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    N,M,K = MI()
    D=ST()
    grid = []
    for i in range(N):
        line = ST()
        grid.append(line)
        s,g = line.find("S"), line.find("G")
        if s != -1:
            S = (i,s)
        if g != -1:
            G = (i,g)
    
    serched = set()
    queue = [(0,S)]

    cost = [[None,None,None,None]for _ in range(2*K)]
    last = [inf,inf,inf,inf]
    UDLR = "UDLR"
    for i in reversed(range(2*K)):
        for j in range(4):
            if D[i%K]==UDLR[j]:
                last[j] = i
            cost[i][j] = last[j] - i + 1
    #print(*cost,sep="\n")

    #dist = defaultdict(lambda : inf)
    dist = [[inf]*M for _ in range(N)]
    dist[S[0]][S[1]] = 0
    #print(dist.items())
    dydx = [(-1,0), (1,0), (0,-1), (0,1)]
    while queue:
        dis,(y,x) = heappop(queue)
        if (y,x) in serched:
            continue
        dist[y][x] = dis
        serched.add((y,x))
        if (y,x) == G:
            break

        for i,(dy,dx) in enumerate(dydx):
            to = (y+dy,x+dx)
            di = cost[dis%K][i] + dis
            #print(to,di,cost[dis][j],)
            if 0<=to[0]<N and 0<=to[1]<M and grid[to[0]][to[1]]!="#" and di!=inf and to not in serched:
                heappush(queue,(di,to))
    
    #print(serched)
    #print(*dist.items(),sep="\n")
    if dist[G[0]][G[1]]!=inf:
        print(dist[G[0]][G[1]])
    else:
        print(-1)

            
        


    

if __name__ == '__main__':
    main()