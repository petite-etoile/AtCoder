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
    A = [ST() for i in range(N)]
    B=[ST() for i in range(N)]
    edge = [[]for _ in range(N)]
    rev_edge = [[]for _ in range(N)]
    for from_,a in enumerate(A):
        for to_,bin in enumerate(a):
            if bin=="1":
                edge[from_].append(to_)
                rev_edge[to_].append(from_)
    pathAtoC = [set() for _ in range(N)]
    for from_,b in enumerate(B):
        for to_,bin in enumerate(b):
            if bin=="1":                
                pathAtoC[from_].add(to_)

    #print("rev",*rev_edge,sep="\n")
    #print("AtoC",*pathAtoC,sep="\n")


    edge_BtoC = [[0]*N for _ in range(N)]
    for to_ in range(N):
        if not rev_edge[to_]:
            #print(to_)
            continue
        S = set(pathAtoC[ rev_edge[to_][0] ])
        for from_ in rev_edge[to_]:
            S&=pathAtoC[from_]
        for C in S:
            #print(to_,C)
            edge_BtoC[to_][C] = 1
        #print(to_,S)
        #edge_BtoC[from_][to_]=1
    
    def is_ok():
        for A in range(N):
            for c in pathAtoC[A]:
                if 
    
    if is_ok()#条件を満たす:
        print(*edge_BtoC,sep="\n")
    else:
        print(-1)
if __name__ == '__main__':
    main()