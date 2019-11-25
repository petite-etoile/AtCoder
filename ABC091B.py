N = int(input())
words = []
s = []
for i in range(N):
    si = input()
    s.append(si)
    if si not in words:
        words.append(si)
M = int(input())
t = []
for i in range(M):
    ti = input()
    t.append(ti)
    if ti not in words:
        words.append(si)
ans = 0
for word in words:
    ans = max(ans, (s.count(word) - t.count(word)))
print(ans)
