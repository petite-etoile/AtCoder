s = int(input())
i = 1
a = [s]
while 1:
    if a[i-1] % 2 == 0:
        a.append(a[i-1] / 2)
    else:
        a.append(3 * a[i-1] + 1)
    if a[i] in a[0:i]:
        print(i+1)
        break
    i += 1
