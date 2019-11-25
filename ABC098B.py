N = int(input())
S = input()
ans = 0
for i in range(1, N):
    X = S[:i]
    Y = S[i:]
    count = 0
    for j in range(26):
        if chr(ord("a") + j) in X and chr(ord("a") + j) in Y:
            count += 1
    if count > ans:
        ans = count
print(ans)
