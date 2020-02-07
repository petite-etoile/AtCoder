H, W = map(int, input().split())
A = []
for i in range(H):
    A.append([int(i) for i in input().split()])
ans = 10**8
for h in range(H):
    for w in range(W):
        cnt = 0
        for i in range(H):
            for j in range(W):
                cnt += min(abs(i - h), abs(j - w)) * A[i][j]

        ans = min(ans, cnt)
print(ans)
