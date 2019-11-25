"""# 累積和(想定解)めんどくさいので書きかけ
N, Q = map(int, input().split())
S = input()
cumulative_sum = [0]*N
cumsum = 0
for i in range(N):
    if S[i:i + 2] == "AC":
        cumsum += 1
    cumulative_sum[i] = cumsum
print(cumulative_sum)
ans = []
for i in range(Q):
    left, right = map(int, input().split())
    left -= 1
    right -= 1
    ans.append(cumulative_sum[right] - cumulative_sum[left])
print(ans, sep="\n")
"""
# 当日出したコード
import bisect
N, Q = map(int, input().split())
S = input()
minians = []
for i in range(N-1):
    if S[i:i + 2] == "AC":
        minians.append(i)
ans = [0]*Q
for i in range(Q):
    left, right = map(int, input().split())
    left -= 1
    right -= 1
    ans[i] = bisect.bisect_left(minians, right) - \
        bisect.bisect_left(minians, left)
print('\n'.join(map(str, ans)))
