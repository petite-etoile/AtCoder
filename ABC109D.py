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
    H,W=MI()
    A=LLIN(H)
    odds=[]
    ans=[]
    for i in range(H):
        if i&1:
            for j in range(W)[::-1]:
                if A[i][j]&1:
                    if j==0:
                        dy=1
                        dx=0
                    else:
                        dy=0
                        dx=-1
                    if i+dy!=H:
                        print(i,i+dy,j,j+dx)
                        ans.append((i,j,i+dy,j+dx))
                        A[i+dy][j+dx]+=1
        else:
            for j in range(W)[::-1]:
                if A[i][j]&1:
                    if j==W-1:
                        dy=1
                        dx=0
                    else:
                        dy=0
                        dx=1
                    if i+dy!=H:
                        print(i,i+dy,j,j+dx)
                        ans.append((i,j,i+dy,j+dx))
                        A[i+dy][j+dx]+=1

    print(len(ans))
    for a in ans:
        print(*a)
    


if __name__ == '__main__':
    main()