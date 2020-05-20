*a, k = map(int, open(0).read().split())
for i in range(5):
    for j in range(5):
        if i == j:
            continue
        if abs(a[j] - a[i]) > k:
            print(":(")
            exit()
print("Yay!")
