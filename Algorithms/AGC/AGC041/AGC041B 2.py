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
    N,M,V,P=MI()
    A=LI()
    A.sort()
    rival = N-P
    while rival>0 and A[rival]==A[rival-1]:
        rival-=1
    rival = A[rival]
    def is_ok(x,V):
        # V-=x+1 #自分含め下位
        if x==N-1:
            return True
        if V==N:#全員投票される
            return A[x]>=rival
        print(x,rival-A[x],M)
        return A[x]>=rival or rival-A[x]<=M
        # if V<=0:
        #     return abs(A[x]-rival)<=M
        # if V>=N-1-rival:
        #     return abs(A[x]-rival)
        # else:
        #     print(x)
        #     return abs(A[N-V-1]-A[x])<M
            
        
    print(A)
    ok = N-1
    ng = -1
    while abs(ok-ng)>1:
        mid = (ok-ng)//2
        print(ok,ng,mid,is_ok(mid,V))
        if is_ok(mid,V):
            ok = mid
        else:
            ng = mid
    print(N-ok)
if __name__ == '__main__':
    main()