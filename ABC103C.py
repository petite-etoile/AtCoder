from fractions import gcd
from functools import reduce


def product(a, b):
    return a*b


N = int(input())
a = [int(i) for i in input().split()]
# 最小公倍数-1を代入すると最大
max_m = reduce(product, a)//reduce(gcd, a) - 1
ans = 0
for i in range(len(a)):
    ans += max_m % a[i]
print(ans)
