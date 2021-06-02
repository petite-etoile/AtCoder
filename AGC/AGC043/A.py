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
def main():
    H,W=MI()
    grid = [ST() for _ in range(H)]
    N = H*W
    edge = [[] for _ in range(N)]
    def enc(h,w):
        return h*W+w

    # DP = [[[inf,inf] for _ in range(W)] for _ in range(H)]
    # DP[0][0][0] = 0
    DP = [[inf]*W for _ in range(H)]
    DP[0][0] = int(grid[0][0] == "#")
    for h in range(H):
        for w in range(W):
            if(h+1<H):
                if(grid[h][w] == grid[h+1][w] or grid[h+1][w] == "."):
                    DP[h+1][w] = min(DP[h+1][w], DP[h][w])
                else:
                    DP[h+1][w] = min(DP[h+1][w], DP[h][w] + 1) 
            if(w+1<W):
                if(grid[h][w] == grid[h][w+1] or grid[h][w+1] == "."):
                    DP[h][w+1] = min(DP[h][w+1], DP[h][w])
                else:
                    DP[h][w+1] = min(DP[h][w+1], DP[h][w] + 1) 
    print(DP[-1][-1])
if __name__ == '__main__':
    main()