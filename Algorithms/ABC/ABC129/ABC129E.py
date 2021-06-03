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
from math import floor,ceil,sqrt,factorial
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
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
    L = ST()
    N=len(L)
    #dp[i][j]:=i桁目までみた j:= 未満が確定したなら1 else 0
    dp = [[0] * 2 for _ in range(N + 1)]
    dp[0][0] = 1

    for i, s in enumerate(L, start=1):
        #a+b=0
        if s == "0":
            dp[i][1] += dp[i - 1][1]
            dp[i][0] += dp[i - 1][0]
        else:
            dp[i][1] += dp[i - 1][1] + dp[i - 1][0]
        
        #a+b=1
        if s == "1":
            dp[i][1] += dp[i - 1][1] * 2
            dp[i][0] += dp[i - 1][0] * 2
        else:
            dp[i][1] += dp[i - 1][1] * 2
        dp[i][0] %= mod
        dp[i][1] %= mod


    print(sum(dp[-1])%mod)


if __name__ == '__main__':
    main()