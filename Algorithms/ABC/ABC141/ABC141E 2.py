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
    N = I()
    S = ST()
    
    def z_algorithm(S):
        N = len(S)
        A = [N] + [0] * (N-1)
        left = 1
        length = 0
        while left < N:
            while left+length<N and S[length] == S[left+length]:
                length += 1
            A[left] = length
            if not length:
                left += 1
                continue
            k = 1
            while k+left<N and k+A[k]<length:
                A[left+k] = A[k]
                k += 1
            
            left += k
            length -= k

        return A

    ans = 0
    for i in range(N):
        A = z_algorithm(S[i:])
        for i,a in enumerate(A):
            ans = max(ans, min(a,i))
    print(ans)
    


    """
    # めぐる式二分探索
    def meguru_bisect(ok, ng):
        while abs(ok - ng) > 1:
            mid=(ok + ng) // 2
            if is_ok(mid):
                ok=mid
            else:
                ng=mid
        return ok

    def is_ok(l):
        for i,s in enumerate(S[:-l + 1]):
            st = S[i:i+l]
            if st in S[i+l:]:
                return True
        return False

    ans = meguru_bisect(0,len(S))
    print(ans)
    """


if __name__ == '__main__':
    main()