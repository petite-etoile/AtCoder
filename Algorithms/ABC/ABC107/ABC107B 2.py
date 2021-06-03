H, W = map(int, input().split())
a = []
for i in range(H):
    list = [i for i in input()]
    a.append(list)
column = [int(i) for i in range(W)]
row = [int(i) for i in range(H)]
for i in range(H):
    for j in range(W):
        if a[i][j] == "#":
            if i in row:
                row.remove(i)
            if j in column:
                column.remove(j)
# print(column)
# print(row)
for i in range(H):
    printed = False
    for j in range(W):
        if i not in row and j not in column:
            print(a[i][j], end="")
            printed = True
    if printed:
        print("")
