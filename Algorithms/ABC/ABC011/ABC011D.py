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
from fractions import gcd
from random import randint
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
    N,D = MI()
    X,Y = MI()

    Pascal = [[0]*(N+1) for _ in range(N+1)]
    Pascal[0][0] = 1
    for n in range(N):
        for r in range(N):
            Pascal[n+1][r] += Pascal[n][r]/2
            Pascal[n+1][r+1] += Pascal[n][r]/2

    if X%D or Y%D:
        print(0)
        return
    step_x,step_y = X//D ,Y//D
    
    ans = 0
    remain = N - (step_x + step_y)

    if remain < 0 or remain&1:
        print(0)
        return 

    for r in range(remain+1)[::2]:
        try:
            minus_x, minus_y = r//2, (remain-r)//2
            x = step_x + r
            ans += Pascal[N][x] * Pascal[x][minus_x] * Pascal[N-x][minus_y]
        except:
            pass
    print(ans)
if __name__ == '__main__':
    main()