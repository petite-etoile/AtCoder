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
    def is_inside(h,w):
        return (0<=h<H and 0<=w<W)

    S=[ST() for _ in range(H)]
    ans = [["#"]*W for _ in range(H)]
    for h in range(H):
        for w in range(W):
            if S[h][w]==".":
                ans[h][w]="."
                continue
            for dx in range(-1,2):
                for dy in range(-1,2):
                    if (dx,dy)==(0,0):
                        continue
                    if not is_inside(h+dy,w+dx):
                        continue
                    # print(h,w)
                    # print(ans[h])
                    if S[h+dy][w+dx]==".":
                        ans[h][w]="."

    possible=True
    for h in range(H):
        for w in range(W):
            if S[h][w]=="." or ans[h][w]=="#":
                continue
            ok = False
            for dx in range(-1,2):
                for dy in range(-1,2):
                    if (dx,dy)==(0,0):
                        continue
                    if not is_inside(h+dy,w+dx):
                        continue
                    if ans[h+dy][w+dx]=="#":
                        ok=True
            if not ok:
                possible=False
    if possible:
        print("possible")
        for a in ans:
            print(*a,sep="")
    else:
        print("impossible")

if __name__ == '__main__':
    main()