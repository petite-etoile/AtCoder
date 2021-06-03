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
    T = I()
    S = ST()
    if T <= 0:
        print("Yes")
        exit()
    for s in S:
        if s == "+":
            T += 1
        else:
            T -= 1
        if T <= 0:
            print("Yes")
            exit()
    print("No")


if __name__ == '__main__':
    main()
