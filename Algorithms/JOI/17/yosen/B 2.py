N, *A = map(int, open(0).read().split())
cnt = 0
ans = 0
for i in range(N):
    if A[i] == 1:
        cnt += 1
        ans = max(ans, cnt)
    else:
        cnt = 0
print(ans+1)
