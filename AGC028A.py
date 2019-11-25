from fractions import gcd
N, M = map(int, input().split())
S = input()
T = input()
gcd_ = gcd(N, M)
lcm = N * M // gcd_
s_ = lcm//N
t_ = lcm // M

X = ["0"] * (lcm*2)
for i in range(N):
    #print(i, i * s_)
    X[i * s_] = S[i]
ans = True
for i in range(M):
    if X[i * t_] != "0" and T[i] != X[i * t_]:
        ans = False
        break
    else:
        X[i * t_] = T[i]
if ans:
    print(lcm)
else:
    print("-1")
"""
ans = True
if gcd_ != 1:
    for i in range(gcd_):
        # print(i)
        if S[s_ * i] != T[t_ * i]:
            ans = False
            # break
if ans:
    print(lcm)
else:
    print(-1)
"""
