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

    class BigCombination(object):

        def __init__(self, mod: int = 10**9+7, max_n: int = 10**6):
            fac, inv = [1], []
            fac_append, inv_append = fac.append, inv.append

            for i in range(1, max_n+1):
                fac_append(fac[-1] * i % mod)

                inv_append(pow(fac[-1], mod-2, mod))

            for i in range(max_n, 0, -1):
                inv_append(inv[-1] * i % mod)

            self.mod, self.factorial, self.inverse = mod, fac, inv[::-1]

        def get_combination(self, n, r):
            return self.factorial[n] * self.inverse[r] * self.inverse[n-r] % self.mod

        def get_permutation(self, n, r):
            return self.factorial[n] * self.inverse[n-r] % self.mod
    N, M, K = MI()
    comb = BigCombination(max_n=N*M)
    get_comb = comb.get_combination

    ans = 0
    for distansssss in range(N):
        ans += distansssss * (M ** 2) * (N - distansssss)
        ans %= mod
    for distansssss in range(M):
        ans += distansssss * (N ** 2) * (M - distansssss)
        ans %= mod
    ans *= get_comb(N*M-2, K-2)
    print(ans % mod)


if __name__ == '__main__':
    main()
