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
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
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
    N = I()
    LR=LLIN_(N)
    L_sort = sorted(LR)
    R_sort = sorted(LR,key=lambda x: x[1])
    
    # print(L_sort)
    # print()
    # print(R_sort)
    
    def get_fun(A,i):
        left = -1
        right = 10**9+7
        for l,r in A[:i]:
            left=max(left,l)
            right=min(right, r)
        res = max(0,right-left+1)

        left = -1
        right = 10**9+7
        for l,r in A[i:]:
            left=max(left,l)
            right=min(right, r)
        res += max(0,right-left+1)
        
        return res
    
    ans = 0
    left = 0
    right = N
    while left+2<right:
        ml = (left*2+right)//3
        mr = (left+right*2)//3
        if get_fun(L_sort,ml)<get_fun(L_sort,mr):
            left=ml
        else:
            right=mr
    ans = get_fun(L_sort,(left+right)//2)

    left = 0
    right = N
    while left+2<right:
        ml = (left*2+right)//3
        mr = (left+right*2)//3
        if get_fun(R_sort,ml)<get_fun(R_sort,mr):
            left=ml
        else:
            right=mr
    ans = max(ans,get_fun(R_sort,(left+right)//2))

    m =max(LR,key=lambda x: x[1]-x[0])
    i = LR.index(m)
    left = 0
    right = 10**9+4
    for j,(l,r) in enumerate(LR):
        if i==j:
            continue
        left=max(left,l)
        right=min(right, r)
    ans = max(ans, max(0,(right-left+1))+m[1]-m[0])


    print(ans)



if __name__ == '__main__':
    main()