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
from math import floor,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
def ceil(a,b): return (a+b-1)//b
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
    N=I()
    A=LIN(N)
    Q=I()
    query=LIN(Q)

    A.sort(reverse = True)
    cumsum = [[A[0]+1,0]]
    for a in A:
        if(a==0):
            break
        if cumsum[-1][0] == a:
            cumsum[-1][1] += 1
        else:
            cumsum.append([a,cumsum[-1][1] + 1])
    cumsum.append([0,cumsum[-1][1]])
    cumsum = cumsum[::-1]
    
    def is_ok(x,q):
        n = cumsum[x][1]
        return n<=q


    for q in query:
        ok = len(cumsum)-1
        ng = -1
        while ok-ng>1:
            mid = (ok+ng)//2
            if(mid == ng):
                break
            if(is_ok(mid,q)):
                ok = mid
            else:
                ng = mid
        if(ok):
            print(cumsum[ok-1][0]+1)
        else:
            print(0)

if __name__ == '__main__':
    main()
