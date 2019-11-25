a, b = map(int, input().split())
A = ((b-a) * (b - a-1)) // 2
print(A-a)
