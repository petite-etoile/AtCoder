import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def mi(): return map(int, input().split())


def li(): return list(mi())


def li_(): return [int(x) - 1 for x in input().split()]


def lin(n: int): return [input() for _ in range(n)]


def llin(n: int): return [li() for _ in range(n)]


def llin_(n: int): return [li_() for _ in range(n)]


def lli(): return [list(map(int, l.split())) for l in input()]


def i(): return int(input())


def f(): return float(input())


def s(): return input().replace('\n', '')


def main():
    N, W = mi()
    WV = llin(N)
    dp = [[0] * (W + 1) for _ in range(N)]
    dp[0] = [WV[0][1] if WV[0][0] <= i else 0 for i in range(W+1)]
    for i in range(1, N):
        for j in range(W + 1):
            if j >= WV[i][0]:
                dp[i][j] = dp[i - 1][j - WV[i][0]] + WV[i][1]
            dp[i][j] = max(0, dp[i][j], dp[i - 1][j])
    print(dp[N-1][W])


if __name__ == '__main__':
    main()
