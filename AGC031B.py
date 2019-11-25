import sys
N = int(input())
C = [0]
n = N
for i in range(1, n + 1):
    c = int(sys.stdin.readline())
    if c == C[-1]:
        N -= 1
    else:
        C.append(c)
dp = [0] * (N + 2)
dp[0] = 1
dp[1] = 1
cumsum = [0] * (2 * (10 ** 5) + 2)
cumsum[C[1]] = 1
for i in range(2, N+1):
    dp[i] = dp[i - 1] + cumsum[C[i]]
    cumsum[C[i]] += dp[i-1]
    dp[i] %= (10 ** 9 + 7)
print(dp[N])

"""
import sys
N = int(input())
C = [0]
#c = [int(sys.stdin.readline()) for i in range(N)]
n = N
for i in range(1, n + 1):
    c = int(sys.stdin.readline())
    if c == C[-1]:
        N -= 1
    else:
        C.append(c)
#C = C+c
dp = [0] * (N + 2)
dp_2 = [0] * (N + 2)
color = [[]for i in range((2*(10**5)+2))]
dp[0] = 1
dp[1] = 1
dp_2[0] = 1
dp_2[1] = 1
color[C[1]].append(1)
cumsum = [0] * (2 * (10 ** 5) + 2)
cumsum[C[1]] = 1
for i in range(2, N+1):
    dp[i] = dp[i - 1] + cumsum[C[i]]
    cumsum[C[i]] += dp[i-1]
    # ↓これだと遅い(当日はこれ以上の高速化が思いつけなくてTLE)
    dp_2[i] = dp_2[i - 1] + sum([dp_2[col - 1] for col in color[C[i]]])
    color[C[i]].append(i)
    dp[i] %= (10 ** 9 + 7)
# print(C)
# print(dp)
# print(dp_2)
print(dp[N])
"""
