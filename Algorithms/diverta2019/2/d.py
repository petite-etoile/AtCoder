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
    N = I()
    g, s, b = MI()
    G, S, B = MI()
    x,y,z = G - g, S - s, B - b    
    X,Y,Z = -x,-y,-z
    
    ans = 0
    for i in range(N//g+1):
        for j in range(N // s+1):
            if g * i + s * j > N:
                break
            k =( N - (g * i + s * j))//b
            if z < 0:
                ans =max(ans,i * x + j * y)
            else:
                ans = max(ans, i * x + j * y + k * z)
    for i in range(N//G+1):
        for j in range(N // S+1):
            if G * i + S * j > N:
                break
            k = (N-(G * i + S * j))//B
            if Z < 0:
                ans = max(ans,i * X + j * Y)
            else:
                ans = max(ans, i * X + j * Y + k * Z)
    print(ans+N)
if __name__ == '__main__':
    main()