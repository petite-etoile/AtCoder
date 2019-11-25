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


def inp(): return int(input())


def f(): return float(input())


def s(): return input().replace('\n', '')


def main():
    N = inp()
    h = li()
    dp = [0] * N
    dp[1] = abs(h[0]-h[1])
    for i in range(2, N):
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]),
                    dp[i - 2] + abs(h[i - 2] - h[i]))
    print(dp[N-1])


if __name__ == '__main__':
    main()
