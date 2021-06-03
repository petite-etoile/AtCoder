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
    N,M=MI()
    A=LI()

    uf=UnionFind(N)
    get_root, unite, nodes=uf.get_root, uf.unite, uf.nodes
    for _ in range(M):
        x,y = MI()
        unite(x,y)
    
    need = N-1-M #N-1本の辺が必要で、今M本の辺がある
    need *= 2 #辺の2倍の点を使う
    if need > N:
        print("Impossible")
        return 
    if need == 0:
        print(0)
        return

    root = defaultdict(list)
    for i,a in enumerate(A):
        root[get_root(i)].append(a)

    ans = 0
    whole = []

    #各連結成分から1つずつ、全体合計で2(N-1-M)点選ぶ
    for list_ in root.values():
        list_.sort()
        ans += list_[0]
        whole.extend(list_[1:])
        need-=1
    whole.sort()
    ans += sum(whole[:need])
    print(ans)


if __name__ == '__main__':
    main()