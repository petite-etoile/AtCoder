N = int(input())
X = [int(i) for i in input().split()]
X_sorted = sorted(X)
a = [X_sorted[N//2-1], X_sorted[N//2]]
for i in range(N):
    if X[i] >= a[1]:
        print(a[0])
    else:
        print(a[1])
