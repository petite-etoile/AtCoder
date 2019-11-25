import sys
from functools import lru_cache
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
    N = I()
    A = LI_()
    cnt = [0, 0, 0]
    for a in A:
        cnt[a] += 1

    def recursion(i, j, k, dp):
        if dp[i][j][k] != -1:
            return dp[i][j][k]
        if (i, j, k) == (0, 0, 0):
            dp[i][j][j] = 0
            return 0
        else:
            dp[i][j][k] = 0
            if i != 0:
                #print(i, j, j, recursion(i-1, j, k))
                if dp[i-1][j][k] == -1:
                    dp[i][j][k] += recursion(i - 1, j, k, dp) * (i / N)
                else:
                    dp[i][j][k] += dp[i-1][j][k] * (i / N)
            if j != 0:
                if dp[i+1][j-1][k] == -1:
                    dp[i][j][k] += recursion(i + 1, j - 1, k, dp) * (j / N)
                else:
                    dp[i][j][k] += dp[i+1][j-1][k] * (j / N)
            if k != 0:
                if dp[i][j+1][k-1] == -1:
                    dp[i][j][k] += recursion(i, j + 1, k - 1, dp) * (k / N)
                else:
                    dp[i][j][k] += dp[i][j+1][k-1] * (k / N)

            dp[i][j][k] += 1
            dp[i][j][k] /= (i+j+k)/N
            return dp[i][j][k]
    # dp[i][j][k]:=1貫の皿がi,２貫がj,3貫がk皿有るときのなくなるまでの期待値
    dp = [[[-1]*(N+1) for _ in range(N+1)]for _ in range(N+1)]
    ans = recursion(cnt[0], cnt[1], cnt[2], dp)
    print(ans)


if __name__ == '__main__':
    main()
