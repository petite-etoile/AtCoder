import math
N = int(input())
ans = []
for i in range(int(math.sqrt(N)) + 1):
    for j in range(int(math.sqrt(N)) + 1):
        if i ** j <= N:
            ans.append(i ** j)
        else:
            break
print(max(ans))
