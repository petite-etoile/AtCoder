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
from math import floor,ceil,sqrt,factorial
from heapq import heappop, heappush, heappushpop,heapify
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
    def rev(n):
        return -n
    N = I()
    A = LI()
    left_sum = [sum(A[:N])]  #left_sum[k]:=N+k個取って、小さいN個を選んだときの合計値
    left = A[:N]
    heapify(left)
    right_sum = [sum(A[2 * N:])]
    right=list(map(rev,A[2*N:]))
    heapify(right)
    for k in range(1, N + 1):
        heappush(left, A[N - 1 + k])
        poped = heappop(left)
        left_sum.append(left_sum[-1] + A[N - 1 + k] - poped)

        heappush(right, -A[-N - k])
        poped = -heappop(right)
        right_sum.append(right_sum[-1] + A[-N - k] - poped)
    ans = -inf
    for k in range(N + 1):
        ans = max(ans, left_sum[k] - right_sum[-k - 1])
    print(ans)
if __name__ == '__main__':
    main()