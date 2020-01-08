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
    LR=LLIN(3)
    ans = 0
    p = 1/(LR[0][1]-LR[0][0]+1)
    num2 = LR[1][1]-LR[1][0]+1
    num3 = LR[2][1]-LR[2][0]+1

    for x in range(LR[0][0],LR[0][1]+1):
        low = max(x+1,LR[1][0])
        high = LR[1][1]
        if low>high:
            continue
        p2 = ((high-low+1))/num2

        low = max(x+1,LR[2][0])
        high = LR[2][1]
        p3 = ((high-low+1))/num3
        if low>high:
            continue

        if p2>0 and p3>0:
            ans += p * p2 * p3
    print(ans)
if __name__ == '__main__':
    main()