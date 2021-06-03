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
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
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
    
    N, K = MI()
    A = LI()
    
    ans = 0
    left = 0
    right = 0
    now = 0
    *cum, = [0]+list(accumulate(A))


    for right, a in enumerate(A):
        """if 0 <= left <= right and cum[right + 1] - K>=0:# and cum[right+1] - cum[left] >= K:
            print(cum[right+1],left,cum[left],cum[right + 1] - K)
            ans += left+1"""
        while left != right and cum[right + 1] - cum[left] >= K:
            print(left,right)
            left += 1
        if left > 0 and cum[right+1] - cum[left] < K:
            left -= 1
        print(left,right)
        if cum[right+1] - cum[left] >= K:
            ans += left + 1
    print(ans)
if __name__ == '__main__':
    main()