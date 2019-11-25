# 75数を列挙して、N!を割り切れるかどうかで判定
from math import factorial, sqrt


def comb(n, r):  # n個からr個選ぶ場合の数
    if n < r:
        return 0
    else:
        return factorial(n)//(factorial(r) * factorial(n-r))


N = int(input())
fact = [0]*(N+1)
# それぞれを素因数分解
for i in range(2, N + 1):
    for j in range(2, i+1):
        while i % j == 0:
            i //= j
            fact[j] += 1
over4 = 0
over2 = 0
over24 = 0
over14 = 0
over74 = 0
for f in fact:
    if f >= 2:
        if f >= 4:
            over4 += 1
            if f >= 14:
                over14 += 1
            if f >= 24:
                over24 += 1
            if f >= 74:
                over74 += 1
        else:
            over2 += 1
ans = (comb(over4, 2) * over2) + comb(over4, 3) * 3 + \
    (over14) * (over4 - 1) + over24 * ((over4 - 1) + (over2)) + over74

print(ans)
