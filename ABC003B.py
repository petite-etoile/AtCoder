S = input()
T = input()
atcoder = "atcoder@"
ans = True
for s, t in zip(S, T):
    if s != t:
        if s not in atcoder or t not in atcoder:
            ans = False
            break
        elif s == "@" or t == "@":
            continue
        else:
            ans = False
if ans:
    print("You can win")
else:
    print("You will lose")
"""
問題勘違いおじさん
S = input().replace("a", "@").replace(
    "t", "@").replace("c", "@").replace("o", "@").replace("d", "@").replace("e", "@").replace("r", "@")
T = input().replace("a", "@").replace(
    "t", "@").replace("c", "@").replace("o", "@").replace("d", "@").replace("e", "@").replace("r", "@")
if S == T:
    print("You can win")
else:
    print("You will lose")
"""
