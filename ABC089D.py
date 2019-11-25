H, W, D = map(int, input().split())
where = [None] * (H*W+1)
for i in range(H):
    inputing = [int(i) for i in input().split()]
    for j in range(W):
        where[int(inputing[j])] = (i, j)
cum_ = [[0] for _ in range(D)]
print(cum_)
for i in range(H*W):
    cum_[i % D].append(abs(where[i][0]-where[i+D][0]) +
                       abs(where[i][1]-where[i+D][1]))
Q = int(input())

for _ in range(Q):
    ans = 0
    l, r = map(int, input().split())
    #a = cum[l % D][l//D]
    print(ans)
