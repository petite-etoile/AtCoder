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
    S=ST()
    lefter = 0
    righter = 0
    last = -1
    ans = [0]*len(S)
    last_is_R = True
    for i,s in enumerate(S):
        
        #print(lefter,last,righter)
        if last_is_R and s == "L":
            #print("lefter",lefter)
            #RLゾーン
            last = i
            ans[last]+=lefter//2
            ans[last-1]+=ceil(lefter/2)
            lefter = 0
            righter = 0
        elif not last_is_R and s == "R":
            #print("righter",righter)
            ans[last] += ceil(righter/2)
            ans[last-1] += righter//2
            righter = 0

        lefter += 1
        righter += 1

        if s == "L":
            last_is_R = False
            lefter = 0
        else:
            last_is_R = True
            righter = 0

    ans[last] += ceil(righter/2)
    ans[last-1] += righter//2
    print(*ans)
if __name__ == '__main__':
    main()