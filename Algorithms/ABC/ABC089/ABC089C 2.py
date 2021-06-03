import itertools

N = int(input())
l = ["M", "A", "R", "C", "H"]
S = [input()[0] for i in range(N)]
ans = 0
anagram = list(itertools.combinations([0, 1, 2, 3, 4], 3))

for ana in anagram:
    ans += S.count(l[ana[0]])*S.count(l[ana[1]])*S.count(l[ana[2]])

print(ans)
