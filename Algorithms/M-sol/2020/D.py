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
    
    #DP[i][j]:=i日目に株j個持ってる場合の所持金最大値
    DP = [defaultdict(int) for _ in range(N+1)]
    DP[0][0] = 1000
    for i in range(N):
        for j,money in DP[i].items():
            #買わない
            DP[i+1][j] = max(DP[i+1][j], money)
            #売る
            DP[i+1][0] = max(DP[i+1][0], money + j*A[i])

        #0円のときのみ買う
        remain = DP[i][0]%A[i]
        buy = DP[i][0]//A[i]
        DP[i+1][0+buy] = max(DP[i+1][0+buy], remain)
    ans = DP[-1][0]
    print(ans)
if __name__ == '__main__':
    main()