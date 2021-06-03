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
mod = 10**5
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
    DP=[[[0]*4 for _ in range(W)] for _ in range(H)]
    DP[0][0][1]=1
    DP[0][0][3]=1
    #0~1 北に向いている 1:右折不可 2~3:東に向いている 3:左折不可
    for i in range(H):
        for j in range(W):
            if i: #南からここへ
                DP[i][j][0] += DP[i-1][j][0] + DP[i-1][j][1]
                DP[i][j][1] += DP[i-1][j][2]
            if j: #西からここへ
                DP[i][j][2] += DP[i][j-1][2] + DP[i][j-1][3]
                DP[i][j][3] += DP[i][j-1][0]
            DP[i][j][0]%=mod
            DP[i][j][1]%=mod
            DP[i][j][2]%=mod
            DP[i][j][3]%=mod
    print(sum(DP[-1][-1])%mod)




if __name__ == '__main__':
    main()