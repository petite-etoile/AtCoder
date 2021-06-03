N = int(input())
red = []
blue = []
for i in range(N):
    x, y = map(int, input().split())
    red.append((x, y))
for i in range(N):
    x, y = map(int, input().split())
    blue.append((x, y))
red.sort(key=lambda x: x[0])
blue.sort(key=lambda x: x[0])
ans = 0
for j in range(N):
    index = -1
    for i in range(len(red)):
        if red[i][0] >= blue[j][0]:
            break
        elif red[i][1] < blue[j][1]:
            if index == -1 or red[index][1] < red[i][1]:
                index = i
    if index != -1:
        red.remove(red[index])
        ans += 1
print(ans)
