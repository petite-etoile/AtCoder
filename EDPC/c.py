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


def I(): return int(input())


def f(): return float(input())


def s(): return input().replace('\n', '')


def main():
    N = I()
    ABC = llin(N)
    dp = [[0] * 3 for _ in range(N)]
    dp[0] = ABC[0]
    for i in range(1, N):
        for j in range(3):
            dp[i][j] = max((ABC[i][j]+dp[i - 1][k]
                            for k in range(3) if k != j))
    print(max(dp[N-1]))


if __name__ == '__main__':
    main()
