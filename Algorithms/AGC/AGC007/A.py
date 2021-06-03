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
    H,W=MI()
    grid=[ST() for _ in range(H)]
    
    ans = True
    stack = [(0,0)]
    visited = set()
    while(stack):
        v = stack.pop()
        visited.add(v)
        for dh,dw in [(-1,0), (1,0), (0,-1), (0,1)]:
            to_h,to_w = v[0]+dh, v[1]+dw
            if(not(0<=to_h<H) or not(0<=to_w<W)):
                continue
            if(to_h,to_w) in visited:
                continue
            if(grid[to_h][to_w] == "#" and -1 in (dh,dw)):
                ans = False
            if(grid[to_h][to_w] == "#"):
                stack.append((to_h,to_w))
        if(len(stack) >= 2): 
            ans = False   
    if(ans):
        print("Possible")
    else:
        print("Impossible")
if __name__ == '__main__':
    main()