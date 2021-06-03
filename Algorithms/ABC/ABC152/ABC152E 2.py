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
from fractions import gcd
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
#mint
class ModInt:
    def __init__(self, x):
        self.x = x % mod
    
    def __str__(self):
        return str(self.x)
    
    __repr__ = __str__

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x + other.x)
        else:
            return ModInt(self.x + other)

    __radd__ = __add__
        
    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x - other.x)
        else:
            return ModInt(self.x - other)

    def __rsub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(other.x - self.x)
        else:
            return ModInt(other - self.x)

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * other.x)
        else:
            return ModInt(self.x * other)

    __rmul__ = __mul__

    def __truediv__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.x * pow(other.x, mod-2,mod))
        else:
            return ModInt(self.x * pow(other, mod - 2, mod))
            
    def __rtruediv(self, other):
        if isinstance(other, self):
            return ModInt(other * pow(self.x, mod - 2, mod))
        else:
            return ModInt(other.x * pow(self.x, mod - 2, mod))
            

    def __pow__(self, other):
        if isinstance(other, ModInt):
            return ModInt(pow(self.x, other.x, mod))
        else:
            return ModInt(pow(self.x, other, mod))
            

    def __rpow__(self, other):
        if isinstance(other, ModInt):
            return ModInt(pow(other.x, self.x, mod))
        else:
            return ModInt(pow(other, self.x, mod))


# 素因数分解
def prime_factorization(n):
    fact=[]
    fact=defaultdict(int)
    for i in range(2, int(sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            # fact.append(i)
            fact[i]+=1
            # print(n,i)
    if n!=1:
        fact[n]+=1
    return fact

class Eratosthenes:
    def __init__(self, N:int):
        self.data = [-1]*(N+1) ##data[i]:=iの素因数が一つ入ってるリスト
        for i in range(2,int(sqrt(N)+1)):
            if self.data[i]!=-1:
                continue
            j = 2*i
            while j<=N:
                self.data[j] = i
                j += i

    def prime_factorization(self,n):
        res = defaultdict(int)
        while self.data[n] != -1:
            prime = self.data[n]
            res[prime] += 1
            n //= prime
        if n!=1:
            res[n] += 1
        return res

def main():
    N=I()
    A=LI()
    A_max = max(A)
    Eratos = Eratosthenes(A_max)

    lcm = defaultdict(int)
    for a in A:
        p = Eratos.prime_factorization(a)
        for k in p.keys():
            lcm[k] = max(p[k],lcm[k])
    
    L = ModInt(1)
    for l,v in lcm.items():
        L *= l**v
    ans = ModInt(0)
    for a in A:
        ans += L/a
    print(ans)
    
if __name__ == '__main__':
    main()

# #
# # 　　  ⋀_⋀　 
# #　　  (･ω･)  
# # .／ Ｕ ∽ Ｕ＼
# #  │＊　合　＊│
# #  │＊　格　＊│ 
# #  │＊　祈　＊│ 
# #  │＊　願　＊│ 
# #  │＊　　　＊│ 
# #      ￣
# #
# import sys
# sys.setrecursionlimit(10**6)
# input=sys.stdin.readline
# # from math import floor,ceil,sqrt,factorial,hypot,log #log2ないｙｐ
# # from heapq import heappop, heappush, heappushpop
# # from collections import Counter,defaultdict,deque
# # from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
# # from bisect import bisect_left,bisect_right
# # from copy import deepcopy
# from fractions import gcd
# inf=float('inf')
# mod = 10**9+7
# def pprint(*A): 
#     for a in A:     print(*a,sep='\n')
# def INT_(n): return int(n)-1
# def MI(): return map(int,input().split())
# def MF(): return map(float, input().split())
# def MI_(): return map(INT_,input().split())
# def LI(): return list(MI())
# def LI_(): return [int(x) - 1 for x in input().split()]
# def LF(): return list(MF())
# def LIN(n:int): return [I() for _ in range(n)]
# def LLIN(n: int): return [LI() for _ in range(n)]
# def LLIN_(n: int): return [LI_() for _ in range(n)]
# def LLI(): return [list(map(int, l.split() )) for l in input()]
# def I(): return int(input())
# def F(): return float(input())
# def ST(): return input().replace('\n', '')
# #mint
# class ModInt:
#     def __init__(self, x):
#         self.x = x % mod
    
#     def __str__(self):
#         return str(self.x)
    
#     __repr__ = __str__

#     def __add__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(self.x + other.x)
#         else:
#             return ModInt(self.x + other)

#     __radd__ = __add__
        
#     def __sub__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(self.x - other.x)
#         else:
#             return ModInt(self.x - other)

#     def __rsub__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(other.x - self.x)
#         else:
#             return ModInt(other - self.x)

#     def __mul__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(self.x * other.x)
#         else:
#             return ModInt(self.x * other)

#     __rmul__ = __mul__

#     def __truediv__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(self.x * pow(other.x, mod-2,mod))
#         else:
#             return ModInt(self.x * pow(other, mod - 2, mod))
            
#     def __rtruediv(self, other):
#         if isinstance(other, self):
#             return ModInt(other * pow(self.x, mod - 2, mod))
#         else:
#             return ModInt(other.x * pow(self.x, mod - 2, mod))
            

#     def __pow__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(pow(self.x, other.x, mod))
#         else:
#             return ModInt(pow(self.x, other, mod))
            

#     def __rpow__(self, other):
#         if isinstance(other, ModInt):
#             return ModInt(pow(other.x, self.x, mod))
#         else:
#             return ModInt(pow(other, self.x, mod))

# def main():
#     N=I()
#     A=LI()
#     l = 1
#     for a in A:
#         l *= a//gcd(l,a)
#     ans = 0
#     l = ModInt(l)
#     for a in A:
#         ans += l/a
#     print(ans)
# if __name__ == '__main__':
#     main()