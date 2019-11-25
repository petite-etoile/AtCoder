import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def INT_(n): return int(n)-1


def MI(): return map(int, input().split())


def MF(): return map(float, input().split())


def MI_(): return map(INT_, input().split())


def LI(): return list(MI())


def LI_(): return [int(x) - 1 for x in input().split()]


def LF(): return list(MF())


def LIN(n: int): return [input() for _ in range(n)]


def LLIN(n: int): return [LI() for _ in range(n)]


def LLIN_(n: int): return [LI_() for _ in range(n)]


def LLI(): return [list(map(int, l.split())) for l in input()]


def I(): return int(input())


def F(): return float(input())


def ST(): return input().replace('\n', '')


def main():
    N = I()
    p = LF()
    # dp[i][j]:=i枚目までで、k枚が表の確率
    dp = [[0] * (N+1) for _ in range(N)]
    dp[0][1] = p[0]
    dp[0][0] = 1-p[0]
    for i in range(1, N):
        for k in range(i+2):
            if k != 0:
                dp[i][k] += dp[i - 1][k - 1] * p[i]
            if k <= i:
                dp[i][k] += dp[i-1][k]*(1-p[i])
    ans = 0
    for i in range((N + 1) // 2, N + 1):
        ans += dp[N - 1][i]
    #print(*dp, sep="\n")
    print(ans)


if __name__ == '__main__':
    main()
