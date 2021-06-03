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
    H, W, K = MI()
    cum_row = [W] * H
    cum_column = [H] * W
    for _ in range(K):
        r, c = MI_()
        cum_row[r] -= 1
        cum_column[c] -= 1
    
    koma_num = H * W - K
    half_num = koma_num / 2
    
    * cumcum_row, = accumulate(cum_row)
    * cumcum_column, = accumulate(cum_column)
    
    R = bisect_left(cumcum_row, half_num)
    C = bisect_left(cumcum_column, half_num)

    ans = 0
    for r, n in enumerate(cum_row):
        ans += abs(R - r) * n
    for c, n in enumerate(cum_column):
        ans += abs(C - c) * n

    print(ans)
if __name__ == '__main__':
    main()