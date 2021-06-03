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
def get_cost(x):
    x = abs(x)
    return (1+x)*x//2
def get_cost2(x,y):
    if x*y <= 0:
        return get_cost(x) + get_cost(y)
    else:
        if abs(x)<abs(y):
            x,y = y,x
        return get_cost(x) - get_cost(abs(y)-1)
def main():
    R,G,B=MI()
    ans = inf
    for l in range(-G-100,G+100):
        r = l+G-1

        R_cost = inf
        G_cost = get_cost2(l,r)
        B_cost = inf

        B_lr = [0,0]
        R_lr = [0,0]
        for R_r in range(min(-100-R,l-R-1)-100,l):
            R_l = R_r-R+1
            cost = get_cost2(R_l-(-100), R_r-(-100))
            if R_cost > cost:
                R_cost = cost
                R_lr = [R_l,R_r]
        for B_l in range(r+1,max(100+B,r+1+B)+100):
            B_r = B_l+B-1
            cost = get_cost2(B_l-(100), B_r-(100))
            if B_cost > cost:
                B_cost = cost
                B_lr = [B_l, B_r]
        ans = min(ans, R_cost + G_cost + B_cost)
    print(ans)

if __name__ == '__main__':
    main()