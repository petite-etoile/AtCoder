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
    global X,Y,now_X,now_Y
    K=I()
    X,Y=MI()
    ans = []
    now_X=0
    now_Y=0
    
    def move_greedy():
        global X,Y,now_X,now_Y
        move = min(K,abs(now_X-X))
        if(X-now_X<0):
            now_X -= move
        else:
            now_X += move
        if(Y-now_Y<0):
            now_Y -= K-move
        else:
            now_Y += K-move
        ans.append((now_X,now_Y))
    
    def move_last():
        global X,Y,now_X,now_Y
        distance = abs(X-now_X) + abs(Y-now_Y)
        move = (2*K-distance)//2 #あまりの半分
        if(abs(X-now_X) < abs(Y-now_Y)):
            if(X-now_X<0):
                now_X += move
            else:
                now_X -= move
            if(Y-now_Y<0):
                now_Y -= K - move
            else:
                now_Y += K - move
        else:
            if(Y-now_Y<0):
                now_Y += move
            else:
                now_Y -= move
            if(X-now_X<0):
                now_X -= K - move
            else:
                now_X += K - move
        ans.append((now_X,now_Y))
        ans.append((X,Y))
    
    
    if (abs(X) + abs(Y)) % 2 == 1 and K %2 == 0:
        print(-1)
        return
    while abs(now_X-X) + abs(now_Y-Y) > 2*K:
        move_greedy()

    if(K%2==0):
        move_last()
    else:
        if(abs(X-now_X) + abs(Y-now_Y) == K):
            ans.append((X,Y))
        else:
            distance = abs(X-now_X) + abs(Y-now_Y)
            if(distance&1):
                move_greedy()
            move_last()
            
    print(len(ans))
    for a in ans:
        print(*a)


    
if __name__ == '__main__':
    main()