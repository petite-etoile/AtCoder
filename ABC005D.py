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
def LLI(): return [list(map(int, left.split() )) for left in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    N=I()
    D=LLIN(N)
    Q=I()
    P=LIN(Q)

    cumsum_2d = [[0]*(N+1) for _ in range(N+1)]
    
    for i in range(N):
        for j,d in enumerate(D[i]):
            cumsum_2d[i+1][j+1] = d

    for i in range(N):
        for j,d in enumerate(D[i]):
            cumsum_2d[i+1][j+1] += cumsum_2d[i+1][j] + cumsum_2d[i][j+1] - cumsum_2d[i][j]
    
    ans = [0]*(N*N+1)
    for left in range(N):
        for right in range(left+1,N+1):
            for top in range(N):
                for bottom in range(top+1,N+1):
                    S = (right-left)*(bottom-top)
                    ans[S] = max(ans[S], cumsum_2d[bottom][right] - cumsum_2d[top][right] - cumsum_2d[bottom][left] + cumsum_2d[top][left])

    for i,a in enumerate(ans[:-1]):
        ans[i+1]=max(ans[i],ans[i+1])
    for p in P:
        print(ans[p])
    # for p in P:
    #     ans = 0
    #     for left in range(N):
    #         for right in range(left+1,N+1):
    #             for top in range(N):
    #                 h = p//(right-left)
    #                 if h:
    #                     bot = top + h
    #                     if bot>N:
    #                         bot = N
    #                     # print((top,bot),(left,right),(cumsum_2d[bot][right] , cumsum_2d[top][right] , cumsum_2d[bot][left] , cumsum_2d[top][left]),cumsum_2d[bot][right] - cumsum_2d[top][right] - cumsum_2d[bot][left] + cumsum_2d[top][left])
    #                     ans = max(ans, cumsum_2d[bot][right] - cumsum_2d[top][right] - cumsum_2d[bot][left] + cumsum_2d[top][left])
    #     print(ans)
if __name__ == '__main__':
    main()