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
    from itertools import permutations
    N, M, R = MI()
    r = LI_()
    d=[[float("inf")] * N for i in range(N)]
    for i in range(N):
        d[i][i]=0
    for _ in range(M):
        a, b, c = MI_()
        c += 1
        d[a][b] = c
        d[b][a] = c
    def warshall_floyd(d, N):
        for k in range(N):
            for i in range(N):
                for j in range(N):
                    d[i][j]=min(d[i][j], d[i][k] + d[k][j])


    warshall_floyd(d, N)

    ans=inf
    for p in permutations(r):
        prev = p[0]
        cost = 0
        for to in p[1:]:
            cost += d[prev][to]
            prev = to
        ans=min(cost,ans)
    print(ans)
if __name__ == '__main__':
    main()