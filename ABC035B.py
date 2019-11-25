import sys
input = sys.stdin.readline
inf = float('inf')
mod = 10**9+7


def mi(): return map(int, input().split())


def li(): return list(mi())


def lin(n: int): return [input() for _ in range(n)]


def lli(): return [list(map(int, l.split())) for l in input()]


def li_(): return [int(x) - 1 for x in input().split()]


def i(): return int(input())


def f(): return float(input())


def s(): return input()


def main():
    S = input()
    t = i()
    d = {"L": (-1, 0), "R": (1, 0), "U": (0, 1), "D": (0, -1)}
    cnt = 0
    now = [0, 0]
    for st in S:
        if st == "\n":
            break
        if st == "?":
            cnt += 1
        else:
            dx, dy = d[st]
            now[0] += dx
            now[1] += dy
    now[0] = abs(now[0])
    now[1] = abs(now[1])
    ans = now[0] + now[1]
    if t == 1:
        ans += cnt
    else:
        ans -= cnt
        if ans < 0:
            if ans % 2 == 0:
                ans = 0
            else:
                ans = 1
    print(ans)


if __name__ == '__main__':
    main()
