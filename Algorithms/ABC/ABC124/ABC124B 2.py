N, *H = map(int, open(0).read().split())
ans = 0
ma = H[0]
for i in range(N):
    if i == 0:
        ans += 1
    else:
        if ma <= H[i]:
            ans += 1
            ma = H[i]
print(ans)
