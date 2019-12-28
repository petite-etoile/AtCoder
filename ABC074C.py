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
    A,B,C,D,E,F = MI()
    A*=100
    B*=100
    water = []
    can = [False]*3001
    can[0] = True
    for i in range(3001-A):
        if can[i]:
            can[i+A] = True
    for i in range(3001-B):
        if can[i]:
            can[i+B] = True
    for i in range(1,3001):
        if can[i]:
            water.append(i)

    can = [False]*3001
    can[0] = True
    for i in range(3001-C):
        if can[i]:
            can[i+C] = True
    for i in range(3001-D):
        if can[i]:
            can[i+D] = True
    
    suger = []
    for i in range(1,3001):
        if can[i]:
            suger.append(i)
    
    # print(water)
    # print(suger)

    ans = 0
    ans_water = A
    ans_suger = 0
    for w in water:
        want = min(F-w, (w//100)*E)
        idx = bisect_right(suger, want)
        if idx:
            s = suger[idx-1]
            if ans < s/(w+s):
                ans = s/(w+s)
                ans_water=w
                ans_suger=s
                
    print(ans_water+ans_suger,ans_suger)
if __name__ == '__main__':
    main()