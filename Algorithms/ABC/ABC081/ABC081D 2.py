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
    N = I()
    A = LI()
    A_copy = []
    for i, a in enumerate(A,start=1):
        A_copy.append((a,i))

    A_copy.sort()
    if A_copy[-1][0] <= 0:
        print(N-1)
        #逆順cumsum
        for i in range(1,N)[::-1]:
            print(i+1,i)
            #A[i-1]+=A[i]
    elif A_copy[0][0] >= 0:
        print(N-1)
        #正順cumsum
        for i in range(1,N):
            print(i, i + 1)
            #A[i+1]+=A[i]
    elif abs(A_copy[0][0]) > abs(A_copy[-1][0]):
        print(2*N-1)
        min_index = A_copy[0][1]
        for i in range(N):
            print(min_index, i + 1)
            #A[i]+=A[min_index-1]
        for i in range(1,N)[::-1]:
            print(i + 1, i)
            #A[i-1]+=1A[i]
    else:
        print(2*N-1)
        max_index = A_copy[-1][1]
        for i in range(N):
            print(max_index, i + 1)
            #A[i]+=A[max_index-1]
        for i in range(1,N):
            print(i, i + 1)
            #A[i]+=A[i-1]
    
    #print(A)

    """A_copy = []
    for i, a in enumerate(A,start=1):
        A_copy.append((a,i))

    A_copy.sort()
    A_indexes = [i for (a, i) in A_copy]
    print(2*N)
    for i,j in enumerate(A_indexes,start=1):
        print(i,j)
        print(i, j)
        A[i-1] += 2 * A[j-1]
    print(A)"""
if __name__ == '__main__':
    main()
