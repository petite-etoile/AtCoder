inf = float("inf")

# ----入力----
N,L = map(int,input().split())
X = set([int(x) for x in input().split()])
T = [int(x) for x in input().split()]


# ----初期化----
DP = [inf] * (L+5)
DP[0] = 0

# ----状態遷移----
for l in range(L):
    DP[l+1] = min(DP[l+1], DP[l] + T[0] + T[2]*((l+1) in X)) #行動1
    DP[l+2] = min(DP[l+2], DP[l] + T[0] + T[1] + T[2] * ((l+2) in X)) #行動2
    DP[l+4] = min(DP[l+4], DP[l] + T[0] + 3*T[1] + T[2] * ((l+4) in X)) #行動3

# ----コーナーケース----
val1 = DP[L-1] + T[0]/2 + T[1]/2 #行動1
val2 = DP[L-2] + T[0]/2 + T[1] * 1.5 #行動2
val3 = DP[L-3] + T[0]/2 + T[1] * 2.5 #行動3
DP[L] = min(DP[L], val1, val2, val3)

# ----出力----
print(int(DP[L]))
