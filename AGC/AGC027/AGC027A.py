N, x = map(int, input().split())
a = [int(i) for i in input().split()]
a.sort()
frag = False
count = 0
for i in range(len(a)):
    if x >= a[i]:
        count += 1
        x -= a[i]
    else:
        frag = True
        break
if not frag and x != 0:
    count -= 1
print(count)
