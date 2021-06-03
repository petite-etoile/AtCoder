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
    N,M=MI()
    AB=LLIN_(M)
    matrix = [[0]*N for _ in range(N)]

    def dfs(matrix):
        stack = [0]
        visited = set([0])
        while stack:
            u = stack.pop()
            for i,v in enumerate(matrix[u]):
                if v and i not in visited:
                    stack.append(i)
                    visited.add(i)
        return len(visited)!=len(matrix) #非連結になった
    
    for i,(a,b) in enumerate(AB):
        matrix[a][b] = 1
        matrix[b][a] = 1
    ans = 0
    for i,(a,b) in enumerate(AB):
        matrix[a][b] = 0
        matrix[b][a] = 0
        ans += dfs(matrix)
        matrix[a][b] = 1
        matrix[b][a] = 1
    print(ans)
if __name__ == '__main__':
    main()