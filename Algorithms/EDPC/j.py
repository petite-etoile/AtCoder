"""
pythonがおそすぎて通らない！！！
"""
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
    N = I()
    A = LI()
    cnt = [0]*4
    for a in A:
        cnt[a] += 1
    dp = [ [ [0]*(N+1)  for _ in range(N+1)] for _ in range(N+1)]  #dp[i][j][k] = N/i * dp[i-1][j][k] + N/j * dp[i][j-1][k] + N/k * dp[i][j][k-1]
    dp[0][0][0] = 0
    def dfs(i,j,k):
        if (i,j,k) == (0,0,0):
            return 0
        if dp[i][j][k]:
            return dp[i][j][k]

        res = N/(i+j+k)

        if i:
            res += dfs(i-1,j+1,k) * i/(i+j+k)
        if j:
            res += dfs(i,j-1,k+1) * j/(i+j+k)
        if k:
            res += dfs(i,j,k-1) * k/(i+j+k)

        dp[i][j][k] = res
        return res

    print(dfs(cnt[3],cnt[2],cnt[1]))

if __name__ == '__main__':
    main()