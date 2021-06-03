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
def mid(A):
    return (A[N//2] + A[~(N//2)])/2
def main():
    N=I()
    AB=LLIN(N)
    l = []
    r = []
    for a,b in AB:
        l.append(a)
        r.append(b)
    l.sort()
    r.sort(reverse = True)

    l_lim = l[(N-1)//2]
    r_lim = r[(N-1)//2]
    # print(l_lim, r_lim)
    if(N&1):
        print(r_lim - l_lim + 1)
    else:
        l_lim2 = l[(N-1)//2 + 1]
        r_lim2 = r[(N-1)//2 + 1]
        l_lim2 *= 2
        r_lim2 *= 2
        l_lim  *= 2
        r_lim  *= 2
        # print("lim2",l_lim2, r_lim2)
        ans = max(0,(r_lim2 - l_lim2) + 1)
        # print(ans)

        L_low = (l_lim + l_lim2)//2
        L_high = min(l_lim2, (l_lim2 + r_lim)//2)
        # print("L",L_low, L_high)
        ans += int((L_high - L_low))

        R_low = max(r_lim2,(r_lim2 + l_lim)//2)
        R_high = (r_lim + r_lim2)//2
        # print("R",R_low,R_high)
        ans += int((R_high - R_low))
        print(ans)


if __name__ == '__main__':
    main()