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
    K=I()
    T=S*2
    before = ""
    RLE = []
    for t in T:
        if before != t:
            RLE.append(1)
            before = t
        else:
            RLE[-1]+=1
    cnt=0
    for x in RLE:
        cnt+=x//2
    if len(RLE)==1:
        print(cnt*K//2)
        exit()
    RLE = []
    before = ""
    for t in S:
        if before != t:
            RLE.append(1)
            before = t
        else:
            RLE[-1]+=1

    cnt2 = 0    
    for x in RLE:
        cnt2+=x//2

    cnt3 = cnt - cnt2*2

    ans=cnt2*K + cnt3*(K-1)
    print(ans)
    

if __name__ == '__main__':
    main()