import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def mi(): return map(int, input().split())


def li(): return list(mi())


def lin(n: int): return [input() for _ in range(n)]


def llin(n: int): return [li() for _ in range(n)]


def llin_(n: int): return [li_() for _ in range(n)]


def lli(): return [list(map(int, l.split())) for l in input()]


def li_(): return [int(x) - 1 for x in input().split()]


def i(): return int(input())


def f(): return float(input())


def s(): return input().replace("\n", "")


def main():
    from itertools import accumulate
    N, Q = mi()
    lr = llin_(Q)
    imos = [0]*(N+1)
    for l, r in lr:
        imos[l] += 1
        imos[r+1] -= 1
    cnt = list(accumulate(imos))[:-1]
    ans = ""
    for c in cnt:
        if c % 2 == 0:
            ans += "0"
        else:
            ans += "1"
    print(ans)


if __name__ == '__main__':
    main()
