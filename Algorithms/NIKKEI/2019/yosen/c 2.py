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
def len_cycle(edge, start=0):
    stack = [start]
    cnt = 0
    pop, push = stack.pop, stack.append
    while stack:
        cnt+=1
        from_ = pop()
        for to in edge[from_]:
            push(to)
            if to == start:
                return cnt
    return 0
def main():
    N=I()
    A=LI()
    B=LI()

    A_with_index = [(a,i) for i,a in enumerate(A)]
    B_with_index = [(b,i) for i,b in enumerate(B)]
    A_with_index.sort()
    B_with_index.sort()

    for i,(a,_) in enumerate(A_with_index):
        b = B_with_index[i][0]
        if a>b:
            print("No")
            return

    B_dict = {}
    for j,(b,i) in enumerate(B_with_index):
        B_dict[j] = i

    edge = [[]for _ in range(N)]
    for i,(a,from_) in enumerate(A_with_index):
        to = B_dict[i]
        edge[from_] += to,

    cycle = len_cycle(edge)
    if cycle != N:
        print("Yes")
        return 
    for i in range(N-1):
        a = A_with_index[i+1][0]
        b = B_with_index[i][0]
        if a<=b:#辺を組み替えてサイクルを2つに分割できる
            print("Yes")
            return
    print("No")




if __name__ == '__main__':
    main()