aaa = []
for i in range(3):
    a, b = map(int, input().split())
    aaa.append(a)
    aaa.append(b)

aaa.sort()
cnt = 0
prev = aaa[0]
c = []
for i, aa in enumerate(aaa):
    if aa == prev:
        cnt += 1
    else:
        c.append(cnt)
        prev = aa
        cnt = 1
c.append(cnt)
c.sort()
print(c)
if [1, 1, 2, 2] == c:
    print("YES")
else:
    print("NO")
