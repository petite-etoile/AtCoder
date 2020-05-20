# とあるカードCに対して、その約数がS枚だとする
# Sが奇数なら
from math import ceil


def solve(C, i, N):
    divisor_sum = 0
    for j in range(N):
        if j == i:
            continue
        elif C[i] % C[j] == 0:
            divisor_sum += 1
    if divisor_sum != 0:
        return (ceil((divisor_sum+1)/2) / (divisor_sum+1))
    else:
        return 1


N = int(input())
C = [int(input()) for _ in range(N)]
ans = 0
for i in range(N):
    ans += solve(C, i, N)
print(ans)
"""
99点TLE
from itertools import permutations


def solve(pair, N, C):
    c = []
    surface = [True]*N
    for p in pair:
        c.append(C[int(p)])
    for i in range(len(c)):
        for j in range(i + 1, len(c)):
            if c[j] % c[i] == 0:
                surface[j] = not surface[j]

    return surface.count(True)


N = int(input())
S = [str(i) for i in range(N)]
C = [int(input()) for _ in range(N)]
permutation = list(permutations("".join(S)))
sum = 0
for p in permutation:
    sum += solve(p, N, C)
print(sum/len(permutation))
"""
"""
S="arc"
anagram_list = [''.join(v) for v in itertools.permutations(s)]

print(anagram_list)
# ['arc', 'acr', 'rac', 'rca', 'car', 'cra']
"""
