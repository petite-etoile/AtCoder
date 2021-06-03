N, M = map(int, input().split())
ken = [[] for i in range(N)]
Y = []
for i in range(M):
    p, y = map(int, input().split())
    Y.append(y)
    ken[p-1].append(i)
# print(ken)
for i in range(len(ken)):
    ken[i].sort(key=lambda x: Y[x])
# print(ken)

ans = ["0"] * M
for i in range(len(ken)):  # i:ken番号
    for j in range(len(ken[i])):  # j:県の中でj番目
        ans[ken[i][j]] = str(i+1).zfill(6) + str(j+1).zfill(6)
for a in ans:
    print(a)
