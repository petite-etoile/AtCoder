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
def f(S):
    worst = 0
    res = 0
    for s in S:
        if(s=='('):
            res += 1
        else:
            res -= 1
        worst = min(worst, res)
    return worst, res
def main():
    N=I()
    S=[ST() for _ in range(N)]
    
    AB_nega=[]
    AB_nonnega=[]
    for i in range(N):
        a,b = f(S[i])
        if b<0:
            AB_nega.append((a,b))
        else:
            AB_nonnega.append((a,b))
    
    AB_nega.sort(key=lambda x:-x[0]+x[1], reverse =True)
    AB_nonnega.sort(reverse = True)

    # print(AB_nega)
    # print(AB_nonnega)

    now = 0
    for a,b in AB_nonnega:
        if(now+a < 0):
            print("No")
            return
        now += b
        # print(now,"#######")
    
    
    for a,b in AB_nega:
        if(now+a<0):
            print("No")
            return
        now += b
        # print(now,"#########")
    if now == 0:
        print('Yes')
    else:
        print("No")


    
if __name__ == '__main__':
    main()