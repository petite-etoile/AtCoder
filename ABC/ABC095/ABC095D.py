import numpy as np
N, C = map(int, input().split())
XV = [list(map(int, input().split())) for i in range(N)]


V_minus_X = [XV[i][1]-(XV[i][0]-XV[i-1][0])
             for i in range(1, N)]  # i==0なら見ない それ以外ならXV[i-1][0]足して上げる
V_minus_X.insert(0, XV[0][1]-XV[0][0])
cum_ = np.cumsum(V_minus_X)


V_minus_X_reverse = [XV[i][1]-(XV[i+1][0]-XV[i][0])
                     for i in range(0, N-1)]
V_minus_X_reverse.append(XV[-1][1]-(C-XV[-1][0]))
V_minus_X_reverse.reverse()
cum_reverse = np.cumsum(V_minus_X_reverse)

m_ = []
m_reverse = []
maxim = 0
maxim_reverse = 0
maxim_where = 0
maxim_reverse_where = 0
# print("print")
for i in range(N-1):
    if maxim < cum_[i]:
        maxim = cum_[i]
        maxim_where = XV[i][0]
    if maxim_reverse < cum_reverse[i]:
        maxim_reverse = cum_reverse[i]
        maxim_reverse_where = C - XV[-i - 1][0]
    m_.append((maxim, maxim_where))
    m_reverse.append((maxim_reverse, maxim_reverse_where))

ans = 0

for i in range(N - 1):
    next = m_[i][0] + m_reverse[-i - 1][0] - \
        min(m_[i][1], m_reverse[-i - 1][1])
    ans = max(next, ans)

print(max(ans, max(cum_), max(cum_reverse)))
