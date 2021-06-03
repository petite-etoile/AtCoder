N = int(input())
sum = 2025
for i in range(1, 10):
    for j in range(1, 10):
        if N + i * j == sum:
            print("{} x {}".format(i, j))
