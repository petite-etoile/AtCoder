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
    N, M = MI()
    A = LI()
    minA = min(A)
    BC = LLIN(M)
    BC.sort(reverse=True, key=lambda x: x[1])
    bc = []
    cnt = 0
    for b, c in BC:
        if cnt >= N or minA >= c:
            break
        bc += [c] * b
        cnt += b

    l = A + bc
    l.sort(reverse=True)
    ans = sum(l[:N])
    print(ans)

    """
    from bisect import bisect_left
    N, M = MI()
    A = LI()
    A.sort()
    BC = LLIN(M)
    BC.sort(key=lambda x: x[1])
    now = 0  # 要検討
    ans = 0
    for b, c in BC:
        bis = bisect_left(A, c)
        print(bis, b, c)
        if bis - now < 0:
            continue
        else:
            if bis - now > b:
                ans += b*c
                now += b
            else:
                ans += (bis - now) * c
                now = bis
                print(bis, now)
        print(ans)
    # nowまでは想いのままに

    for i in range(now, N):
        ans += A[i]
    print(ans)
"""


if __name__ == '__main__':
    main()
