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
    #DP[i][j][k]:i日目までで今パスタjがk連続
    N,K = MI()
    pasta = {}
    for _ in range(K):
        a,b = MI()
        pasta[a-1] = b-1
    
    DP = [[[0]*3 for _ in range(3)] for _ in range(N)]
    if(0 in pasta):
        DP[0][pasta[0]][1] = 1
    else:
        for j in range(3):
            DP[0][j][1] = 1

    for i in range(1,N):
        if(i in pasta):
            j = pasta[i]
            for l in range(3):
                if( l == j):
                    DP[i][j][2] = DP[i-1][l][1]
                else:
                    for k in range(1,3):
                        DP[i][j][1] += DP[i-1][l][k]
                    DP[i][j][1] %= 10000
        else:
            for j in range(3):
                for l in range(3):
                    if( l == j):
                        DP[i][j][2] = DP[i-1][l][1]
                    else:
                        for k in range(1,3):
                            DP[i][j][1] += DP[i-1][l][k]
                        DP[i][j][1] %= 10000
    
    ans = 0
    for j in range(3):
        for k in range(1, 3):
            ans += DP[-1][j][k]
    ans %= 10000

    print(ans)
        
if __name__ == '__main__':
    main()