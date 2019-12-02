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
    D,N = MI()
    mini = [inf]*D
    maxi = [-inf]*D
    temp = LIN(D)
    for i in range(N):
        a,b,c = MI()
        for i,t in enumerate(temp):
            if a<=t<=b:
                mini[i] = min(mini[i], c)
                maxi[i] = max(maxi[i], c)
    dp = [[0,0] for _ in range(D)]

    for i,(h,l) in enumerate(zip(maxi[1:], mini[1:]), start=1 ):
        dp[i][0] = max(abs(mini[i-1]-l)+dp[i-1][0], abs(maxi[i-1]-l)+dp[i-1][1])
        dp[i][1] = max(abs(mini[i-1]-h)+dp[i-1][0], abs(maxi[i-1]-h)+dp[i-1][1])
    print(max(dp[-1]))
if __name__ == '__main__':
    main()