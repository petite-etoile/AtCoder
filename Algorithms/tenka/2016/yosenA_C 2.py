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
def chr_id(s):
    return ord(s)-ord("a")
def to_chr(s):
    return chr(ord("a") + s)
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
    N = I()
    edge = [[]for _ in range(26)]
    chrs = set()
    indegree = [0]*26
    for _ in range(N):
        A,B = ST().split()
        added = False
        for a,b in zip(A,B):
            if a!=b:
                edge[chr_id(a)].append(chr_id(b))
                added = True
                a = chr_id(a)
                b = chr_id(b)
                chrs.add(a)
                chrs.add(b)
                indegree[b] += 1
                break
        if not added:
            if A > B:
                print(-1)
                exit()
    
    topo_sort = []
    queue = []
    for s in chrs:
        if not indegree[s]:
            heappush(queue, s)
    
    while queue:
        s = heappop(queue)
        topo_sort.append(s)
        for v in edge[s]:
            indegree[v]-=1
            if not indegree[v]:
                heappush(queue, v)
        

    if len(topo_sort) != len(chrs):
        print(-1)
        exit()
    topo_sort = topo_sort[::-1]

    ans = []
    for i in range(26):
        #print(i)
        while topo_sort:
            if i>=topo_sort[-1]:
                s = topo_sort.pop()
                ans.append(to_chr(s))
            else:
                break
        if i not in chrs:
            ans.append(to_chr(i))
    print(*ans,sep="")

            

if __name__ == '__main__':
    main()