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
    N=I()
    Q=I()
    # A=[[inf]*N for _ in range(N)]
    # for i in range(N):
    #     for j in range(N):
    #         A[i][j] = i*N+j
    col_idx = [i for i in range(N)] # col_idx[c] = c列目がもともとどの列に居たのか
    # col_enc = [i for i in range(N)] # 
    row_idx = [i for i in range(N)] # row_idx[r] = r行目がもともとどの行に居たのか

    transpose = False
    def col_rev(a,b):
        col_idx[a],col_idx[b] = col_idx[b], col_idx[a]

    def row_rev(a,b):
        row_idx[a],row_idx[b] = row_idx[b], row_idx[a]

    #転置しているときの変換
    def enc(a,b):
        return N-a-1, N-b-1

    for _ in range(Q):
        S=ST()
        if(S[0] == "1"):
            _,a,b = S.split()
            a,b=int(a)-1,int(b)-1   
            if(transpose):
                # a,b = enc(a,b)
                col_rev(a,b)
            else:
                row_rev(a,b)

        elif(S[0] == "2"):
            _,a,b = S.split()
            a,b=int(a)-1,int(b)-1
            if(transpose):
                # a,b = enc(a,b)
                row_rev(a,b)
            else:
                col_rev(a,b)
        elif(S[0] == "3"):
            transpose ^= True
        else:
            _,a,b = S.split()
            a,b=int(a)-1,int(b)-1
            if(transpose):
                a,b = b,a
            # print(transpose,a,b)
            r,c = row_idx[a], col_idx[b]
            print(row_idx[a] * N + col_idx[b])

if __name__ == '__main__':
    main()