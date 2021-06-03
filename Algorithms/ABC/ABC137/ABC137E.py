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

#edgeは1次元ですべて(始点,終点,重み)を格納
def bellmanford(edge,N):
    costs = [inf] * N
    costs[0] = 0
    exist_minus_cycle = False
    for i in range(N):
        update = False
        for from_, to, cost in edge:
            cost_to = costs[from_] + cost
            if cost_to < costs[to]:
                update = True
                costs[to] = cost_to
                
        if not update:
            break
        elif i==N-1:
            exist_minus_cycle = True

    #どこで無限に更新されるか判定
    minus_cycle = set()
    if exist_minus_cycle:
        for i in range(N+1):
            for from_, to, cost in edge:
                cost_to = costs[from_] + cost
                if from_ in minus_cycle:
                    minus_cycle.add(to)
                if cost_to < costs[to]:
                    minus_cycle.add(from_)
                    minus_cycle.add(to)
                    costs[to] = cost_to
    return costs, minus_cycle


def main():
    N,M,P = MI()
    edges = []
    for _ in range(M):
        A,B,C = MI_()
        cost = P - (C+1)
        edges.append((A,B,cost))

    
    costs,minus_cycle = bellmanford(edges,N)

    if N-1 in minus_cycle :
        print(-1)
    else:
        print(max(0,-costs[-1]))



if __name__ == '__main__':
    main()
