*li, = map(int, open(0).read().split())
new = []
mini = 10
for i in range(len(li)):
    if li[i] % 10 == 0:
        new.append(li[i])
    else:
        new.append(li[i] // 10 * 10 + 10)
        if mini > li[i] % 10:
            mini = li[i] % 10
# print(new)
print(sum(new)-(10-mini))
