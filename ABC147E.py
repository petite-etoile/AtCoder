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
def main():
    H,W=MI()
    A=LLIN(H)
    B=LLIN(H)
    X=80*(H+W)
    can = [[0]*W for _ in range(H)]
    can[0][0] += 1<<(X-abs(A[0][0]-B[0][0]))
    for h in range(H):
        for w in range(W):
            absol = abs(A[h][w]-B[h][w])
            if h:
                can[h][w]|=can[h-1][w]<<absol
                can[h][w]|=can[h-1][w]>>absol
            if w:
                can[h][w]|=can[h][w-1]<<absol
                can[h][w]|=can[h][w-1]>>absol
    for i in range(160*(H+W)+5):
        if can[-1][-1] & ((1<<X<<i) | (1<<X>>i)):
            print(i)
            break

if __name__ == '__main__':
    main()