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
    N=I()
    if N%3!=0:
        if N%4:
            print(-1)
            return
        if N%4==0:
            ans = [["."]*N for _ in range(N)]
            for i in range(N):
                base = (i//4)*4
                if i%4==0:
                    ans[i][base]="a"
                    ans[i][base+1]="a"
                    ans[i][base+2]="c"
                    ans[i][base+3]="d"
                elif i%4==1:
                    ans[i][base]="b"
                    ans[i][base+1]="b"
                    ans[i][base+2]="c"
                    ans[i][base+3]="d"
                elif i%4==2:
                    ans[i][base]="c"
                    ans[i][base+1]="d"
                    ans[i][base+2]="a"
                    ans[i][base+3]="a"
                else:
                    ans[i][base]="c"
                    ans[i][base+1]="d"
                    ans[i][base+2]="b"
                    ans[i][base+3]="b"
                    
            for a in ans:
                print(*a,sep="")    
            return
    ans = [["."]*N for _ in range(N)]
    for i in range(N):
        base = (i//3)*3
        if i%3==0:
            ans[i][base]="a"
        elif i%3==1:
            ans[i][base]="a"
        else:
            ans[i][base+1]="a"
            ans[i][base+2]="a"
    for a in ans:
        print(*a,sep="")

if __name__ == '__main__':
    main()