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
    H,W,K = MI()
    grid = []
    for i in range(H):
        grid.append(ST())

    ans = [[0]*W for _ in range(H)]
    first = [[] for _ in range(H)]
    num = 0
    for i,row in enumerate(grid):
        for index,x in enumerate(row):
            if x=="#":
                first[i].append(index)
                num+=1
                ans[i][index] = num
    
    for h in range(H):
        if first[h]:
            before = first[h][0]
        else:
            continue
        for w in range(W):
            if grid[h][w] == "#":
                before = w
            else:
                ans[h][w] = ans[h][before]
    
    for h in range(1,H):
        for w in range(W):
            if ans[h][w] == 0:
                ans[h][w] = ans[h-1][w]
    for h in range(H-1)[::-1]:
        for w in range(W):
            if ans[h][w] == 0:
                ans[h][w] = ans[h+1][w]
    for a in ans:
        print(*a)

    # print(["".join(a) for a in ans],sep="\n")      
if __name__ == '__main__':
    main()