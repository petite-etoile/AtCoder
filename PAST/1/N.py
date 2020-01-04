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
    N,W,C = MI()
    LRP = LLIN(N)
    place = set()
    imos = defaultdict(int)
    for l,r,p in LRP:
        
        place.add(l)
        place.add(r)
        place.add(r+1)
        imos[l]+=p
        imos[r+1]-=p
    place.add(0)
    so_place = sorted(place)
    d = {}
    # for i in enumerate(place)
    cumsum = []
    before = 0
    print(imos.items())
    for s in so_place:
        cumsum.append(before+imos[s])
        before += imos[s]
    print(so_place)
    print(cumsum)
    # r = 0
    # res = 0
    # ans = inf
    # for l,cost in imos.items():
    #     res += cost
    #     while r-l >= C:
    #         r=

    # ans = min(imos[r]-imos[l])
if __name__ == '__main__':
    main()