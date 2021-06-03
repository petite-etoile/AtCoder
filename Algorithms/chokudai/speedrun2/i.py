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
    from math import ceil

    N = I()
    AB = LLIN(N)
    if N == 1:
        print(1)
        exit()

    #かち0 else 1
    def AwinB(AHP, APOWER, BHP, BPOWER):
        if ceil(AHP / BPOWER) > ceil(BHP / APOWER):
            return 0
        else:
            return 1
    #トーナメントをして優勝したやつに対して、ねえ兄ちゃん他のやつにもかてんの？？を試す
    winner = 0

    #優勝候補
    for i, (hp, attack) in enumerate(AB[1:],start=1):
        if AwinB(AB[winner][0], AB[winner][1], hp, attack) == 0:
            continue
        else:
            winner = i

    for i,(hp,attack) in enumerate(AB):
        if winner == i:
            continue
        if AwinB(AB[winner][0], AB[winner][1], hp, attack) != 0:
            print(-1)
            exit()
    print(winner+1)

if __name__ == '__main__':
    main()
