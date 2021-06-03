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
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf=float('inf')
mod = 10**9+7
def pprint(*A): 
    for a in A:     print(*a,sep='\n')
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
# ダイクストラ
def dijkstra(start, edge):
    N=len(edge)
    costs=[inf]*N
    costs[start]=0
    hash={}
    queue = [(0, start)]  # 第一要素が優先的に評価されるので 第３要素にpre(前の頂点)が入る
    while queue:
        c, from_=heappop(queue)
        if from_ in hash:
            continue
        hash[from_] = 1
        costs[from_]=c
        for cost,node in edge[from_]:
            if node in hash:
                continue
            heappush(queue, (c + cost, node, from_))

    return costs

def main():
    N,L=MI()
    v,d = MI()
    XVD = [(0,v,d)]
    for i in range(N):
        x,v,d = MI()
        XVD.append((x,v,d))
    XVD.sort()
    N+=1
    X=[]
    V=[]
    D=[]
    for x,v,d in XVD:
        X.append(x)
        V.append(v)
        D.append(d)
    X.append(L)
    

    edge = [[] for _ in  range(N+1)]
    for i in range(N):
        for j in range(i+1,N+1):
            dis = X[j] - X[i]
            if dis <= D[i]:
                cost = dis/V[i]
                edge[i].append((cost,j))
    costs = dijkstra(0,edge)

    if costs[-1] < inf:
        print("{:f}".format(costs[-1]))
    else:
        print("impossible")
if __name__ == '__main__':
    main()