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
    N,M = MI()
    A=sorted(LI(), reverse=True)
    num_cost = {
        1:2,
        2:5,
        3:5,
        4:4,
        5:5,
        6:6,
        7:3,
        8:7,
        9:6
    }


    dp = [-inf]*(N+1) #dp[i]:ちょうどi本使ったときの最大桁数
    dp[0] = 0

    for i in range(1,N+1):
        for a in A:
            if i-num_cost[a]>=0:
                dp[i] = max(dp[i], dp[i-num_cost[a]] + 1)

    ans = []
    while N:
        for a in A:
            cost = num_cost[a]
            if N-cost>=0 and dp[N-cost]==dp[N]-1: #aを使って最大桁数で作れる
                ans.append(a)
                N-=cost
                break
    print(*ans,sep="")



if __name__ == '__main__':
    main()