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
    S = ST()
    x, y = MI()
    to_x_y = [[], []]
    deleted = False
    for i,s in enumerate(S):
        if s == "T":
            S = S[i:]
            deleted = True
            break
        else:
            x -= 1
    if not deleted:
        S=""
    toY = False
    contin = False
    #run length 
    for i, s in enumerate(S):
        if s == "F":
            if contin:
                to_x_y[toY][-1] += 1
            else:
                to_x_y[toY].append(1)
                contin = True
        else:
            toY = not toY
            contin = False

    #print((x,y),*to_x_y,sep="\n")

    #xについてdp
    now_x = set([0])
    for distanse in to_x_y[0]:    
        next_x = set()
        for i, X in enumerate(now_x):
            next_x.add(X + distanse)
            next_x.add(X - distanse)
        now_x = next_x
    
    #yについてdp
    now_y = set([0])
    for distanse in to_x_y[1]:    
        next_y = set()
        for i, Y in enumerate(now_y):
            next_y.add(Y + distanse)
            next_y.add(Y - distanse)
        now_y = next_y

    #print(now_x,now_y)
    print("YNeos"[x not in now_x or y not in now_y::2] )


if __name__ == '__main__':
    main()