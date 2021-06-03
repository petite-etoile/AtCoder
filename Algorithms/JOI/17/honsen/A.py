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
    N,Q,S,T = MI()
    A=LIN(N+1)
    B=[]
    for i,a in enumerate(A[:-1]):
        B.append(A[i+1]-a)
    
    ans = 0
    for b in B:
        if b>0:
            ans+=b*S
        else:
            ans+=b*T
    # print(-ans)
    LRH = LLIN(Q)

    for l,r,h in LRH:
        print(B)
        print(ans)
        
        if B[l-1]*(B[l-1]+h)>0:
            if B[l-1]>=0:
                ans+=h*S
            else:
                ans+=h*T
        else:
            if B[l-1]<0:
                ans+=abs(B[l-1])*T
                ans+=abs(B[l-1]+h)*S
            elif B[l-1]>0:
                ans-=abs(B[l-1])*S
                ans-=abs(B[l-1]+h)*T
            else:
                if h>0:
                    ans+=h*S
                else:
                    ans+=h*T
        print(ans)
        h*=-1
        if r<len(B):
            if B[r]*(B[r]+h)>0:
                if B[r]>=0:
                    ans+=h*S
                else:
                    ans+=h*T
            else:
                if B[r]>0:
                    # print(abs(B[r]+h)*T)
                    ans-=abs(B[r])*S
                    ans-=abs(B[r]+h)*T
                elif B[r]:
                    ans+=abs(B[r])*T
                    ans+=abs(B[r]+h)*S
                else:
                    if h>0:
                        ans+=h*S
                    else:
                        ans+=h*T
        # print(ans)
            
        h*=-1
        B[l-1] += h
        if r<len(B):
            B[r] -= h
        print(-ans)
        
if __name__ == '__main__':
    main()