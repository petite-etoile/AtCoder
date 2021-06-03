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
    N=I()
    edge=[[]for _ in range(N)]
    for i in range(N):
        a=I()
        for _ in range(a):
            x,y = MI()
            edge[i].append((x-1,y))

    max_bit = 1<<N
    ans = 0
    for bit in range(max_bit):
        cnt = 0
        T = []
        people = [0]*N
        for i in range(N):
            if (1<<i)&bit:
                people[i]=True
                cnt += 1
                T.append(i)
            else:
                people[i]= 2
        ok = True
        visited = set()
        while T:
            u = T.pop()
            visited.add(u)
            for v,tf in edge[u]:
                if tf==1:
                    if people[v]==0:
                        ok = False
                        break
                    people[v] = True
                    if v not in visited:
                        T.append(v)
                        visited.add(v)
                else:
                    if people[v]==1:
                        ok=False
                        break
                    people[v] = False
        if ok:
            ans = max(ans,cnt)
    print(ans)


if __name__ == '__main__':
    main()