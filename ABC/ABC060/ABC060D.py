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
input=sys.stdin.readline
from math import floor,ceil,sqrt,factorial
from heapq import heappop, heappush, heappushpop
from collections import Counter, defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
inf=float('inf')
mod = 10**9+7
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
    N, W = MI()
    items = [[] for _ in range(4)]
    w0, v0 = MI()
    items[0].append(v0)
    for _ in range(N-1):
        w, v = MI()
        items[w - w0].append(v)
    
    cumsum = [[0] + list(accumulate(sorted(items[i],reverse=True))) for i in range(4)]
    ans=0
    for i,c0 in enumerate(cumsum[0]):
        for j,c1 in enumerate(cumsum[1]):
            for k,c2 in enumerate(cumsum[2]):
                s = i * w0 + j * (w0 + 1) + k * (w0 + 2)
                if s <= W:
                    l = min(len(cumsum[3])-1,(W-s)//(w0+3))
                    ans = max(ans, c0 + c1 + c2 +cumsum[3][l])
    print(ans)
if __name__ == '__main__':
    main()