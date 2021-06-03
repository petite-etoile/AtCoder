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
from math import floor,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
def ceil(a,b): return (a+b-1)//b
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
def solve():
    N,A,B,C,D = MI()
    ans = inf
    for x in range(0,60+1):
        now_x = 2**x
        if(now_x > N * 2):
            break
        for y in range(0,38+1):
            now_y = 3**y
            if(now_x * now_y > N * 3):
                break
            for z in range(0,26+1):
                now_z = 5**z
                    print()
                    print(x,y,z)
                # print(now_x,now_y,now_z)
                # print()
                if(now_x * now_y * now_z > N * 5):
                    break
                remain = now_x*now_y*now_z*ceil(N,now_x*now_y*now_z)
                res = (remain - N) * D # Nを超える分
                print("いくつになるか",remain)
                print("Nを超える分",(remain - N) * D)
                res += x*A + y*B + z*C #それぞれの乗算
                print("それぞれの乗算",x*A + y*B + z*C)
                remain //= now_x*now_y*now_z
                res += remain * D #最初に足す分
                print("最初に足す分",remain*D)
                print(x,y,z)
                print("切り上げ",ceil(N,now_x*now_y*now_z),"N",N)
                print("res",res)
                print(now_x*now_y*now_z*ceil(N,now_x*now_y*now_z), x*A + y*B + z*C, remain * D, res)
                ans = min(ans, res)


                remain = now_x * now_y * now_z
                res = abs(remain - N) * D
                res += x*A + y*B + z*C
                remain //= now_x*now_y*now_z
                res += remain * D
                ans = min(ans, res)
    print(ans)
def main():
    N=I()
    for i in range(N):
        solve()
if __name__ == '__main__':
    main()
"""
1
11 1 2 4 8
"""