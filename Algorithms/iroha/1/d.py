N, X, Y, *A = map(int, open(0).read().split())
A.sort(reverse=True)
xy = [X, Y]
for i in range(N):
    xy[i % 2 == 1] += A[i]
if xy[0] > xy[1]:
    print("Takahashi")
elif xy[0] < xy[1]:
    print("Aoki")
else:
    print("Draw")
