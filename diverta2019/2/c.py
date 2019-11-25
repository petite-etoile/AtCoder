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
    minus = []
    plus = []
    M = I()
    A = LI()
    zero = []
    ans = []
    for a in A:
        if a < 0:
            minus.append(a)
        elif a > 0:
            plus.append(a)
        else:
            zero.append(0)
    minus.sort()
    plus.sort(reverse = True)
    if not minus:
        #print(minus,plus,zero)
        if zero and plus:
            a = zero.pop()
            b = plus.pop()
            minus.append(a-b)
            ans.append("{} {}".format(a, b))
        elif len(plus) >= 2:
            a = plus.pop()
            b = plus.pop()
            minus.append(a-b)
            ans.append("{} {}".format(a, b))
        
    if not plus:
        if zero and minus:
            a = zero.pop()
            b = minus.pop()
            plus.append(a-b)
            ans.append("{} {}".format(a, b))
        elif len(minus):
            a = minus.pop()
            b = minus.pop()
            plus.append(a-b)
            ans.append("{} {}".format(a, b))
        


    while minus and plus:
        if len(minus) == len(plus) == 1:
            a = plus.pop()
            b = minus.pop()
            ans.append("{} {}".format(a,b))
            plus.append(a - b)
            break
        a = minus.pop()
        b = plus.pop()
        if len(minus) > len(plus):
            ans.append("{} {}".format(b,a))
            plus.append(b-a)
        else:
            ans.append("{} {}".format(a,b))
            minus.append(a - b)

    while zero:
        if minus:
            a = zero.pop()
            b = minus.pop()
            #print(a, b)
        elif plus:
            a = plus.pop()
            b = zero.pop()
            #print(a, b)
        elif len(zero) >= 2:
            a = zero.pop()
            b = zero.pop()
            #print(a,b)
        else:
            break
        plus.append(a - b)
        ans.append("{} {}".format(a,b))

    if zero:
        print(*zero)
    elif minus:
        print(*minus)
    else:
        print(*plus)
    print(*ans,sep="\n")

if __name__ == '__main__':
    main()
