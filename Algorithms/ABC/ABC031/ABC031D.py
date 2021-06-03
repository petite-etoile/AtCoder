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
from fractions import gcd
from random import randint
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
    K,N= MI ()
    VW = [ST().split() for _ in range(N)]

    ## その長さで語呂合わせが整合性を満たしているか判断 O(N* ( K+len(w_i) ) )
    def is_ok(pattern):
        S = [""]*K
        for v,w in VW:
            now = 0
            for i in v:
                i = int(i)-1 
                length = pattern[i] 
                s = w[now:now+length]
                now += length

                if now > len(w):
                    return False
                
                if S[i]=="":
                    S[i] = s
                elif S[i] != s:
                    return False

            if len(w)!=now:
                return False

        print(*S,sep="\n")
        exit()
        return True

    ## それぞれの文字の長さで全探索 O(3^K)
    def dfs(i,pattern):
        if i==K:
            if is_ok(pattern):
                return True
            else:
                return False
        for j in range(1,4):
            pattern[i] = j
            if dfs(i+1,pattern):
                return True
        return False
    
    pattern = [0]*K
    dfs(0,pattern)


if __name__ == '__main__':
    main()