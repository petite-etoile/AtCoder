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
    H,W,T = MI()
    S=[ST() for _ in range(H)]
    start = -1
    for h in range(H):
        for w in range(W):
            if S[h][w]=="S":
                start=(h,w)

    dxdy = [(1,0),(-1,0),(0,1),(0,-1)]
    def is_inside(h,w):
        return (0<=h<H and 0<=w<W)

    def is_ok(x):
        queue = [(0,start)]
        visited = set()
        while queue:
            dist,(h,w) = heappop(queue)
            fr=(h,w)
            visited.add(fr)
            for dx,dy in dxdy:
                # print(fr,dy)
                to = (fr[0]+dy,fr[1]+dx)
                if to in visited or not is_inside(to[0],to[1]):
                    continue
                visited.add(to)
                h,w=to
                if S[h][w]==".":
                    cost = 1
                elif S[h][w]=="#":
                    cost = x
                else:
                    return 1+dist<=T
                heappush(queue,(dist+cost,(to[0],to[1])))


    ng = 10**9+1
    ok=0
    while ng-ok>1:
        mid=(ng+ok)//2
        if is_ok(mid):
            ok = mid
        else:
            ng = mid
    print(ok)
if __name__ == '__main__':
    main()