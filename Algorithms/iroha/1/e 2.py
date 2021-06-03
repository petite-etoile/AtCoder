N, A, B, *D = map(int, open(0).read().split())
if A == 0 or B == 0:
    print(0)
    exit()
D.sort()
cum = [D[0]-1]
for i in range(1, B):
    cum.append(D[i] - D[i - 1] - 1)
cum.append(N-D[-1])
ans = N-B
for i in range(B+1):
    ans -= cum[i] // A
print(ans)
