from fractions import gcd
N = int(input())
list = [int(i) for i in input().split()]
gcd1 = list[0]
for i in list:
    gcd1 = gcd(i, gcd1)
print(gcd1)
