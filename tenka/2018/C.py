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
from math import floor,ceil,sqrt,factorial,hypot,log #log2ないｙｐ
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
    N=I()
    A=LIN(N)
    
    def solve(odd):
        s1 = sorted(A)
        s2 = sorted(A,reverse=True)


        if odd:
            s1,s2 = s2,s1
        
        q = deque([s1.pop()])

        sign = False
        for i in range(N):
            if sign:
                v = s1.pop()
            else:
                v = s2.pop()
            q.appendleft(v)

            if len(s1)+len(s2)<=N:
                break
            
            if sign:
                v = s1.pop()
            else:
                v = s2.pop()
            q.append(v)
            
            if len(s1)+len(s2)<=N:
                break
            sign ^= 1

        res = 0
        before = q[0]
        for a in q:
            res += abs(before-a)
            before = a

        return res 

    print(max(solve(1),solve(0)))
if __name__ == '__main__':
    main()