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
    N=I()
    S=ST()
    S+=S[0]
    def is_ok():
        for i,s in enumerate(S[1:-1],start=1):
            if ans[i]==(s=="o"):
                ans[i+1]=ans[i-1]
            else:
                ans[i+1]=ans[i-1]^1
        ok = (ans[0]==ans[-1])
        if ans[0]==(S[0]=="o"):
            if ans[1]!=ans[-2]:
                ok=False
        else:
            if ans[1]==ans[-2]:
                ok=False
        return ok

    for bit in range(1<<2):
        ans=[0]*(N+1)
        for i in range(2):
            ans[i] = bit>>i&1
        if is_ok():
            ans="".join(map(str,ans[:-1]))
            print(ans.replace("1","S").replace("0","W"))
                
            return
    print(-1)
if __name__ == '__main__':
    main()