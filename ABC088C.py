c = []
for i in range(3):
    c.append([int(i) for i in input().split()])

ans = True
for i in range(2):
    if c[0][i] - c[0][i + 1] == c[1][i] - c[1][i + 1] == c[2][i] - c[2][i + 1]:
        pass
    else:
        ans = False
for j in range(2):
    if c[j][0] - c[j][0] == c[j][1] - c[j][1] == c[j][2] - c[j][2]:
        pass
    else:
        ans = False
if ans:
    print("Yes")
else:
    print("No")
