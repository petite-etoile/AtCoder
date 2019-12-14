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
# UnionFind
class UnionFind():
    def __init__(self, n):
        self.nodes=[-1] * n  # nodes[x]: 負なら、絶対値が木の要素数

    def get_root(self, x):
        # nodes[x]が負ならxが根
        if self.nodes[x] < 0:
            return x
        # 根に直接つなぎ直しつつ、親を再帰的に探す
        else:
            self.nodes[x]=self.get_root(self.nodes[x])
            return self.nodes[x]

    def unite(self, x, y):
        root_x=self.get_root(x)
        root_y=self.get_root(y)
        # 根が同じなら変わらない
        # if root_x == root_y:
        # pass
        if root_x != root_y:
            # 大きい木の方につないだほうが計算量が減る
            if self.nodes[root_x] < self.nodes[root_y]:
                big_root=root_x
                small_root=root_y
            else:
                small_root=root_x
                big_root=root_y
            self.nodes[big_root] += self.nodes[small_root]
            self.nodes[small_root]=big_root
def main():
    N,M=MI()
    xyc=LLIN(N)
    XYC=LLIN(M)
    xyc___ = xyc+XYC

    edge = []
    for i in range(N+M):
        for j in range(i+1,N+M):
            x,y,c = xyc___[i]
            X,Y,C = xyc___[j]
            cost = hypot(x-X,y-Y)
            if c!=C:
                cost *= 10
            edge.append((cost,i,j))
            edge.append((cost,j,i))
    edge.sort()
    def solve(M_bit,edge):
        exist=set([i for i in range(N)])
        for i in range(M):
            if (M_bit>>i)&1:
                exist.add(i+N)


        uf=UnionFind(N+M)
        get_root, unite, nodes=uf.get_root, uf.unite, uf.nodes
        res = 0
        for cost,u,v in edge:
            if get_root(u)!=get_root(v) and u in exist and v in exist:
                unite(u,v)
                res += cost
        return res

    ans = inf
    bit_max = 1<<M
    for i in range(bit_max):
        ans = min(ans,solve(i,edge))
    print(ans)
if __name__ == '__main__':
    main()