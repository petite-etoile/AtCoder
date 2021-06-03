n = int(input())
tri = [0, 0, 1]
for i in range(3, n):
    tri.append((tri[i - 1] + tri[i - 2] + tri[i - 3]) % 10007)
print(tri[n-1])
