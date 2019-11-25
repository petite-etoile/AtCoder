N, X = map(int, input().split())
x = [int(i) for i in input().split()]
x.append(X)
x.sort()
dif_x = [x[i + 1] - x[i] for i in range(len(x) - 1)]
n = max(dif_x)  # の約数だけ調べる
divisors = []
for i in range(1, int(n ** 0.5) + 1):
    if n % i == 0:
        divisors.append(i)
        if i != n // i:
            divisors.append(n // i)
divisors.sort(reverse=True)
# print(divisors)
for i in divisors:
    frag = True
    for j in dif_x:
        if j % i == 0:
            continue
        else:
            frag = False
            break
    if frag:
        print(i)
        break
