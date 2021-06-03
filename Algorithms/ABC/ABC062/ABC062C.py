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
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf=float('inf')
mod = 10**9+7
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

    def solve(H,W):
        ans = inf
        for h in range(H):
            if not (H-h)&1 or not W&1:
                piece = [h*W, (W*(H-h))//2]
                ans = min(ans, max(piece)-min(piece))
            else:
                if (H-h)&1:
                    piece = [h*W, ((H-h-1)*W)//2, ((H-h+1)*W)//2]
                    ans = min(ans, max(piece)-min(piece))
                if W&1:
                    piece = [h*W, ((W-1)*(H-h))//2, ((W+1)*(H-h))//2]
                    ans = min(ans, max(piece)-min(piece))
        return ans    

    ans1 = solve(H,W)
    ans2 = solve(W,H)

    print(min(ans1,ans2))

if __name__ == '__main__':
    main()
