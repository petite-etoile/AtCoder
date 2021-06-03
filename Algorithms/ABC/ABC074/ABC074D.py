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
    # ワーシャルフロイド
    def warshall_floyd(d, N):
        for k in range(N):
            for i in range(N):
                for j in range(N):
                    d[i][j]=min(d[i][j], d[i][k] + d[k][j])
    
    N=I()
    A=LLIN(N)
    d=deepcopy(A)
    warshall_floyd(d, N)

    edge = []
    for i in range(N):
        for j in range(i+1,N):
            edge.append((A[i][j],i,j))
    edge.sort()

    ans = 0
    for a,i,j in edge:
        if d[i][j]<a:
            print(-1)
            return
        need = True
        for k in range(N):
            if k in (i,j):
                continue
            if a==d[i][k]+d[k][j]:
                need = False
                break
        if need:
            ans += a
    print(ans)
        
if __name__ == '__main__':
    main()