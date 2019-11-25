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
    W, H = mi()
    if W / H == 4 / 3:
        print("4:3")
    else:
        print("16:9")


if __name__ == '__main__':
    main()
