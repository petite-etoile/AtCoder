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
    def solve_percent_cc(pre_p, pre_c, now_p, now_c):
        ret = now_p + (pre_p-now_p)*(pre_c/(now_c+pre_c))
        return now_p + (pre_p-now_p)*(pre_c/(now_c+pre_c))
    N, K = MI()
    WP = LLIN(N)
    WP.sort(reverse = True,key = lambda x:x[1])
    ans_set = set([tuple(WP[0])])
    now_node = WP[0][1]
    now_cc = WP[0][0]
    
    for i in range(K-1):
        new_luquid = WP[WP.index(max(WP, key=lambda x: solve_percent_cc(x[1], x[0], now_node, now_cc) if tuple(x) not in ans_set else - inf))]
        now_node = solve_percent_cc(new_luquid[1], new_luquid[0], now_node, now_cc)
        now_cc += new_luquid[0]
        ans_set.add(tuple(new_luquid))
    print(now_node)
if __name__ == '__main__':
    main()