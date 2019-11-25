n, c = map(int, input().split())
xv = []
for _ in range(n):

    xv.append(tuple(map(int, input().split())))

a = [0]*n
a[0] = xv[0][1]-xv[0][0]
for i in range(1, n):
    a[i] = a[i-1]+xv[i][1]-xv[i][0]+xv[i-1][0]


b = [0]*n
b[n-1] = xv[n-1][1]-(c-xv[n-1][0])
for i in range(n-2, -1, -1):
    b[i] = b[i+1]+xv[i][1]-(c-xv[i][0])+(c-xv[i+1][0])

amax = [0]*n
bmax = [0]*n
amax[0], bmax[n - 1] = max(0, a[0]), max(0, b[n - 1])
print("bmax[n-1]", bmax[n-1])
for i in range(1, n):
    amax[i] = max(a[i], amax[i - 1])
print("print")
for i in range(n-2, -1, -1):
    bmax[i] = max(b[i], bmax[i + 1])
    print(b[i])
print(bmax)
ans = 0
print("print")
for i in range(n):
    if i == n-1:
        ans = max(ans, amax[i])
    else:
        print(bmax[i])
        # print(amax[i]+bmax[i+1]-xv[i][0])
        ans = max(ans, amax[i]+bmax[i+1]-xv[i][0])

for i in range(n-1, -1, -1):
    if i == 0:
        ans = max(ans, bmax[i])
    else:
        ans = max(ans, amax[i-1]+bmax[i]-(c-xv[i][0]))
print(ans)
