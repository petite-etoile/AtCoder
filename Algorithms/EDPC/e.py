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
    N, W = mi()
    WV = llin(N)
    max_val = 0
    for i in range(N):
        max_val += WV[i][1]
    max_val += 1
    # dp[i][j]:=i番目の品で、価値がj以上になるように選んだときの最小重量
    dp = [[inf] * max_val for i in range(N)]
    for v in range(max_val):
        if v <= WV[0][1]:
            dp[0][v] = WV[0][0]
        else:
            break
    for i in range(1, N):
        for v in range(max_val):
            if v >= WV[i][1]:
                # print(dp[i - 1][v], dp[i - 1]
                #               [v - WV[i][1]] + WV[i][0])
                dp[i][v] = min(dp[i - 1][v], dp[i - 1]
                               [v - WV[i][1]] + WV[i][0])
            else:
                dp[i][v] = dp[i - 1][v]
            if v <= WV[i][1]:
                dp[i][v] = min(dp[i][v], WV[i][0])

    for v in reversed(range(max_val)):
        if dp[N-1][v] <= W:
            print(v)
            exit()


if __name__ == '__main__':
    main()
