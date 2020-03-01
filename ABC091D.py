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
    #28*2*(10^5)*log2(10^5)
    N=I()
    A=LI()
    B=sorted(LI())
    ans = 0
    for k in range(28):
        A_ = [a&((1<<(k+1))-1) for a in A]
        B_ = [a&((1<<(k+1))-1) for a in B]
        B_.sort()
        cnt = 0
        for a in A_:
            #2**K <= a+b < 2**(K+1)
            cnt += bisect_left(B_, 2**(k+1) - a) - bisect_left(B_, 2**k - a) 
            #2**K + 2**(K+1) <= a+b < 2**(K+2)
            cnt += bisect_left(B_, 2**(k+2) - a) - bisect_left(B_, 2**(k+1) + 2**k - a) 
        if cnt&1:
            ans += 1<<k
    print(ans)

if __name__ == '__main__':
    main()