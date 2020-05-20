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
    H,W=MI()
    def is_inside(hw):
        h,w = hw
        return 0<=h<H and 0<=w<W
    grid=[[s for s in ST()] for _ in range(H)]
    ans = 0
    dxdy = [(1,0),(0,1),(-1,0),(0,-1)]
    for i in range(H*W):
        h = i//W
        w = i%W
        if grid[h][w] == "#":
            continue
        visited = set()
        q = [(h,w)]
        for cost in range(H*W+1):
            tmp = []
            if not q:
                ans = max(ans,cost-1)
                break
            while q:
                from_ = q.pop()
                if from_ in visited:
                    continue
                visited.add(from_)
                for dh,dw in dxdy:
                    to = (from_[0]+dh, from_[1]+dw)
                    if is_inside(to) and to not in visited and grid[to[0]][to[1]]==".":
                        tmp.append(to)
            q = tmp
    print(ans)
if __name__ == '__main__':
    main()