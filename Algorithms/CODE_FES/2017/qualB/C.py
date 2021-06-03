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
    """
    辺(a,b)を結べるかどうかは、(a,b)の距離が奇数長かどうかと等しい
    なぜなら、(a,b)が奇数長なら(a,b)の間の3-stepを1-stepで出来るような辺を張れるのでいずれ3-stepになる。
    
    1.二部グラフでないなら、奇数サイクルが1つ以上存在する
        ―奇数サイクルがあるなら、サイクル上のvを通るようなpath(s,t)が存在し、それが偶数長でも余計に奇数サイクルを通ることで奇数長のパスを見つける事ができる
    2.二部グラフならグループ1とグループ2の任意の点を結ぶパスは奇数長になり、同グループのパスは偶数長になる
    """
    N,M=MI()
    edge = [[]for _ in range(N)]
    for _ in range(M):
        a,b = MI_()
        edge[a].append(b)
        edge[b].append(a)
    
    group = [-1]*N
    group[0] = 0

    def is_bipartite():
        stack = [0]
        while stack:
            v = stack.pop()
            for to in edge[v]:
                if group[to]!=-1 and group[to]==group[v]:
                    return False
                if group[to]==-1:
                    stack.append(to)
                    group[to] = group[v]^1
        return True

    bipartite = is_bipartite()
    if bipartite:
        g1 = group.count(0)
        g2 = N-g1
        ans = g1*g2
    else:
        ans = N*(N-1)//2
    ans -= M
    print(ans)

                
if __name__ == '__main__':
    main()