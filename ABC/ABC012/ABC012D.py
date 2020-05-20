def warshall_floyd(d, N):
    for k in range(N):
        for i in range(N):
            for j in range(N):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])


N, M = map(int, input().split())
d = [[float("inf")] * N for i in range(N)]
for i in range(N):
    d[i][i] = 0
for _ in range(M):
    i, j, w = map(int, input().split())
    d[i-1][j-1] = w
    d[j-1][i-1] = w
warshall_floyd(d, N)
ans = float("inf")
for i in range(N):
    longest = 0
    for j in range(N):
        longest = max(longest, d[i][j])
    ans = min(longest, ans)
print(ans)
