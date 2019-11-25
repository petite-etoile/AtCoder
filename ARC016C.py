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
    N, M = MI()
    card_of_kuji = [[]for _ in range(M)]
    kuji_expense = [0]*M
    for i in range(M):
        C,cost = MI()
        kuji_expense[i] = cost
        for _ in range(C):
            idol,p = MI()
            idol = 1<<(idol-1)
            p /= 100
            card_of_kuji[i].append((idol,p))

    bit_max = 2**N
    dp = [inf]*bit_max
    dp[0] = 0
    #bit_setで立っているbitがまだもってないアイドル
    for bit_set in range(1,bit_max):
        #最適のくじを見つける
        for kuji in range(M):
            cost = 0
            get_want_percent = 0
            want = []
            for idol,p in card_of_kuji[kuji]:
                if idol&bit_set:#ほしい(もってない)アイドルを引いた
                    get_want_percent += p
                    want.append((idol,p))
            if not get_want_percent:
                cost = inf
            else:
                cost = kuji_expense[kuji]/get_want_percent #引く回数期待値
            
            for idol,p in want:
                after_state = bit_set-idol
                cost += dp[after_state]*p / get_want_percent
            dp[bit_set] = min(dp[bit_set], cost)
    #for i,x in enumerate(dp):
    #    print(bin(i)[2:], x)
    print(dp[-1])   
            
if __name__ == '__main__':
    main()