L, X = map(int, input().split())
X %= (2 * L)
if X <= L:
    print(X)
else:
    print(L-(X-L))
