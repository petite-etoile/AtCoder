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
def LIN(n:int): return [I() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def main():
    from heapq import heappop, heappush, heappushpop
    from math import floor,ceil,sqrt,factorial
    """O(max(h)*log(n))なので無理
    N, A, B = MI()
    H = []
    #heapで最大を持ち続けたいのでマイナスにして格納するよ!(popするときは符号反転させる)
    for _ in range(N):
        h=I()
        heappush(H, -h)
    C = A - B
    
    for i in range(1, -H[0] // B + 2):
        heappushpop(H, H[0] + C)
        print(H[0],i,i*B)
        if - H[0] <= i * B:
            print(i)
            break
            """
    #操作回数で二分探索
    N, A, B = MI()
    H = LIN(N)
    C=A-B

    def is_ok(n):
        cnt = 0
        for h in H:
            cnt+=max(0,ceil((h-n*B)/C))
        return cnt <= n
        
    ok = 10 ** 9 // B + 1
    ng=0
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if is_ok(mid):
            ok = mid
        else:
            ng = mid
    print(ok)   

        
        
        

if __name__ == '__main__':
    main()