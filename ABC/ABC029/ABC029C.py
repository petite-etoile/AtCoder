import itertools
N = int(input())
# list(itertools.product(["a", "b", "c"], repeat=N))
ans = ["".join(i) for i in itertools.product(["a", "b", "c"], repeat=N)]
print("\n".join(ans))

"""
N = int(input())
# 3**N個
S = [["a", "b", "c"] for i in range(N-1)]
ans = ["a", "b", "c"]
for s in S:
    new = []
    for i in range(len(ans)):
        for sj in s:
            new.append(ans[i] + sj)
    ans = new
print("\n".join(ans))
"""
