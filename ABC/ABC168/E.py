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
from math import floor,sqrt,factorial,hypot,log,gcd #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
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



def main():
    N=I()
    A,B=[],[]
    for i in range(N):
        a,b = MI()
        A.append(a)
        B.append(b)
    both_zero_cnt = 0
    num_of_group = defaultdict(int) ##既約分数にしてあげて、(分子,分母)がkeyで、負なら分子が負になる他は正
    for i in range(N):
        a,b = A[i], B[i]
        if(a==b==0):
            both_zero_cnt+=1
            continue
        elif(a==0):
            num_of_group[-inf,inf] += 1
            num_of_group[inf,inf] += 0

        elif(b==0):
            num_of_group[inf,inf] += 1
        else:
            if(a*b<0):
                a,b=abs(a),abs(b)
                g = gcd(a,b)
                a//=g
                b//=g
                num_of_group[(-b,a)] += 1
                num_of_group[(b,a)] += 0
            else:
                a,b=abs(a),abs(b)
                g = gcd(a,b)
                a//=g
                b//=g
                num_of_group[(a,b)] += 1
    # print(num_of_group.items())
    if(both_zero_cnt==N):
        print(N)
        return
    ##solve
    ans = ModInt(1)
    two_pow = [1]
    for i in range(N):
        two_pow.append((2*two_pow[-1])%mod)
    # print(two_pow,"#######")
    for (a,b),cnt1 in num_of_group.items():
        if(a<0):
            continue
        tmp = two_pow[cnt1]

        if (-a,b) in num_of_group:
            cnt2 = num_of_group[-a,b]
            tmp += two_pow[cnt2]
            tmp-=1
        if(tmp):
            ans *= tmp
    ans -= 1 ##全部選ばない
    ans += both_zero_cnt
    print(ans)
if __name__ == '__main__':
    main()
