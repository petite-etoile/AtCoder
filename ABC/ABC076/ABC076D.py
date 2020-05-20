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
    N=I()
    T=LI()
    V=LI()
    T_sum = sum(T)

    #初期化
    max_V = [inf]*(2*T_sum+1)
    now = 0
    for i,(t,v) in enumerate(zip(T,V)):
        max_V[now] = min(max_V[now], v)
        for dt in range(2*t):
            now += 1
            max_V[now] = min(max_V[now], v)
    max_V[0] = 0
    max_V[-1] = 0


    #前から
    for i in range(2*T_sum):
        max_V[i+1] = min(max_V[i+1], max_V[i]+0.5)

    for i in range(2*T_sum)[::-1]:
        max_V[i] = min(max_V[i], max_V[i+1]+0.5)

    #計算部分
    ans = 0
    for i in range(2*T_sum):
        ans += (max_V[i]+max_V[i+1])/2

    ans /= 2
    print(ans)
            

if __name__ == '__main__':
    main()