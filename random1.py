from random import randint
N = 5
a = []
for _ in range(N):
    a.append(randint(0,100))
print(N)
print(*a)