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
def get_hash(S):
    return sum([ord(s)+1-ord("a") for s in S])
def get_S(hash_):
    res1 = ""
    res2 = ""
    X=hash_
    while X:
        sub = min(26, X)
        res1 += chr(sub + ord("a") - 1)
        X-=sub
    if(len(res1) == 20):
        res2 = chr(ord(res1[0])-1) + res1[1:-1] + chr(ord(res1[-1]) + 1)
    else:
        res2 = chr(ord(res1[0])-1) + res1[1:] + "a"

    return (res1,res2)
def main():
    S=ST()
    if(S=="a" or S=="z"*20):
        print("NO")
        return
    hash_ = get_hash(S)
    T,U = get_S(hash_)
    if(S!=T):
        print(T)
    else:
        print(U)
if __name__ == '__main__':
    main()