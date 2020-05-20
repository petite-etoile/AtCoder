# 今度やるときは再帰
D, G = map(int, input().split())
PC = []
for i in range(D):
    pi, ci = map(int, input().split())
    PC.append([pi, ci])
# dp[i][j]:得られる得点  (i番目の問題まで見る といた問題数j)
dp = [[0 for _ in range(2000)]for i in range(11)]
# print(dp)
for i in range(D):
    for j in range(1001):
        # k問解く(中途半端に解く)
        for k in range(PC[i][0]):
            #print(i, j, k)
            dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j]+k*(i+1)*100)
        # コンプボーナスもらえるまで解く
        dp[i + 1][j + PC[i][0]] = max(dp[i + 1][j + PC[i][0]],
                                      dp[i][j] + PC[i][0] * (i + 1) * 100 + PC[i][1])

# print(dp)
for j in range(1001):
    if dp[D][j] >= G:
        print(j)
        break
"""
D, G = map(int, input().split())
p_c_complete_average = []
"""
"""
p, c = [], []
complete = []
average = []
"""
"""
for i in range(D):
    pi, ci = map(int, input().split())
    p_c_complete_average.append([pi, ci, (pi*100*i+ci)//pi, pi*100*i])
    """
"""
    p.append(pi)
    c.append(ci)
    pc.append(pi*100*(i+1)+ci)
    average.append(pi*100*(i+1)
    """
"""
# print(p_c_complete_average)
p_c_complete_average.sort(key=lambda x: x[2],reverse=True)
# print(p_c_complete_average)
index=0
while G > 0:
    if G > p_c_complete_average[i][0]*p_c_complete_average[i][2]:
        G -= p_c_complete_average[i][2]
        ans+=pi
    else:
        minimum_n=10**5
        for i in range(index, len(p_c_complete_average)):
"""
