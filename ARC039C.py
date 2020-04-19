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
left = 0
right = 1
up = 2
down = 3
def init(x,y,z):
    if(z ==  left):
        return x-1,y
    elif(z == right):
        return x+1,y
    elif(z == up):
        return x,y+1
    elif(z == down):
        return x,y-1
def main():
    N=I()
    S=ST()
    now = [0,0]
    adjacent = {}
    opposite = { left:right, right:left, up:down, down:up }
    for s in S:
        s = "LRUD".index(s)

        for direct in range(4):
            if(now[0],now[1],direct) not in adjacent.keys():
                adjacent[now[0],now[1],direct] = init(now[0],now[1],direct)
            next_ = adjacent[now[0],now[1],direct]

            if (now[0],now[1],opposite[direct]) not in adjacent.keys():
                adjacent[now[0],now[1],opposite[direct]] = init(now[0],now[1],opposite[direct])
            adjacent[next_[0],next_[1],opposite[direct]] = adjacent[now[0],now[1],opposite[direct]]

        now = adjacent[now[0],now[1],s]
    print(*now)
if __name__ == '__main__':
    main()