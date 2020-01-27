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

def main():
    N,M,D = MI()
    A=LI()

    from_ = [i for i in range(N)]
    for a in A:
        from_[a-1],from_[a] = from_[a], from_[a-1]
    
    to = [0]*N #to[i] := iのあみだくじ1回の行き先
    for i,f in enumerate(from_):
        to[f] = i
    
    root = [-1]*N
    loop_list = [[] for _ in range(N)]
    idx_in_loop = [0]*N
    for i in range(N):
        if root[i] == -1: ##まだ他のループに含まれていない
            now = i
            idx = 0
            while 1: 
                loop_list[i].append(now)
                idx_in_loop[now] = idx
                now = to[now]
                root[now] = i
                idx += 1
                if now == i:
                    break
            

    ans = [0]*N
    for i in range(N):
        l = loop_list[root[i]]
        idx = idx_in_loop[i]
        loop_length = len(l)
        K = D

        K %= loop_length
        ans[i] = l[(K+idx)%loop_length]
    print(*[a+1 for a in ans],sep="\n")

        

if __name__ == '__main__':
    main()