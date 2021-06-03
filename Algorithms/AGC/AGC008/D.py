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
    XI=[(x-1,i) for i,x in enumerate(MI())]
    XI.sort()
    remain = [N-i-1 for i in range(N)]
    idx = 0
    ans = [None]*(N*N)
    ok = True
    for x,i in XI:
        for _ in range(i):
            while(idx<N*N and ans[idx] is not None):
                idx += 1
            if(idx >= x):
                ok = False
                break
            ans[idx] = i
            idx += 1
        ans[x] = i

    for x,i in XI:
        for _ in range(remain[i]):
            while(idx<N*N and ans[idx] is not None):
                idx += 1
            if(idx < x):
                ok = False
            ans[idx] = i
            idx += 1

    if(not ok):
        print("No")
        return 
    print("Yes")
    print(*[a+1 for a in ans])
if __name__ == '__main__':
    main()