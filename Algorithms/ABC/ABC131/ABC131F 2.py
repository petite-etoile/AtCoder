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
    N=I()
    XY=LLIN(N)
    MAX_XY = 10**5+1
    uf=UnionFind((MAX_XY)*2)
    get_root, unite, nodes=uf.get_root, uf.unite, uf.nodes
    
    """ 
    http://drken1215.hatenablog.com/entry/2019/06/23/004700
    ・二部グラフにして
    ・連結成分ごとに
    ・完全二部グラフにするように辺を追加する(この二部グラフの辺(x,y)はグリッド上の点(x,y)に対応する)
    """
    

    for x,y in XY:
        unite(x,y+MAX_XY)
    
    cnt_x = defaultdict(int)
    cnt_y = defaultdict(int)
    
    for x in range(MAX_XY):
        cnt_x[ get_root(x) ] += 1
    for y in range(MAX_XY,2*MAX_XY):
        cnt_y[ get_root(y) ] += 1
    
    ans = 0
    #rootが根の連結成分に含まれる(X座標の数)*(Y座標の数)だけ辺がある(もとからあるものは後で引く)
    for root in range(2*MAX_XY):
        ans += cnt_x[root] * cnt_y[root]
    
    ans -= N #もとからN個の辺はある
    print(ans)

    

if __name__ == '__main__':
    main()