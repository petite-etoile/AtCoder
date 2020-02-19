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
def main():
    N=I()
    D={
        "A":0, "G":1, "C":2, "T":3
    }

    DP=[[[[0]*4 for _ in range(4)] for _ in range(4)] for _ in range(N)] #DP[i][a][b][c] := i文字目までで、最後の文字ががabcな場合の数
    DP[1][3] = [[1]*4 for _ in range(4)] 
    for i in range(2,N):
        for a in range(4):
            for b in range(4):
                for c in range(4):
                    for s in range(4):
                        if s==0: #なんでもOK
                            pass
                        elif s==1: #ACGだとout
                            if (b,c)==(D["A"],D["C"]):
                                continue
                        elif s==2: #AGC,GAC,A?GC,AG?Cがout
                            if (b,c) in ((D["A"],D["G"]), (D["G"],D["A"])) or (a,c) == (D["A"], D["G"]) or (a,b) == (D["A"], D["G"]) :
                                continue
                        else: #なんでもOK
                            pass
                        DP[i][b][c][s] += DP[i-1][a][b][c]
                        DP[i][b][c][s] %= mod

    ans = 0
    for a in DP[-1]:
        ans += sum([sum(i) for i in a])
    print(ans%mod)
    """
    AGC
    ACG
    GAC
    A?GC
    AG?C

    """
if __name__ == '__main__':
    main()


# def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
#     if counts:
#         return [dp_table(*counts[1:]) for _ in range(counts[0])]
#     else:
#         return 0


# def ng(char1, char2, char3, new_char):
#     if char2 == 0 and char3 == 1 and new_char == 2:
#         return True
#     if char2 == 0 and char3 == 2 and new_char == 1:
#         return True
#     if char2 == 1 and char3 == 0 and new_char == 2:
#         return True
#     if char1 == 0 and char2 == 1 and new_char == 2:
#         return True
#     if char1 == 0 and char3 == 1 and new_char == 2:
#         return True
#     return False


# AGCT = ["A", "G", "C", "T"]
# # ng=[[0,1,2],[0,2,1],[1,0,2],[0,1,?,2],[0,?,1,2]]


# def main():
#     modulo = 10**9+7
#     N = int(input())
#     dp = dp_table(N+1, 4, 4, 4)
#     dp[0][3][3][3] = 1
#     for i in range(N):
#         for char_1 in range(4):
#             for char_2 in range(4):
#                 for char_3 in range(4):
#                     if dp[i][char_1][char_2][char_3] == 0:
#                         continue
#                     # (...char1,char2,char3)のあとにnewをつけた文字列が追加できるなら、
#                     # (...char1,char2,char3)のバリエーション分だけ(バリエーションがある
#                     for new in range(4):
#                         if ng(char_1, char_2, char_3, new):
#                             continue
#                         else:
#                             dp[i + 1][char_2][char_3][new] += dp[i][char_1][char_2][char_3]
#                     dp[i + 1][char_2][char_3][new] %= modulo
#     ans = 0
#     for char_1 in range(4):
#         for char_2 in range(4):
#             for char_3 in range(4):
#                 ans += dp[N][char_1][char_2][char_3]
#     # print(dp)
#     print(ans % modulo)


# if __name__ == '__main__':
#     main()

# """AGCT = ["A", "G", "C", "T"]


# def solve(dp, N: int, index: int = 0, AGC: bool = False, S: str = ""):
#     if N == index:
#         if AGC:
#             print(S)
#             return 1
#         else:
#             return 0
#     elif dp[index][AGC] is not None and AGC:
#         return dp[index][AGC]
#     if AGC:
#         print(index, S, pow(4, N-index))
#         return pow(4, N-index)
#     else:
#         for_max = 4
#         res = 0
#         for i in range(for_max):

#             if index == 1:
#                 AGC_ = False
#             else:
#                 AGC_ = ((S[index-2:] + AGCT[i]) in ["AGC", "ACG", "GAC"])
#                 if index >= 3 and not AGC_:
#                     AGC_ = ((S[index-3] + S[index-1] + AGCT[i] == "AGC")
#                             or ((S[index - 3] + S[index - 2] == "AG") and AGCT[i] == "C"))
#             #print(S, AGC, S+AGCT[i])
#             res += solve(dp, N, index + 1, AGC_, S + AGCT[i])
#         #print(res, S)
#         dp[index][AGC] = res
#         return res


# def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
#     if counts:
#         return [dp_table(*counts[1:]) for _ in range(counts[0])]
#     else:
#         return None


# N = int(input())
# four_pow_N = pow(4, N, 10 ** 9 + 7)
# dp = dp_table(102, 2)
# print(dp)
# ans = solve(dp, N)
# print(four_pow_N - ans)
# """
