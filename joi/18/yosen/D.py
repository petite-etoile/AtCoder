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
    L = LIN(N)
    cumsum = [0] + list(accumulate(L))
    can_length = set()
    for l in range(N):
        for r in range(l+1,N+1):
            can_length.add(cumsum[r] - cumsum[l])

    can_length = sorted(can_length)[:-1]
    ans = inf
    for min_len in can_length:
        dp = [inf]*N #dp[i] := i番目まででmin以上の切り方で最大の長さ最小
        for i in range(N):
            if min_len <= cumsum[i+1] and i!=N-1:
                dp[i] = cumsum[i+1]
            for j in range(i):
                if min_len <= cumsum[i+1]-cumsum[j+1]:
                    dp[i] = min(dp[i], max(cumsum[i+1]-cumsum[j+1], dp[j]))
        ans = min(ans, dp[-1]-min_len)
    print(ans)

            
    
if __name__ == '__main__':
    main()