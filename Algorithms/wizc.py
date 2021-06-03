def meguru_bisect(ok, ng):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok


N, Q = map(int, input().split())
S = input()
t, d = [], []
for i in range(Q):
    ti, di = input().split()
    t.append(ti)
    d.append(di)


def solve(i):
    for j in range(Q):
        if S[i] == t[j]:
            if d[j] == "L":
                i -= 1
            else:
                i += 1

            if i < 0 or i >= N:
                return 1
    return 0


left = meguru_bisect(-1, N)
right = meguru_bisect(N, -1)
print(max(right-left-1, 0))

"""
from bisect import bisect_left
N, Q = map(int, input().split())
S = input()
magic = [None] * 26
for i in range(len(S)):
    if magic[ord(S[i]) - ord("A")] is None:
        magic[ord(S[i]) - ord("A")] = [i]
    else:
        magic[ord(S[i]) - ord("A")].append(i)

num_in_the_location = [1]*N
for i in range(Q):
    t, d = input().split()
    # print("\n", t)
    t = ord(t) - ord("A")

    if magic[t] is None:
        continue
    bi = bisect_left(magic[t], N-Q)
    if d == "L":
        # left = True
        for j in range(bi+1):
            if magic[t][j] > 0:
                num_in_the_location[magic[t][j]
                                    ], num_in_the_location[magic[t][j] - 1] = 0, num_in_the_location[magic[t][j] - 1] + num_in_the_location[magic[t][j]
                                                                                                                                            ]
            else:
                num_in_the_location[magic[t][j]] = 0

    else:
        for j in range(bi, len(magic[t])):
            # print(t, magic[t][j], magic[t][j]+1, magic[t])
            if magic[t][j] < N-1:
                num_in_the_location[magic[t][j]
                                    ], num_in_the_location[magic[t][j]+1] = 0, num_in_the_location[magic[t][j]+1]+num_in_the_location[magic[t][j]
                                                                                                                                      ]
            else:
                num_in_the_location[magic[t][j]] = 0
# print(num_in_the_location)
print(sum(num_in_the_location))
"""
