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
    Q,L=MI()
    size = 0
    stack = []
    push, pop = stack.append, stack.pop
    for _ in range(Q):
        S=ST()
        if "Push" in S:
            _, n, x = S.split()
            size += int(n)
            push( (int(n),int(x)) )
            if(size > L):
                print("FULL")
                return
        elif S == "Top":
            if(stack):
                print(stack[-1][1])
            else:
                print("EMPTY")
                return
        elif "Pop" in S:
            _,n = S.split()
            n = int(n)
            size-=n
            if(size<0):
                print("EMPTY")
                return
            while(n):
                m,x = pop()
                sub = min(m,n)
                n-=sub
                m-=sub
                if(m):
                    push((m,x))
        else: #Size
            print(size)
        # print(S, stack)
    print("SAFE")

if __name__ == '__main__':
    main()