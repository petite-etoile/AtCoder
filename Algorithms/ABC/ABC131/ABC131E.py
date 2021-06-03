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
from math import floor,ceil,sqrt,factorial,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
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
    N, K = MI()
    pair = ((N * (N - 1)) // 2)
    ans = []
    cnt = 0
    frag = False
    if ((N - 1) * (N - 2))//2 < K:
        print(-1)
        exit()
    else:
        for i in range(1, N):
            start = 0
            ans.append((start, i))
            cnt = (i * (i - 1)) // 2
    if cnt == K:
        print(len(ans))
        for (s, t) in ans:
            print(s+1, t+1)
    if cnt != K:
        for i in range(1, N):
            for j in range(i+1, N):
                ans.append((i, j))
                cnt -= 1
                if cnt == K:
                    print(len(ans))
                    for (s, t) in ans:
                        print(s+1, t+1)
            
if __name__ == '__main__':
    main()