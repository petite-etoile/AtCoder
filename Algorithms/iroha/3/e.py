N = int(input())
S = ""
for _ in range(N):
    s = input()
    if S == "" and s != "/":
        continue
    S += s

prev = S[0]
cnts = []
cnt = 0
for i in range(len(S)):
    if S[i] == prev:
        cnt += 1
    else:
        cnts.append(cnt)
        prev = S[i]
        cnt = 1
cnts.append(cnt)
ans = 0
for i in range(len(cnts) // 2):
    if cnts[i * 2] == cnts[i * 2 + 1]:
        ans += 1
print(ans)
