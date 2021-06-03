A, B, C, X = map(int, open(0).read().split())
ans = 0
for a in range(A+1):
    for b in range(B + 1):
        for c in range(C + 1):
            if 500 * a + 100 * b + 50 * c == X:
                ans += 1
print(ans)


"""A = int(input())
B = int(input())
C = int(input())
X = int(input())


n = 0
for a in range(A+1):
    for b in range(B+1):
        for c in range(C+1):
            if 500 * a + 100 * b + 50 * c == X:
                n += 1
print(n)
"""
