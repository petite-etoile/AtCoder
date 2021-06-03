from numpy import cumsum
N, K = map(int, input().split())
S = input()
*S, = map(int, list(S))
zeros = [0]
ones = [0]
if S[0] == 0:
    ones.append(0)
cnt = 1
now = S[0]
for i in range(1, N):
    if now == S[i]:
        cnt += 1
    else:
        if now == 0:
            zeros.append(cnt)
        else:
            ones.append(cnt)
        cnt = 1
        now = S[i]
if now == 0:
    zeros.append(cnt)
else:
    ones.append(cnt)
if S[-1] == 0:
    ones.append(0)

c_zero = cumsum(zeros)
c_one = cumsum(ones)
if len(zeros) <= K:
    print(len(S))
else:
    ans = 0
    for i in range(0, len(zeros) - K):
        aaa = c_zero[i+K]-c_zero[i] + c_one[i+K+1]-c_one[i]
        ans = max(aaa, ans)
    print(ans)
