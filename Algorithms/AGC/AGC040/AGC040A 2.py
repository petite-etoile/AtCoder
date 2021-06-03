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
    S=ST()
    before = " "
    RLE = []
    string = []
    for s in S:
        if s==before:
            RLE[-1] += 1
        else:
            RLE.append(1)
            string.append(s)
        before = s
    # print(RLE)
    # print(string)

    A = [-1]*(len(S)+1) ##最後に0で初期化
    if string[0]=="<":
        A[0]=0
    now = 0
    for i,x in enumerate(RLE):
        s = string[i]
        now += x
        if s=="<":
            pass
        else: #>
            A[now] = 0
    i=0
    while i<(len(S)+1):
        if A[i]==0:
            j=i-1
            while j>=0:
                if S[j]==">":
                    A[j]=max(A[j],A[j+1]+1)
                    j-=1
                else:
                    break

            j=i
            while j<len(S):
                if S[j]=="<":
                    A[j+1]=max(A[j+1],A[j]+1)
                    j+=1
                else:
                    break
        i+=1


    # print(A)
    print(sum(A))

if __name__ == '__main__':
    main()