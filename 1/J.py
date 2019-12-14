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
from math import floor,ceil,sqrt,factorial,hypot,log #log2ないｙｐ
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
    queue = [(0, start, start)]  # 第一要素が優先的に評価されるので 第３要素にpre(前の頂点)が入る
    pre_node = [-1]*N
    while queue:
        c, from_ ,pre=heappop(queue)
        if from_ in hash:
            continue
        hash[from_] = 1
        # print(from_,costs)
        costs[from_]=c
        pre_node[from_]=pre
        for cost,node in edge[from_]:
            if node in hash:
                continue
            heappush(queue, (c + cost, node, from_))

    return costs, pre_node
def main():
    H,W = MI()
    A=LLIN(H)
    def id(h,w):
        return h*W+w
    

    edge = [[] for _ in range(H*W)]
    for h,a in enumerate(A):
        for w,x in enumerate(a):
            dxdy = [(0,1),(1,0),(-1,0),(0,-1)]
            for dx,dy in dxdy:
                nh,nw = h+dx,w+dy
                if 0<=nh<H and 0<=nw<W:
                    edge[id(h,w)].append((A[nh][nw],id(nh,nw)))
    s,v,t = id(H-1,0),id(H-1,W-1),id(0,W-1)

    ans = inf
    for h in range(H):
        for w in range(W):
            dists,_ = dijkstra(id(h,w),edge)
            # print(dists[s]+dists[v]+dists[t],dists[s],dists[v],dists[t],(h,w))
            ans = min(ans,dists[s]+dists[v]+dists[t]+A[h][w])
    print(ans)

if __name__ == '__main__':
    main()