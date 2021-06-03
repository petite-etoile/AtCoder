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
    N, M = MI()
    edge = [[] for _ in range(N)]
    for _ in range(M):
        u,v = MI_()
        edge[u].append(v)
    S, T = MI_()

    queue = [S]
    checked = set()
    for i in range(1,max(3*N+1,3*M+2)):
        tmp = set()
        while queue:
            s = queue.pop()
            if i % 3 == 0:
                if s in checked:
                    continue
                else:
                    checked.add(s)
            for to in edge[s]:
                if to == T:
                    if i%3==0:
                        print(i//3)
                        exit()
                tmp.add(to)
        queue = tmp
    print(-1)
            

if __name__ == '__main__':
    main()