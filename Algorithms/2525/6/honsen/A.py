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
    H,W = MI()
    if H==1:
        if W%7==0:
            print("Yes")
            print("2255555"*(W//7))
        elif W%7==2:
            print("Yes")
            print("22"+"5555522"*(W//7))
        elif W%7==5:
            print("Yes")
            print("55555"+"2255555"*(W//7))
        else:
            print("No")
        return
    if W==1:
        if H%7==0:
            print("Yes")
            print(*("2255555"*(H//7)),sep="\n")
        elif H%7==2:
            print("Yes")
            print(*("22"+"5555522"*(H//7)),sep="\n")
        elif H%7==5:
            print("Yes")
            print(*("55555"+"2255555"*(H//7)),sep="\n")
        else:
            print("No")
        return
    if (H,W)==(3,3):
        print("Yes")
        print("225\n555\n225")
        return
    if H==2:
        block_up = "2555255"
        block_down = "2552555"

        if W%7==0:
            print("Yes")
            print(block_up*(W//7))
            print(block_down*(W//7))
        elif W%7==1:
            print("Yes")
            print(block_up*(W//7)+"2")
            print(block_down*(W//7)+"2")
        elif W%7==6:
            print("Yes")
            print(block_up[1:] + block_up*(W//7))
            print(block_down[1:] + block_down*(W//7))
        else:
            print("No")
        return
    if W==2:
        block_up = "2555255"
        block_down = "2552555"

        if H%7==0:
            print("Yes")
            ans1 = (block_up*(H//7))
            ans2 = (block_down*(H//7))
        elif H%7==1:
            print("Yes")
            ans1 = (block_up*(H//7)+"2")
            ans2 = (block_down*(H//7)+"2")
        elif H%7==6:
            print("Yes")
            ans1 = (block_up[1:] + block_up*(H//7))
            ans2 = (block_down[1:] + block_down*(H//7))
        else:
            print("No")
            return
        for a,b in zip(ans1,ans2):
            print(a+b)
        return
    print("No")
if __name__ == '__main__':
    main()