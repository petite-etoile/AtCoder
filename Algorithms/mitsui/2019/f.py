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
from fractions import gcd
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
    T1,T2 = MI()
    A1,A2 = MI()
    B1,B2 = MI()
    if T1*A1+T2*A2==T1*B1+T2*B2:
        print("infinity")
        exit()
    A1*=T1
    B1*=T1
    A2*=T2
    B2*=T2
    diff1 = A1-B1
    diff2 = A2-B2
    # print(diff1,diff2)

    if diff1*diff2>0:
        print(0)
    else:
        if abs(diff1)>abs(diff2):
            print(0)
            exit()
        else:
            ans = 2 * (abs(diff1) // abs(diff1+diff2))
            if diff1//(diff1+diff2) == diff1/(diff1+diff2):
                ans -= 1 ##ピッタリ原点
            print(ans + 1)
    

if __name__ == '__main__':
    main()