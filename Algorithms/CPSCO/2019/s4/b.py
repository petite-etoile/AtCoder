N, D = map(int, input().split())
S = [input() for i in range(D)]

ans = 0
for i in range(D):
    for j in range(D):
        cnt = 0
        for k in range(N):
            if S[i][k] == "o" or S[j][k] == "o":
                cnt += 1
        ans = max(ans, cnt)
print(ans)
