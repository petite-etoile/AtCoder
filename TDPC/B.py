def dp_table(*counts):  # dp[x][y]を作りたかったら dp_table(xのサイズ,yのサイズ)
    if counts:
        return [dp_table(*counts[1:]) for _ in range(counts[0])]
    else:
        return None


A, B = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
dp = dp_table(A+1, B+1)
dp[0][0] = 0
for i in range(A):
    dp[i+1][0] = a[i]
for i in range(B):
    dp[0][i+1] = b[i]
# print(dp)
for i in range(A):
    for j in range(B):
        if (i + j) % 2 == 0:
            dp[i + 1, j + 1] = max(dp[i][j + 1]+A[i], dp[i+1][j]+B[j])
        else:


"""
嘘貪欲法
A, B = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
score = [0, 0]
sunuke = True
while A or B:
    if A and B:
        if a[0] > b[0]:
            score[sunuke] += a.pop(0)
            A -= 1
        else:
            score[sunuke] += b.pop(0)
            B -= 1
    elif A:
        score[sunuke] += a.pop(0)
        A -= 1
    else:
        score[sunuke] += b[0]
        B -= 1
    sunuke = not sunuke
    print(score)
print(score[1])
"""
