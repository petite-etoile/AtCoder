
N, M = map(int, input().split())
A = []

for i in range(N):
    a, b = map(int, input().split())
    A.append([a, b])
A.sort(key=lambda x: x[0])
ans = 0
for i in range(N):
    money = A[i][0] * A[i][1]
    if M <= A[i][1]:
        ans += A[i][0]*M
        break
    ans += money
    M -= A[i][1]
    # print(ans)
print(ans)
