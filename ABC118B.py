N, M = map(int, input().split())
food = [1 for i in range(M + 1)]
food[0] = 0
for i in range(N):
    k, *a = map(int, input().split())
    for j in range(1, M+1):
        if j not in a:
            food[j] = 0
# print(food)
print(sum(food))
