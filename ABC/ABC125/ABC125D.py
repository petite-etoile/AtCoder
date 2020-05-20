N = int(input())
A = [int(i) for i in input().split()]
B = []
for i in range(N):
    B.append(abs(A[i]))

mini = min(B)
cnt = 0
for i in range(N):
    if A[i] < 0:
        cnt += 1

if cnt % 2 == 0:
    ans = sum(B)
else:
    ans = sum(B) - mini * 2
print(ans)
