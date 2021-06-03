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
    N = I()
    S = ST()
    T = ST()
    contin = False
    equal = False
    if S[0] == T[0]:
        ans = 3
        equal = True
    else:
        ans = 6
        contin = False
    start = 1 + (S[0] != T[0])
    for s, t in zip(S[start:], T[start:]):
        if s == t:
            if equal:
                ans *= 2
            else:
                pass
            equal = True
        else:
            if contin:
                if equal:
                    ans *= 2
                else:
                    ans *= 3
                contin = False
                equal = False
            else:
                contin = True
        ans %= mod
        
    print(ans)
if __name__ == '__main__':
    main()