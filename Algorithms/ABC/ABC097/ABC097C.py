# K<=5ということから6文字以上のsubstringには5個以上、辞書順で早いprefixを5個以上もつので
# 長さが5以下の文字列のみをみればいい

S = input()
K = int(input())
substrings = []
for i in range(1, min(len(S)+1, 6)):  # 文字数
    for n in range(len(S) - i + 1):
        sub = S[n:n + i]
        if sub not in substrings:
            substrings.append(sub)
# print(substrings)
substrings.sort()
print(substrings[K-1])
"""
部分点解法
S = input()
K = int(input())
# python のsortは辞書順
substrings = []
for i in range(1, len(S)+1):  # 文字数
    for n in range(len(S) - i + 1):
        sub = S[n:n + i]
        if sub not in substrings:
            substrings.append(sub)
# print(substrings)
substrings.sort()
print(substrings[K-1])
"""
