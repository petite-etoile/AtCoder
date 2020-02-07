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
    N,M = MI()
    XYZ = LLIN(N)

    a,b,c = [1<<i for i in range(3)]
    def f(x):
        x,y,z = x
        return abs(x) + abs(y) + abs(z)

    ans = 0
    for mask in range(1<<3):
        x_minus = bool(a&mask)
        y_minus = bool(b&mask)
        z_minus = bool(c&mask)

        XYZ.sort(reverse=True, key=lambda x: ((-1)**x_minus) * x[0] + ((-1)**y_minus) * x[1] + ((-1)**z_minus) * x[2] )
        x_sum, y_sum, z_sum = 0, 0, 0
        for x,y,z in XYZ[:M]:
            x_sum += x
            y_sum += y
            z_sum += z
        ans = max(ans, f((x_sum, y_sum, z_sum)))
    print(ans)
    

if __name__ == '__main__':
    main()