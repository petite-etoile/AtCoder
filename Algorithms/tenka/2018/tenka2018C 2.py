N = int(input())
A = [int(input()) for i in range(N)]

f = True
A.sort()

i = 0
j = 0
before = 0
ans1 = -A[0]

print(A)
for _ in range(N):
    if f:
        ans1 += abs(before - A[i])
        before = A[i]
        i += 1
    else:
        ans1 += abs(before - A[-j-1])
        before = A[-j-1]
        j += 1
    print(ans1)
    f = not f

i = 0
j = 0
before = 0
ans2 = -A[-1]
f = False
for _ in range(N):
    if f:
        ans2 += abs(before - A[i])
        before = A[i]
        i += 1
    else:
        ans2 += abs(before - A[-j-1])
        before = A[-j-1]
        j += 1

    f = not f
print(ans1, ans2)
print(max(ans1, ans2))
