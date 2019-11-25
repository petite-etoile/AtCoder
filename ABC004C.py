N = int(input())
N = N % 30
ans = [1, 2, 3, 4, 5, 6]
for i in range(N):
    ans[i % 5], ans[i % 5 + 1] = ans[i % 5 + 1], ans[i % 5]
ans = map(str, ans)
print("".join(ans))
