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
    H,W = MI()
    def is_inside(to):
        return 0<=to[0]<H and 0<=to[1]<W
    S=[ST() for _ in range(H)]
    queue = deque([(0,0)])
    visited = set()
    ans=0
    for s in S:
        ans += Counter(s)["."]
    for i in range(H*W+1):
        tmp = deque()
        while queue:
            fr = queue.popleft()
            if fr in visited:
                continue
            visited.add(fr)
            for dh,dw in [(-1,0),(0,-1),(1,0),(0,1)]:
                to = (fr[0]+dh,fr[1]+dw)
                if to not in visited and is_inside(to) and S[to[0]][to[1]]==".":
                    tmp.append(to)
        queue = tmp
        if (H-1,W-1) in tmp:
            print(ans-(i+2))
            return
    print(-1)
if __name__ == '__main__':
    main()