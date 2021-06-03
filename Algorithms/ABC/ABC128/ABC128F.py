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
    s = LI()

    """
    A+kC=N-1
    A=N-1-kC
    0,A     ,C, A+C       ,2C,A+2C      ,3C,A+3C      =N-1
    0,N-1-kC,C, N-1-(k-1)C,2C,N-1-(k-2)C,3C,N-1-(k-3)C=N-1
    """

    ans = 0
    for c in range(1, N):
        score = 0
        hass = set([0, N-1])

        for k in range(1, (N - 1) // c):
            if k * c in hass or N - 1 - (k * c) in hass or N - 1 - (k * c) == k * c:
                score = -inf
                break
            #print(N - 1 - (k * c), k*c)
            score += s[N - 1 - (k * c)] + s[k * c]
            hass.add(N - 1 - (k * c))
            hass.add(k * c)

            # print(score)
            ans = max(ans, score)
    print(ans)


if __name__ == '__main__':
    main()
