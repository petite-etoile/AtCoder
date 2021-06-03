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
    H,W=MI()
    ans = inf
    for w in range(1,W):
        A=w*H
        remain = H*W-A
        B=remain//(W-w)//2*(W-w)
        C=remain-B
        ans = min(ans, max(A,B,C)-min(A,B,C))
    for h in range(1,H):
        A=h*W
        remain = W*H-A
        B=remain//(H-h)//2*(H-h)
        C=remain-B
        ans = min(ans, max(A,B,C)-min(A,B,C))
    if W%3==0 or H%3==0:
        print(0)
        return
    A = H//3*W
    if A:
        remain = H*W-A
        B=remain//2
        C=remain-B
        ans = min(ans, max(A,B,C)-min(A,B,C))
    
    A = W//3*H
    if A:
        remain = W*H-A
        B=remain//2
        C=remain-B
        ans = min(ans, max(A,B,C)-min(A,B,C))
    

    print(ans)
if __name__ == '__main__':
    main()