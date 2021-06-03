N, T = map(int, input().split())
c = []
t = []
for i in range(N):
    hoge1, hoge2 = map(int, input().split())
    c.append(hoge1)
    t.append(hoge2)
candidate = [c[i] for i in range(len(t)) if t[i] <= T]
if len(candidate) == 0:
    print("TLE")
else:
    print(min(candidate))
