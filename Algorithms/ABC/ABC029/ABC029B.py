S = [input() for i in range(12)]
ans = 0
for s in S:
    if "r" in s:
        ans += 1
print(ans)
