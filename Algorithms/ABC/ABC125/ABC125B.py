N = int(input())
v = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]

ans = 0
for i in range(N):
    if v[i] > c[i]:
        ans += v[i] - c[i]
print(ans)
