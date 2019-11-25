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
from math import floor,ceil,sqrt,factorial
from heapq import heappop, heappush, heappushpop
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
    
    N = I()
    uf=UnionFind(N)
    get_root, unite, nodes=uf.get_root, uf.unite, uf.nodes
    xlist = []
    ylist = []
    for i in range(N):
        x, y = MI()
        xlist.append((x, i))
        ylist.append((y, i))
    xlist.sort()
    ylist.sort()
    
    edges = [] #(重み、頂点a,b)
    for i in range(N - 1):
        edges.append((xlist[i+1][0]-xlist[i][0], xlist[i][1],xlist[i+1][1]))
        edges.append((ylist[i+1][0]-ylist[i][0],ylist[i][1], ylist[i + 1][1]))
    edges.sort(reverse=True)

    cnt = 1
    ans=0
    while cnt<N:
        c, a, b = edges.pop()
        if get_root(a) != get_root(b):
            unite(a, b)
            cnt += 1
            ans += c
    print(ans)
if __name__ == '__main__':
    main()