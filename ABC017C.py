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
    N,M=MI()
    LRS=LLIN(N)
    LRS_lsort = sorted(LRS)
    LRS_rsort = sorted(LRS,key=lambda x: x[1],reverse=True)

    cumsum_left  =[0]*(M+2)
    cumsum_right =[0]*(M+2)

    now = 0
    for i in range(M+1)[::-1]:
        while LRS_lsort and LRS_lsort[-1][0]==i:
            now += LRS_lsort.pop()[2]
        cumsum_left[i]=now

    now = 0
    for i in range(M+1):
        while LRS_rsort and LRS_rsort[-1][1]==i:
            now += LRS_rsort.pop()[2]
        cumsum_right[i]=now

    ans = 0
    for i in range(1,M+1):
        ans = max(ans, cumsum_left[i+1]+cumsum_right[i-1])
    print(ans)
if __name__ == '__main__':
    main()