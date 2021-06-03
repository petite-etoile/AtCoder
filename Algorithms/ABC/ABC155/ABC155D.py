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
from math import floor,sqrt,factorial,hypot,log,ceil #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
# def ceil(a,b): return (a+b-1)//b
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
    N,K=MI()
    A=LI()
    B=[-a for a in A]
    sort_A1 = sorted(A)
    # sort_A2 = sorted(A,reverse=True)

    def is_ok(x): #x以下の数がK個以下ならok
        cnt = 0
        for a in A:
            if a==0:
                if x<=0:
                    cnt += N-1
                continue
            need = x//a
            if need<0 and need!=x/a:
                need-=1
            if need>0 and need!=x/a:
                need+=1
            if a<0:
                cnt += N-bisect_right(sort_A1, need)
                if need<a:
                    cnt -= 1
            else:
                cnt += bisect_left(sort_A1, need)
                if need>a:
                    cnt -= 1
        cnt//=2
        return cnt <= K-1

    ok = -10**9
    ng =  10**9
    
    while abs(ng-ok)>1:
        mid = (ok+ng)//2
        if is_ok(mid):
            ok = mid
        else:
            ng = mid
    print(ng)        


if __name__ == '__main__':
    main()