import math
L, N, M = map(int, input().split())
ans = [[-1, -1, -1] for i in range(N)]
# print(ans)
R_P = []  # R,P,indexが格納
for i in range(N):
    R_P.append([int(j) for j in input().split()]+[i])
sorted_RP = sorted(R_P, key=lambda x: x[1], reverse=True)
for i in range(len(sorted_RP)):
    R_P[sorted_RP[i][2]].append(i)
    """if R_P[sorted_RP[i][2]][0] == 200:
        print(R_P[sorted_RP[i][2]], i)"""
ABCD = []
for j in range(M):
    ABCD.append([int(j) for j in input().split()])
    ABCD[j][0] -= 1
    ABCD[j][1] -= 1
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

"""ans.sort(key=lambda x: x[0])
print(ans)"""

# print(math.ceil((R_P[sorted_RP[0][2]][0] + R_P[sorted_RP[1][2]][0])))
before_index = rpindex
rpindex += 1
root2 = math.sqrt(2)
used_index_list = []
frag = True
while rpindex < N and abcdindex < M:
    if sorted_RP[rpindex][1] >= sorted_ABCD[abcdindex][3] / 2:
        if sorted_RP[rpindex][2] in used_index_list:
            rpindex += 1
            continue
        if ans[sorted_RP[R_P[before_index][2]][2]][0] + math.ceil((sorted_RP[R_P[before_index][2]][0] + sorted_RP[rpindex][0]) / root2) + sorted_RP[rpindex][0] <= L:
            if frag:
                print(R_P[before_index],
                      ans[sorted_RP[R_P[before_index][2]][2]][0])
                frag = False
            ans[sorted_RP[rpindex][2]] = [ans[sorted_RP[R_P[before_index][2]][2]][0] +
                                          math.ceil((sorted_RP[R_P[before_index][2]][0] + sorted_RP[rpindex][0]) / root2)] * 3
            """print(ans[sorted_RP[R_P[before_index][2]][2]][0], math.ceil(
                (sorted_RP[R_P[before_index][2]][0] + sorted_RP[rpindex][0]) / root2), sorted_RP[rpindex][0])"""
            before_index = sorted_RP[rpindex][2]
            used_index_list.append(before_index)
            """if ans[before_index][0] >= 1000:
                print(ans[sorted_RP[R_P[before_index][2]][2]][0], math.ceil(
                    (sorted_RP[R_P[before_index][2]][0] + sorted_RP[rpindex][0]) / root2), sorted_RP[rpindex][0])"""
        rpindex += 1
    else:
        # あとで改良(before==ならやっていい):
        if sorted_ABCD[abcdindex][0] in used_index_list or sorted_ABCD[abcdindex][1] in used_index_list:
            abcdindex += 1
            continue
        # ここでout of range
        # if ans[sorted_RP[before_index][2]][0] + math.ceil((sorted_RP[before_index][0] + R_P[sorted_ABCD[abcdindex][0]][0] + R_P[sorted_ABCD[abcdindex][1]][0]) / root2) + R_P[sorted_ABCD[abcdindex][1]][0] <= L:
        a = ans[sorted_RP[R_P[before_index][2]][2]][0] + math.ceil((sorted_RP[R_P[before_index][2]][0] +
                                                                    R_P[sorted_ABCD[abcdindex][0]][0]) / root2)
        b = a+math.ceil(
            (R_P[sorted_ABCD[abcdindex][0]][0] + R_P[sorted_ABCD[abcdindex][1]][0])/root2)
        if b+R_P[sorted_ABCD[abcdindex][1]][0] < L:
            ans[sorted_ABCD[abcdindex][0]] = [ans[sorted_RP[R_P[before_index][2]][2]][0] +
                                              math.ceil((sorted_RP[R_P[before_index][2]][0] +
                                                         R_P[sorted_ABCD[abcdindex][0]][0]) / root2)] * 3
            ans[sorted_ABCD[abcdindex][1]] = [
                ans[sorted_ABCD[abcdindex][0]][0]+math.ceil((R_P[sorted_ABCD[abcdindex][0]][0] + R_P[sorted_ABCD[abcdindex][1]][0])/root2)] * 3
            # R_P[sorted_ABCD[abcdindex][1]][3]
            """if ans[sorted_ABCD[abcdindex][1]][0] >= 1000:
                print(ans[sorted_RP[R_P[before_index][2]][2]][0], math.ceil((math.ceil((sorted_RP[R_P[before_index][2]][0] +
                                                                                        R_P[sorted_ABCD[abcdindex][0]][0]) / root2) + R_P[sorted_ABCD[abcdindex][1]][0]) / root2), R_P[sorted_ABCD[abcdindex][1]][0])
                print(ans[sorted_RP[R_P[before_index][2]][2]][0] + math.ceil((math.ceil((sorted_RP[R_P[before_index][2]][0] +
                                                                                         R_P[sorted_ABCD[abcdindex][0]][0]) / root2) + R_P[sorted_ABCD[abcdindex][1]][0]) / root2) + R_P[sorted_ABCD[abcdindex][1]][0])
                print(ans[sorted_ABCD[abcdindex][0]])
                print(ans[sorted_ABCD[abcdindex][1]])"""
            """print(ans[sorted_RP[R_P[before_index][2]][2]][0], math.ceil((math.ceil((sorted_RP[R_P[before_index][2]][0] +
                                                                                    R_P[sorted_ABCD[abcdindex][0]][0])/root2) + R_P[sorted_ABCD[abcdindex][1]][0]) / root2), R_P[sorted_ABCD[abcdindex][1]][0])"""
            before_index = sorted_ABCD[abcdindex][1]

            # print(before_index, sorted_RP[before_index],
            #      R_P[sorted_ABCD[abcdindex][1]][3])
            # print(sorted_RP[before_index][2], sorted_ABCD[abcdindex][1])
            # before_index = sorted_ABCD[abcdindex][1]
            used_index_list.append(sorted_ABCD[abcdindex][0])
            used_index_list.append(sorted_ABCD[abcdindex][1])

        abcdindex += 1

# 半径 sorted_RP[index][0]
"""
for i in range(len(sorted_RP)):
    if R_P[sorted_RP[i][2]][3] != i:
        print(sorted_RP[i])
"""

for i in range(N):
    if ans[i][0] != -1:
        print("下", R_P[i])
        print(' '.join(map(str, ans[i])))
    """
ans.sort(key=lambda x: x[0])
for i in range(N):
    print(' '.join(map(str, ans[i])))
"""
"""
for i in used_index_list:
    print(ans[i][0], i, R_P[i][0])
"""
