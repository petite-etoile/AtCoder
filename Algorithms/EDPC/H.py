import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def INT_(n): return int(n)-1


def MI(): return map(int, input().split())


def MI_(): return map(INT_, input().split())


def LI(): return list(MI())


def LI_(): return [int(x) - 1 for x in input().split()]


def LIN(n: int): return [input() for _ in range(n)]


def LLIN(n: int): return [LI() for _ in range(n)]


def LLIN_(n: int): return [LI_() for _ in range(n)]


def LLI(): return [list(map(int, l.split())) for l in input()]


def I(): return int(input())


def F(): return float(input())


def ST(): return input().replace('\n', '')


def main():
    H, W = MI()
    grid = [input() for _ in range(H)]
    dp = [[0] * W for _ in range(H)]
    dp[0][0] = 1
    for i in range(1, H):
        if grid[i][0] == ".":
            dp[i][0] = dp[i - 1][0]
    for j in range(1, W):
        if grid[0][j] == ".":
            dp[0][j] = dp[0][j - 1]

    for i in range(1, H):
        for j in range(1, W):
            if grid[i][j] == ".":
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                dp[i][j] %= mod
    print(dp[H-1][W-1] % mod)


if __name__ == '__main__':
    main()
