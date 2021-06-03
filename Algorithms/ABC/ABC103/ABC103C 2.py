from functools import reduce
def product(a, b):
    return a*b
N = int(input())
A = [int(i) for i in input().split()]
# 公倍数-1を代入すると最大
max_m = reduce(product,A)-1
ans = 0
for a in A:
    ans += max_m%a
print(ans)
