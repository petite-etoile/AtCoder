import math
L, N, M = map(int, input().split())
ans = [[-1, -1, -1] for i in range(N)]
# print(ans)
R_P = []  # R,P,indexが格納
for i in range(N):
    R_P.append([int(j) for j in input().split()]+[i])
sorted_RP = sorted(R_P, key=lambda x: x[1], reverse=True)
ABCD = []
for j in range(M):
    ABCD.append([int(j) for j in input().split()])
sorted_ABCD = sorted(ABCD, key=lambda x: x[3], reverse=True)
abcdindex = 0
rpindex = 0
# ans[sorted_RP[rpindex][2]] = [右下+R_P[sorted_RP[rpindex][2]][0], 右下+R_P[sorted_RP[rpindex][2]][0],右下+R_P[sorted_RP[rpindex][2]][0]]
if rpindex == 0:
    exist = False
    while rpindex < N:
        if L//2 > R_P[sorted_RP[rpindex][2]][0]:
            ans[sorted_RP[rpindex][2]] = [R_P[sorted_RP[rpindex][2]][0]] * 3
            exist = True
            break
        else:
            rpindex += 1
    if not exist:
        print(ans)
        exit()
# print(math.ceil((R_P[sorted_RP[0][2]][0] + R_P[sorted_RP[1][2]][0])))
before_index = rpindex
rpindex += 1
# while rpindex < N and abcdindex < M:
# if sorted_RP[rpindex] >= sorted_ABCD / 2:
while rpindex < N:
    if ans[sorted_RP[before_index][2]][0] + math.ceil((sorted_RP[before_index][0] + sorted_RP[rpindex][0]) / math.sqrt(2)) + sorted_RP[rpindex][0] <= L:
        ans[sorted_RP[rpindex][2]] = [ans[sorted_RP[before_index][2]][0] +
                                      math.ceil((sorted_RP[before_index][0] + sorted_RP[rpindex][0]) / math.sqrt(2))] * 3
        before_index = rpindex
    rpindex += 1
    # else:
    #   if sorted_ABCD[]
"""
while 1:
    if sorted_ABCD[abcdindex] > sorted_RP[rpindex]:
        if
        abcdindex+=1
"""
for i in range(N):
    print(' '.join(map(str, ans[i])))
