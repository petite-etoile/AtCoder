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
    N, M = MI()
    s = ["#"*M]
    up = [[0] * (M+2) for _ in range(N+2)]
    left = [[0]*(M+2) for _ in range(N+2)]
    right = [[0]*(M+2) for _ in range(N+2)]
    down = [[0] * (M+2) for _ in range(N+2)]
    for i in range(N):
        a = ST()
        s.append("#"+a+"#")
    s += ["#" * M]
    for i in range(1, N+1):
        for j in range(1, M+1):
            """if (i, j) == (0, 0):
                if s[i][j] == ".":
                    up[i][j] = 1
                    left[i][j] = 1"""
            if s[i][j] == "#":
                continue
            else:
                up[i][j] = up[i-1][j] + 1
                left[i][j] = left[i][j-1] + 1
    for i in range(1, N+1)[::-1]:
        for j in range(1, M+1)[::-1]:
            if s[i][j] == "#":
                continue
            else:
                down[i][j] = down[i+1][j] + 1
                right[i][j] = right[i][j+1] + 1
    ans = 0
    for i in range(1, N+1):
        for j in range(1, M + 1):
            if s[i][j] == ".":
                """print((left[i][j-1] + right[i][j+1]),
                      (up[i - 1][j] + down[i + 1][j]), end="")"""
                ans += (left[i][j-1] + right[i][j+1]) * \
                    (up[i - 1][j] + down[i + 1][j])
    print(ans)
    """
    print(*up, sep="\n")
    print()
    print(*down, sep="\n")
    print()
    print(*left, sep="\n")
    print()
    print(*right, sep="\n")
    print(ans)
    """


if __name__ == '__main__':
    main()
