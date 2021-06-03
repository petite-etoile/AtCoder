from fractions import gcd
A, B = map(int, input().split())
if gcd(A, B) == A:
    print(A + B)
else:
    print(B-A)
