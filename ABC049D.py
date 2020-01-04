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
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
inf=float('inf')
mod = 10**9+7
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
    N, K, L = MI()
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
            
        def same(self,x,y):
            return self.get_root(x)==self.get_root(y)
    uf1=UnionFind(N)
    uf2 = UnionFind(N)
    uf_both = UnionFind(N)
    for _ in range(K):
        p, q = MI_()
        uf1.unite(p, q)
        
    for _ in range(L):
        r, s = MI_()
        uf2.unite(r, s)

    cnt = defaultdict(int)    
    A = [-1]*N
    B = [-1]*N
    for i in range(N):
        A[i] = uf1.get_root(i)
        B[i] = uf2.get_root(i)
        cnt[A[i],B[i]] += 1
    
    print(*[cnt[A[i],B[i]] for i in range(N)] )


if __name__ == '__main__':
    main()