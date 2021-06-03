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
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
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
    N = I()
    C = defaultdict(int)
    D,U,R,L=inf,inf,inf,inf

    for _ in range(N):
        x, y, d = ST().split()
        x = int(x)
        y=int(y)
        if d in "D":
            D=min(D,y)
        if d in "U":
            U = max(U, y)
        if d in "L":
            L = min(L, x)
        if d in "R":
            R = max(R, x)
    
    if D == U == inf:
        if R >= L:
            ans = abs(R - L)
        else:
            ans = (R-L)%2!=0
    elif R == L == inf:
        if U >= D:
            ans = abs(U - D)
        else:
            ans = (U-D)%2!=0
    if U <= D or L >= R:
        ans = 0
    else:
        if U == inf:
            
        ans = abs(R - L) * abs(U - D)
    print(ans)


if __name__ == '__main__':
    main()