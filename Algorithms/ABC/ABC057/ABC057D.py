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
from heapq import heappop, heappush, heappushpop
from collections import Counter, defaultdict
from operator import itemgetter, attrgetter
inf=float('inf')
mod = 10 ** 9 + 7
def combination(n, r):  # n個からr個選ぶ場合の数
    if n < r:
        return 0
    else:
        return factorial(n)//(factorial(r) * factorial(n-r))


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
    N, A, B = MI()
    V = LI()
    v_dict = defaultdict(int)
    for v in V:
        v_dict[v] += 1
    VN = [(v, num) for v, num in v_dict.items()]
    VN.sort(reverse=True)
    A_copy = A
    ans_1 = 0
    for (v, n) in VN:
        if A_copy > n:
            A_copy -= n
            ans_1 += v*n
        else:
            ans_1 += A_copy * v
            break
    print(ans_1/A)
            
    if VN[0][1] > A:
        ans_2 = 0
        for choose_num in range(A, min(B, VN[0][1]) + 1):
            ans_2 += combination(n, choose_num)
        print(ans_2)
    else:
        for (v, n) in VN:
            if A > n:
                A -= n
            else:
                ans_2 = combination(n, A)
                break
        print(ans_2)

if __name__ == '__main__':
    main()