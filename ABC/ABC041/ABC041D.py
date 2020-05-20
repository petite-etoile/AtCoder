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
    #bitDP
    N,M = MI()
    faster_rabbit = [0]*N
    for _ in range(M):
        x,y = MI_()
        faster_rabbit[y] += 1 << x

    max_bit = 2**N
    dp=[0]*max_bit
    dp[0] = 1
    for bit_set in range(max_bit):
        for rabbit_num in range(N):
            rabbit_bit = 1 << rabbit_num
            if rabbit_bit & bit_set:
                others = bit_set - rabbit_bit
                if faster_rabbit[rabbit_num] == faster_rabbit[rabbit_num]&others:
                    dp[bit_set] += dp[bit_set - rabbit_bit]
    print(dp[-1])


if __name__ == '__main__':
    main()

"""N, M = map(int, input().split())
# fast_rabbit[i]:i匹目のうさぎより速いうさぎたち ex)fast_rabbit[i]=11010 → i番目のうさぎより速いのは1,2,4番目のうさぎ
fast_rabbit = [0]*N
for i in range(M):
    x, y = map(int, input().split())
    fast_rabbit[y-1] += 1 << (x-1)

bit_max = 1 << N
# print(bit_max)
dp = [0] * bit_max
dp[0] = 1  # 空集合の数(もちろん{}のみなので1)
for bit_set in range(bit_max):
    for rabbit_num in range(N):
        rabbit_bit = 1 << rabbit_num

        # bitsetにrabbit_bitがない=bitsetのうさぎたちの中にrabbit_num匹目のうさぎはいないので無視
        if bit_set & rabbit_bit:
            others = bit_set - rabbit_bit

            # rabbit_num匹目のうさぎより早くゴールしたうさぎたちが全員"rabbit_num匹目のうさぎ以外のbitset"のうさぎたちの中にいないならありえないので無視
            if fast_rabbit[rabbit_num] & others == fast_rabbit[rabbit_num]:
                # dp[bitset-rabbitbit]:bitsetの組み合わせからrabbit_num匹目のうさぎを除いたやつらの並び方の数
                dp[bit_set] += dp[bit_set - rabbit_bit]
print(dp[bit_max-1])
"""