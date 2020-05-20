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
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
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
    N, M = MI()
    edge = [[] for _ in range(N)]
    used_edge = set()

    # ダイクストラ
    def dijkstra(start, edge):
        costs=[inf]*N
        costs[start]=0
        queue = [(0, start, (-1,-1))]  # 第一要素が優先的に評価されるので 第３要素にpre(前の頂点)が入る
        hash = {}
        while queue:
            c, from_, e = heappop(queue)
            hash[from_]=1
            if costs[from_] >= c:
                costs[from_] = c
                used_edge.add(e)
            for cost,node in edge[from_]:
                if node in hash:
                    continue
                e = tuple(sorted([from_,node]))
                heappush(queue, (c + cost, node,e))



    for _ in range(M):
        a, b, c = MI_()
        c += 1
        edge[a].append((c, b))
        edge[b].append((c, a))
        
    for start in range(N):
        dijkstra(start, edge)
    
    num_used_edge = len(used_edge)-1
    print(M-num_used_edge)
    
if __name__ == '__main__':
    main()