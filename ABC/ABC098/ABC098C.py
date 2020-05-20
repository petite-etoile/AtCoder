N = int(input())
S = input()
E_cost = S.count("E")
W_cost = 0
ans = N
for s in S:
    if s == "E":
        E_cost -= 1
    ans = min(ans, E_cost + W_cost)
    if s == "W":
        W_cost += 1
print(ans)

"""
嘘解法
N = int(input())
S = input()
S_list = list(S)
face = [-1, 1]
ans_index = N // 2
while ans_index != N - 1 and S[ans_index] == S[ans_index + face[S[ans_index] == "E"]]:
    ans_index += face[S[ans_index] == "E"]
# print(ans_index)
ans = 0
for i in range(len(S)):
    if i < ans_index and S[i] == "W":
        ans += 1
    elif ans_index == i:
        continue
    elif i > ans_index and S[i] == "E":
        ans += 1
print(ans)
"""
