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
from math import floor,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
def ceil(a,b): return (a+b-1)//b
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
        costs[from_]=c
        pre_node[from_]=pre
        for cost,node in edge[from_]:
            if node in hash:
                continue
            heappush(queue, (c + cost, node, from_))
    return costs, pre_node
def main():
    H,W=MI()
    A=[[0]*W for _ in range(H)]
    for i in range(H):
        S=ST()
        for j,a in enumerate(S):
            if a not in "SG":
                A[i][j] = int(a)
            elif(a == "S"):
                A[i][j] = 0
            else:
                A[i][j] = 10

    d=[[] for _ in range(12)]
    for i in range(H):
        for j,a in enumerate(A[i]):
            d[a].append((i,j))
    
    def enc(h,w):
        return h*W+w

    def calc_cost(from_,to):
        return abs(from_[0]-to[0])+abs(from_[1]-to[1])
    
    edge = [[] for _ in range(H*W)]
    for i in range(H):
        for j,a in enumerate(A[i]):
            for (k,l) in d[a+1]:
                edge[enc(i,j)].append((calc_cost((i,j),(k,l)), enc(k,l) ))
    s1,s2 = d[0][0]
    dist,_ = dijkstra(enc(s1,s2),edge)
    ans = dist[enc(d[10][0][0],d[10][0][1])]
    if(ans!=inf):
        print(ans)
    else:
        print(-1)
    
if __name__ == '__main__':
    main()