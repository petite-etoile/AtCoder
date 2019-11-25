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
    S = s()
    T = s()
    dp = [[0] * len(T) for _ in range(len(S))]
    dp[0][0] = int(S[0] == T[0])
    check = [[None] * len(T) for _ in range(len(S))]
    ok = (10, 10)
    check[0][0] = ok if dp[0][0] else (0, 0)
    for i in range(1, len(S)):
        if S[i] == T[0]:
            dp[i][0] = 1
            check[i][0] = ok
        else:
            dp[i][0] = dp[i - 1][0]
            check[i][0] = (-1, 0)
    for j in range(1, len(T)):
        if T[j] == S[0]:
            dp[0][j] = 1
            check[0][j] = ok
        else:
            dp[0][j] = dp[0][j-1]
            check[0][j] = (0, -1)
    for i in range(1, len(S)):
        for j in range(1, len(T)):
            if S[i] == T[j]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                check[i][j] = (-1, -1)
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                if dp[i - 1][j] > dp[i][j - 1]:
                    check[i][j] = (-1, 0)
                else:
                    check[i][j] = (0, -1)

    ans = ""
    i = len(S)-1
    j = len(T)-1
    for _ in range(len(S) + len(T)):
        if check[i][j] == ok:
            print(i, j)
            ans = S[i] + ans
            break
        else:
            if check[i][j] == (-1, -1):
                ans = S[i] + ans
                tmp = i
                i += check[i][j][0]
                j += check[tmp][j][1]
            else:
                tmp = i
                i += check[i][j][0]
                j += check[tmp][j][1]
    print(*check, sep="\n")
    print(ans)


if __name__ == '__main__':
    main()
