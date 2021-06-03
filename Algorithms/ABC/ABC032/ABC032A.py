from fractions import gcd
a = int(input())
b = int(input())
n = int(input())

ans = a * b // gcd(a, b)
i = 1
while 1:
    if ans * i < n:
        i += 1
    else:
        ans = i * ans
        break
print(ans)
