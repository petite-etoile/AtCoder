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
from heapq import heappop, heappush, heappushpop, heapify
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
    N=I()
    C=LI()
    Q=I()
    S=LLIN(Q)
    odd = C[1::2]
    even = C[::2]
    all_ = C.copy()
    heapify(odd)
    heapify(even)
    heapify(all_)
    all_sub = 0
    even_sub = 0

    ans = 0
    for q,*s in S:
        # print("even",even)
        # print(all_sub,even_sub,"------")
        if q==1:
            x,a = s
            x-=1
            if (x%2==0):
                if (C[x]-all_sub-even_sub)>=a:
                    C[x]-=a
                    heappush(all_,C[x])
                    heappush(even,C[x])
                    ans += a
            else:
                if (C[x]-all_sub)>=a:
                    C[x]-=a
                    heappush(all_,C[x])
                    ans += a
        else:
            a = s[0]
            if q==2:
                if even[0]-all_sub-even_sub>=a:
                    # heappush(even,even[0])
                    even_sub+=a
                    ans += a*ceil(N/2)
            else:
                mini = min(even[0]-all_sub-even_sub,all_[0]-all_sub)
                # print(mini,even[0]-all_sub-even_sub,all_[0]-all_sub)
                if mini>=a:
                    # heappush(all_,mini-a)
                    all_sub+=a
                    ans += a*N
        # print(q,ans,"##")
    print(ans)
if __name__ == '__main__':
    main()