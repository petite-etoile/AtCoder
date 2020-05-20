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
from collections import Counter,defaultdict
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
    Value = []
    Weight=[]
    for _ in range(N):
        v, w = MI()
        Value.append(v)
        Weight.append(w)
    dp = [[0] * (W + 1) for _ in range(N)]
    dp[0] = [Value[0] if Weight[0]<=bag else 0 for bag in range(W+1)]
    for i in range(1,N):
        for bag in range(W + 1):
            dp[i][bag] = max(dp[i - 1][bag], dp[i - 1][max(0, bag - Weight[i])] + Value[i])
    print(dp[-1][-1])
            
            
if __name__ == '__main__':
    main()