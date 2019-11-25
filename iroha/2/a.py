S = input()
T = input()
N = len(S)
dp = [[0] * (N+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N+1):
        if S[i-1] == T[j-1]:
            dp[i][j] = dp[i - 1][j - 1]+1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
print(dp[N][N]+1)

# 誤読
"""from collections import defaultdict
S = input()
T = input()
dic1 = defaultdict(int)
for s in S:
    dic1[ord(s) - ord("a")] += 1
dic2 = defaultdict(int)
for t in T:
    dic2[ord(t) - ord("a")] += 1
ans = 0
# ans = len(S)
print(dic1)
print(dic2)

ans = 0
for s in S:
    ch = ord(s) - ord("a")
    if dic2[ch] > 0:
        ans += 1
        dic2[ch] -= 1
print(ans+1)
"""
