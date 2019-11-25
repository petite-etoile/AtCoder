from functools import reduce


def product(a, b):
    return a*b % (10**9+7)


N = int(input())
S = input()
count = 0
alpha = [1] * 26
left = 0
for s in S:
    #print(ord(s) - ord("a"), s)
    alpha[ord(s) - ord("a")] += 1
ans = reduce(product, alpha)
print(ans - 1)


"""
for i in range(len(S)):
    if alpha[ord(S[i]) - ord("a")] == -1:
        alpha[ord(S[i]) - ord("a")] == i
        continue
    else:
        count += sum_(i-left)
        count %= 10**9+7
        # 書き換える
        left = alpha[ord(S[i]) - ord("a")] + 1
        alpha[ord(S[i]) - ord("a")] = i
count += sum_((N - 1)-left)
count %= 10**9+7
print(count)
"""
