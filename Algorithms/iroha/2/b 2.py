X, Y = map(int, input().split())
A, B = map(int, input().split())
Sx, Sy = map(int, input().split())
Tx, Ty = map(int, input().split())


def is_left(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]) > 0


if is_left([0, A], [X, B], [Sx, Sy]) == is_left([0, A], [X, B], [Tx, Ty]):
    print("No")
else:
    print("Yes")
