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
    H,W,K=MI()
    N=I()
    cnt_h = [0]*H
    cnt_w = [0]*W
    posi = []
    for _ in range(N):
        h,w = MI_()
        cnt_h[h]+=1
        cnt_w[w]+=1
        posi.append((h,w))

    cnt_dict_h = defaultdict(int) #cnt_dict_h[x]:=x個飴がある行が何個あるか
    for cnt in cnt_h:
        cnt_dict_h[cnt]+=1
    cnt_dict_w = defaultdict(int)
    for cnt in cnt_w:
        cnt_dict_w[cnt]+=1
    
    ans = 0
    for cnt,k in cnt_dict_h.items():
        ans += k*cnt_dict_w[K-cnt]
    
    for h,w in posi:
        if cnt_h[h]+cnt_w[w]==K: #K-1個なのに数えてた
            ans-=1
        if cnt_h[h]+cnt_w[w]==K+1: #K個なのに数えてなかった
            ans+=1
    print(ans)





if __name__ == '__main__':
    main()