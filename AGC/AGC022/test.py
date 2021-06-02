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
MAX = 30000
def dfs(A:list,idx:int,now:int):
    if(idx==len(A)):
        if(is_ok(A)):
            print(A)
        return
    for a in range(now, MAX+1):
        A[idx] = a
        dfs(A,idx+1,a+1)
    
def is_ok(A:list):
    # print(A)
    S=sum(A)
    if(max(A) > MAX or len(set(A))!=len(A)):
        return False
    g = 0
    ok = True
    for a in A:
        g = gcd(g,a)
        if(gcd(a,S-a) == 1):
            return False
    return g==1
def main():
    # N = I()
    # A=[inf]*N
    # dfs(A,0,2)
    A=LI()
    print(is_ok(A))
if __name__ == '__main__':
    main()