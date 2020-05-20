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
    N,L,R=MI()
    edge = [ [] for i in range(N)]
    for i in range(N):
        if(i):
            edge[i].append(i-1)
        if(i<N-1):
            edge[i].append(i+1)
    L-=1
    R-=1
    edge[L].append(R)
    edge[R].append(L)
    ans = [0]*N
    for i in range(N):
        q = [i]
        visited = set()
        for step in range(N):
            tmp = []
            while(q):
                v = q.pop()
                if(v in visited):
                    continue
                ans[step] += 1
                visited.add(v)
                for to in edge[v]:
                    if(to in visited):
                        continue
                    tmp.append(to)
            q = tmp
    print(*[a//2 for a in ans[1:]],sep="\n")
if __name__ == '__main__':
    main()