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

# 約数列挙
def find_divisor(n):
    divisors=[]
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            divisors.append(i)
            if i*i!=n:
                divisors.append(n // i)
    return divisors


# 素因数分解
def prime_factorization(n):
    fact=[]
    for i in range(2, int(sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            fact.append(i)
    if n!=1:
        fact.append(n)
    return fact

def solve(n):
    res = 0
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            res += i
            if i*i!=n:
                res += n//i
    return res


def main():
    N = I()
    res = solve(N) - N
    if( res < N):
        print("Deficient")
    elif( res > N):
        print("Abundant")
    else:
        print("Perfect")
if __name__ == '__main__':
    main()