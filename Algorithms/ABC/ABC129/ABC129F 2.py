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
from collections import Counter,defaultdict
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
inf=float('inf')
#mod = 10 ** 9 + 7
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

def main():
    global mod
    #二分法を使って高速に求める
    def f(N):
        ret = ModInt(0)
        if N == 0:
            return ret
        elif N % 2 == 1:
            ret = (f(N - 1) * pow(ModInt(10), k)) + 1
            return ret
            #return ((f(N - 1)%mod * pow(10 , k,mod)) %mod + 1)%mod
        else:
            x = f(N // 2)
            ret = (x * pow(ModInt(10), k * (N // 2))) + x
            #print("ret",N)
            return ret 
            #return ((x * pow(10 , k * (N//2) ,mod)) %mod + x)%mod
        
    
    def g(N):
        ret = ModInt(0)
        if N == 0:
            return ret
        elif N % 2 == 1:
            ret = g(N - 1) * pow(ModInt(10), k) + (N - 1) * B
            return ret
            #return ((g(N - 1) * pow(10 , k,mod))%mod + ((N-1) * B)%mod) %mod
        else:
            x = g(N // 2)
            ret = x * pow(ModInt(10), k * (N // 2)) + x + ((N // 2) * B * f(N // 2))
            return ret
            #return ((x * pow(10 , k * (N//2),mod))%mod + x + ((N//2) * B * f(N//2))%mod  )%mod
            



    L, A, B, mod = MI()
    first = A
    last = A + (L - 1) * B
    ans=ModInt(0)
    for k in range(1, 19):
        print(10 ** (k - 1) , 10 ** k - 1)
        if (last < 10 ** (k - 1) or 10 ** k - 1 < first):
            continue
        #k桁の整数のgroupにおける、初項Ag
        if first >= 10 ** (k - 1):
            Ag = first
        else:
            Ag = ceil((10 ** (k - 1) - A) / B) * B + A
        #print("初項",Ag)

        #groupの要素数
        if last <= 10**k -1:
            Lastg = last
            N = (Lastg-Ag)//B + 1
        else:
            N = (((10 ** k) - 1 - Ag) // B) + 1
            
        #N*k桁ずらす
        #print(pow(10, N * k, mod))
        ans *= pow(10, N * k, mod)
        #print("         " ,ans)
        #このグループにおける値の計算
        ans += Ag * f(N)
        ans += g(N)
    print(ans)
    
if __name__ == '__main__':
    main()