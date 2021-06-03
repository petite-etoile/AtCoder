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
    N,X=MI()
    if(X==1 or X==2*N-1):
        if(N==1):
            print("Yes")
            print(1)
        else:
            print("No")
    else:
        if(N==2):
            if(X==2):
                print("Yes")
                print("1\n2\n3")
            else:
                print("No")
        else:
            ans = [-1]*(2*N-1)
            ans[N-2] = 1
            ans[N-1] = X
            ans[N] = 2*N-1
            used = set([X,1,2*N-1])
            now = 2
            for i in range(N+1,2*N-1):
                while(now in used):
                    now += 1
                ans[i] = now
                used.add(now)
            for i in range(N-2):
                while(now in used):
                    now += 1
                ans[i] = now
                used.add(now)
            print("Yes")
            # print(ans)
            print(*ans,sep="\n")
if __name__ == '__main__':
    main()