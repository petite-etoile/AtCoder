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
    N=I()
    edge = [[] for i in range(N)]
    e_index = []
    for i in range(N-1):
        a,b = MI_()
        edge[a].append(b)
        edge[b].append(a)
        e_index.append((a,b))
    queue = deque()
    queue.append((0,0))
    ans_col = {}
    visited = set()
    K=1
    while queue:
        from_,col = queue.popleft()
        if from_ in visited:
            continue
        visited.add(from_)
        now = 1
        for to in edge[from_]:
            if to in visited:
                continue
            if now == col:
                now += 1
            ans_col[from_,to] = now
            ans_col[to,from_] = now
            queue.append((to,now))
            K = max(now,K)
            now += 1
    print(K)
    for a,b in e_index:
        print(ans_col[a,b])

if __name__ == '__main__':
    main()