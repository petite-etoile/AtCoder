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
    N=I()
    edge = [[] for _ in range(N)]
    for i in range(N-1):
        a,b = MI_()
        edge[a].append(b)
        edge[b].append(a)
    
    root = 0
    q = []
    q.append(root)
    pre = [-1]*N
    visited = [False]*N
    while q:
        v = q.pop() 
        visited[v] = True
        for to in edge[v]:
            if visited[to]:
                continue
            pre[to] = v
            q.append(to)
    
    path = [] #パスに含まれる辺(根に向かう方で保存)
    constraint = []
    M=I()
    for i in range(M):
        a,b = MI_()
        constraint.append((a,b))

        
        root_path_a = 1<<a
        root_path_b = 1<<b
        
        while a!=root:
            root_path_a |= 1<<pre[a]
            a = pre[a]
        while b!=root:
            root_path_b |= 1<<pre[b]
            b = pre[b]
        path.append(root_path_a ^ root_path_b) #LCAまでのみ
        if not path[-1]>>a&1:
            path[-1] |= 1<<a
        if not path[-1]>>b&1:
            path[-1] |= 1<<b
    

    ans = 0
    for mask in range(1<<M):
        builtin_count = 0
        U = 0 #pathに含まれる辺
        for i in range(M):
            if mask>>i&1:
                builtin_count += 1
                U |= path[i]
        edge_cnt = max(0,bin(U).count("1")-1)
        if builtin_count&1:
            ans -= 1<<(N-1-edge_cnt)
        else:
            ans += 1<<(N-1-edge_cnt)
    print(ans)



if __name__ == '__main__':
    main()