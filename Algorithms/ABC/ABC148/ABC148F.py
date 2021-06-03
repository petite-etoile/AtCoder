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
    N,tk,ao = MI()
    tk-=1
    ao-=1

    AB=LLIN_(N-1)
    edge = [[]for _ in range(N)]
    for a,b in AB:
        edge[a].append(b)
        edge[b].append(a)
    
    dist_from_tk = [-inf]*N
    dist_from_ao = [-inf]*N
    
    dist_from_ao[ao]=0
    q = deque([ao])
    while q:
        fr = q.popleft()
        for to in edge[fr]:
            if dist_from_ao[to]!=-inf:
                continue
            # print(fr,to,dist_from_ao)
            dist_from_ao[to]=dist_from_ao[fr]+1
            q.append(to)
    # print(dist_from_ao)

    dist_from_tk[tk]=0
    q = deque([tk])
    mid = -inf
    add_flag=0
    while q:
        fr = q.popleft()
        for to in edge[fr]:
            if dist_from_tk[to]!=-inf:
                continue
            if dist_from_ao[to]<=dist_from_tk[fr]+1:
                mid = fr
                if(dist_from_ao[to]==dist_from_tk[fr]+1):
                    add_flag=1
                continue
            # print(fr,to,dist_from_tk)
            dist_from_tk[to]=dist_from_tk[fr]+1
            q.append(to)
    # print("#########")
    # print(dist_from_ao)
    # print(dist_from_tk)
    # print(mid)


    dist_from_mid = [-inf]*N
    dist_from_mid[mid]=0
    q = deque([mid])
    while q:
        fr = q.popleft()
        for to in edge[fr]:
            if dist_from_mid[to]!=-inf:
                continue
            if dist_from_tk[to]==-inf:#到達不可
                continue
            # print(fr,to,dist_from_mid)
            dist_from_mid[to]=dist_from_mid[fr]+1
            q.append(to)
    # print(dist_from_mid)
    
    if dist_from_ao[tk]==1 and max(dist_from_tk)==0: ##自滅
        print(0)
    elif max(dist_from_tk)==0: ##動いたらすぐ死ぬ
        print(1)
    else:
        ans = dist_from_tk[mid]+max(dist_from_mid)
        print(ans+add_flag)
    # print(dist_from_tk[mid],max(dist_from_mid))

if __name__ == '__main__':
    main()