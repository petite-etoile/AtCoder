N = int(input())
A = [int(i) for i in input().split()]
for i in range(N):
    A[i] -= i + 1
A.sort()
sunuke = A[N // 2]
ans = 0
for a in A:
    ans += abs(a-sunuke)
print(ans)
