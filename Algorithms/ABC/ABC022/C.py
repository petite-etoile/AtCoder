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

# ワーシャルフロイド
def warshall_floyd(d, N):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                d[i][j]=min(d[i][j], d[i][k] + d[k][j])

def main():
    N,M=map(int, input().split())
    edge = [[] for _ in range(N)] #家1が関わる辺は無視されたグラフ
    direct_connect = [] #家1と直接辺でつながってる家
    
    dist=[[float("inf")] * N for i in range(N)]
    for i in range(N):
        dist[i][i] = 0
    
    for _ in range(M):
        a,b,c = map(int, input().split())
        if(a>b): a,b = b,a

        if (1 == a): #家1を端点に含む辺
            direct_connect.append((b-1,c))
        else:
            dist[a-1][b-1] = c
            dist[b-1][a-1] = c
    
    warshall_floyd(dist, N)


    ans = inf
    for i,(v1, cost1) in enumerate(direct_connect):
        for j,(v2, cost2) in enumerate(direct_connect[i+1:], start = i+1):
            ans = min(ans, cost1 + cost2 + dist[v1][v2])
    
    print(ans if ans < inf else -1)

if __name__ == '__main__':
    main()