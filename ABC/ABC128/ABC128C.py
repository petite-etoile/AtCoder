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
    switch_pat = []
    for i in range(M):
        k, *s = MI()
        switch_pat.append(s)
    p = LI()
    ans = 0
    for bit in range(2 ** N):
        frag = False
        for m in range(M):
            cnt = 0
            for switch in switch_pat[m]:
                if 1 << (switch-1) & bit:
                    cnt += 1
            if cnt % 2 == p[m]:
                continue
            else:
                frag = True
                break
        if not frag:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
