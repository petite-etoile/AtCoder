#
#　　　　　　　　　　　　　　,. -─────────‐- .、
#　　　　　　　　　　　　 ／／￣￣＼　　　　　　／￣￣＼＼
#　　　　　　　　　　　／　　　　　　　　　　　　　　　　　　　　 ＼
#　　　　　　　　　 ／　　　　　　　　::::::::::::::::::::::::::::::::　　　　　　　＼
#　　　　　　　　／ 　　／ ／￣＼＼::::;;;;;;;;;;;;;;;;;:::::／／￣＼＼　　＼
#　　　　　　 ／　　　　|　 |.　┃　.|　| ::::;;;;;;;;;;;;;::::｜ |.　┃　.|　|　　　 ＼　　　　　　　　　　　　　　　　　　　　　
#　　　　　／ 　　　　　＼ ＼＿／／　::::::::::::::::::　＼＼＿／／　　　　　 ＼　　　　
#　　　 ／　　　　　..／￣￣＼　／　　　::｜::　　　＼　／￣￣＼..　　　　　＼
#　　 / 　 　 　 　 :::::　　　　　　|　　　　　 |　　　　　 |　　　　　　 :::::　　　　　 ヽ.　　　
#　　| 　　　　　　　　　　　　　　|　　　　　 |　　　　　 |　　　　　　　　　　　　　　|.
#　　| 　　　　　　　　　　　　　　＼＿＿／＼＿＿／ 　　　　　　　　　　　　　　|　　　　　　　　　　　　　　　　　
#　　| 　　　　　　　　　　　　　　　｜　　　　　　　｜　　　　　　　　　　　　　　　|
#　　| 　　　　　　　　　　　　　　　｜r─‐┬──､|　　　　　　　　　　　　　　　 |
#　　ヽ　　　　　　　　　　　　　　　 |/　　　|　　 　｜　　　　　　　　　　　　　　/
#　　　 ＼　　　　　　　　　　　　　 ＼　　　　　　／　　　　　　　　　　　　　／
#　　　　　＼ 　　　　　　　　　　　　　￣￣￣￣　　　　　　　　　　　　　／
#
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
    N, A, B, C, D = MI()
    S = "."+ST()
    for i in range(min(A, B), max(C, D) ):
        if S[i] == "#" and S[i - 1] == "#":
            print("No")
            exit()
    
    if (A - B) * (C - D) >= 0:
        print("Yes")
    else:
        #3連続あるか判定
        for i in range(max(A, B) + 1, min(N,min(C, D) + 2)):
            if S[i] == "." and S[i - 1] == "." and S[i - 2] == ".":
                print("Yes")
                exit()
        print("No")

if __name__ == '__main__':
    main()
