N, M, X, Y = map(int, input().split())
x = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]

max_x = max(x)
min_y = min(y)
if max_x < min_y and max_x < Y and min_y > X:
    print("No War")
else:
    print("War")
