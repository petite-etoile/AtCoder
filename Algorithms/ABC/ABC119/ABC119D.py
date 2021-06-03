from bisect import bisect_left

A, B, Q = map(int, input().split())
INF = 10**20
s = [-INF]
for i in range(A):
    s.append(int(input()))
s.append(INF)
t = [-INF]
for i in range(B):
    t.append(int(input()))
t.append(INF)

x = [int(input()) for i in range(Q)]

# x[i]の東にある神社・寺のうち１番近いのと２番めに近いものEastShrine EastTemple
# x[i]の西にある神社・寺のうち１番近いのと２番めに近いものをみてWest~~
# EastShrine,EastTemple
# EastShrine,WastTemple
# WestShrine,EastTemple
# WestShrine,WestTemple

# x[i]-s[i]の符号が変わるタイミングで近い２点を求める
# ではなく二分探索しましょう
# print(s)
# print(t)

for x_i in x:
    s_index = bisect_left(s, x_i)
    t_index = bisect_left(t, x_i)
    WestShrine, EastShrine = s[s_index - 1], s[s_index]
    WestTemple, EastTemple = t[t_index - 1], t[t_index]

    """
    for i in range(len(s)):
        if s[i] < x_i:
            pass
        elif s[i] == x_i:
            if abs(s[i - 1] - x_i) > abs(s[i + 1] - x_i):
                EastShrine = s[i + 1]
                WestShrine = s[i]
            else:
                EastShrine = s[i]
                WestShrine = s[i - 1]
        else:
            WestShrine = s[i - 1]
            EastShrine = s[i]
            #print(WestShrine, EastShrine)
            break
    """
    """
        if t[i] < x_i:
            pass
        elif t[i] == x_i:

            if i == 0:
                WestTemple = t[i]
                EastTemple = t[i + 1]
            elif i == len(t) - 1:
                WestTemple = t[i-1]
                EastTemple = t[i]

            if abs(t[i - 1] - x_i) > abs(t[i + 1] - x_i):
                EastTemple = t[i + 1]
                WestTemple = t[i]
            else:
                EastTemple = t[i]
                WestTemple = t[i - 1]
        else:
            WestTemple = t[i - 1]
            EastTemple = t[i]
            #print(WestTemple, EastTemple)
            break
        """
    #print("WS:", WestShrine, "ES:", EastShrine)
    #print("WT:", WestTemple, "ET:", EastTemple)

    ans1 = abs(max([EastShrine, EastTemple]) - x_i)
    ans2 = abs(min([WestShrine, WestTemple]) - x_i)

    smaller = min(abs(x_i - EastShrine), abs(x_i - WestTemple))
    larger = max(abs(x_i - EastShrine), abs(x_i - WestTemple))
    #print("S:", smaller, "L:", larger)
    ans3 = smaller * 2 + larger

    smaller = min(abs(x_i - WestShrine), abs(x_i - EastTemple))
    larger = max(abs(x_i - WestShrine), abs(x_i - EastTemple))
    ans4 = smaller * 2 + larger

    #print(WestShrine, EastShrine)
    #print(WestTemple, EastTemple)
    #print(ans1, ans2, ans3, ans4)
    print(min([ans1, ans2, ans3, ans4]))
