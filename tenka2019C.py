from numpy import cumsum

N = int(input())
S = input()

# 黒を1,白を0として　リスト化
ss = S.replace("#", "1").replace(".", "0")
* ls, = map(int, ss)

# 累積和
cum_ls = cumsum(ls)

# 左から何個目に初めてblackが出てくるか
first_black = -1
for i in range(N):
    if S[i] == "#":
        first_black = i
        break

# blackが後ろから何個まで続いているか
last_black = N
for i in reversed(range(N)):
    if S[i] == "#":
        last_black = i
    else:
        break
if first_black == -1:
    print(0)
else:
    # i番目より左をすべて白、それより右をすべて黒にしたとき何回塗り替えるか
    ans_temp = 10 ** 10
    for i in range(N):
        ans_temp = min(ans_temp, cum_ls[i] +
                       (N-(i+1) - (cum_ls[-1] - cum_ls[i])))

    ans = min(S[first_black:].count("."), S[first_black:].count(
        "#"), S[:last_black].count("#"), ans_temp)

    print(ans)
