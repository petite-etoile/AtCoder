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
def main():
    N,M,Q = MI()
    LR=LLIN_(M)
    PQ=LLIN(Q)

    D=[[0]*N for _ in range(N)]
    for l,r in LR:
        D[l][r] += 1

    cumsum_2d = [[0]*(N+1) for _ in range(N+1)]
    
    for i in range(N):
        for j,d in enumerate(D[i]):
            cumsum_2d[i+1][j+1] = d

    for i in range(N):
        for j,d in enumerate(D[i]):
            cumsum_2d[i+1][j+1] += cumsum_2d[i+1][j] + cumsum_2d[i][j+1] - cumsum_2d[i][j]
    
    for p,q in PQ:
        print(cumsum_2d[q][q]-cumsum_2d[p-1][q]-cumsum_2d[q][p-1]+cumsum_2d[p-1][p-1])

if __name__ == '__main__':
    main()