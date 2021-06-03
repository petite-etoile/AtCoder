a, b = map(int, input().split())
num = int(str(a) + str(b))
for i in range(1000):
    if num == i ** 2:
        print("Yes")
        exit()
print("No")
