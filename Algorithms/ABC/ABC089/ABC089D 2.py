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
    H,W,D=MI()
    A=LLIN(H)
    
    def get_cost(fr:tuple, to:tuple):
        return abs(fr[0]-to[0]) + abs(fr[1]-to[1])

    cord_of_x = {}
    for h in range(H):
        for w in range(W):
            cord_of_x[A[h][w]] = (h,w)

    cumsum = [0]*(H*W+1+D)
    for x in range(1,H*W):
        if x+D not in cord_of_x:
            break
        cost = get_cost(cord_of_x[x], cord_of_x[x+D])
        cumsum[x+D]+=cumsum[x]+cost


    Q=I()
    LR=LLIN(Q)
    for l,r in LR:
        d = l%D
        print(cumsum[r]-cumsum[l])
if __name__ == '__main__':
    main()