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
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate, permutations, combinations, product, combinations_with_replacement
from bisect import bisect_left,bisect_right
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
    H, W = MI()
    S = [["#"] * W ]+ ["#"+ST()+"#" for _ in range(H)]
    up = [[0] * (W+2) for _ in range(H+2)]
    left = [[0]*(W+2) for _ in range(H+2)]
    right = [[0]*(W+2) for _ in range(H+2)]
    down = [[0] * (W + 2) for _ in range(H + 2)]
    
    for h in range(1, H+1):
        for w in range(1, W + 1):
            if S[h][w] == "#":
                continue
            else:
                up[h][w] = up[h-1][w] + 1
                left[h][w] = left[h][w-1] + 1
    for h in range(1, H+1)[::-1]:
        for w in range(1, W+1)[::-1]:
            if S[h][w] == "#":
                continue
            else:
                down[h][w] = down[h+1][w] + 1
                right[h][w] = right[h][w + 1] + 1
                
    ans = 0
    for h in range(1, H+1):
        for w in range(1, W + 1):
            if S[h][w] == ".":
                ans = max(ans, (left[h][w-1] + right[h][w+1]) + (up[h-1][w] + down[h+1][w])+1)
                #print(ans,h,w , left[h][w] , right[h][w]) , (up[h][w] , down[h][w])
                
    print(ans)

if __name__ == '__main__':
    main()