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
inf=float('inf')
mod = 10**9+7
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [input() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    from math import sqrt
    N = I()
    AB = LLIN(N)
    divisors = set()
    a, b = AB[0]
    for i in range(1,int(sqrt(a)) + 1):
        if a%i==0:
            divisors.add(i)
            if i * i != a:
                divisors.add(a // i)
    
    for i in range(1,int(sqrt(b)) + 1):
        if b%i==0:
            divisors.add(i)
            if i * i != b:
                divisors.add(b // i)
            
    divisors = sorted(list(divisors), reverse=True)
    for d in divisors:
        frag=False
        for (a, b) in AB[1:]:
            if a % d == 0 or b % d == 0:
                continue
            else:
                frag = True
                break
        if not frag:
            print(d)
            exit()
    



if __name__ == '__main__':
    main()