N, Y = map(int, input().split())
for i in range(N+1):
    for j in range(N+1):
        if (N - i - j) * 10000 + i * 5000 + j * 1000 == Y:
            if (N - i - j) < 0:
                continue
            print(N - i - j, i, j)
            exit()
print(-1, -1, -1)
