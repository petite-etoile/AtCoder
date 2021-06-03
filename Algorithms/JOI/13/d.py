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
    def members(s):
        if s == "J":
            return ("J", "JO", "JI", "JOI")
        elif s == "O":
            return ("O", "JO", "OI", "JOI")
        else:
            return ("I", "OI", "JI", "JOI")
            
    def common_exist(sa, sb):
        for s in sa:
            if s in sb:
                return True
        return False
    

    N = I()
    S=ST()
    dp = [defaultdict(int) for _ in range(N)]  #j,jo,ji,joi,o,oi,i
    all_patern = ("J", "O", "I", "JO", "JI", "OI", "JOI")
    for m in members(S[0]):
        if "J" in m:
            dp[0][m] = 1
    for i,s in enumerate(S[1:],start = 1):
        mem = members(s)
        for m1 in mem:
            for pre_mem in all_patern:
                if not common_exist(m1, pre_mem):
                    continue
                dp[i][m1] += dp[i - 1][pre_mem]
    ans = 0
    mod = 10007
    for key, val in dp[-1].items():
        ans += val
        ans%=mod
    print(ans%mod)

if __name__ == '__main__':
    main()