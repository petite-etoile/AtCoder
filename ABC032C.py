N, K = map(int, input().split())
max_length = 0
substring = []
product = 1
solved = False
for i in range(N):
    s = int(input())
    if solved:
        continue
    if s == 0:
        max_length = N
        solved = True
    product *= s
    substring.append(s)
    if product > K:
        product = product//substring[0]
        del substring[0]
    if max_length < len(substring):
        max_length = len(substring)
print(max_length)
