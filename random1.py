from random import randint
N = 3
a = []
for _ in range(N):
    a.append(randint(0,100))
b = []
for _ in range(N):
    b.append(randint(0,100))

print(N)
print(*a)
print(*b)