S = input()
ACGT = "ACGT"
acgt_index = []
for i in range(len(S)):
    if S[i] in ACGT:
        acgt_index.append(i)
if len(acgt_index) == 0:
    print(0)
    exit()
dif = [acgt_index[i + 1] - acgt_index[i] for i in range(len(acgt_index) - 1)]
ans = 0
now = 0
for i in dif:
    if i == 1:
        now += 1
        ans = max(ans, now)
    else:
        now = 0
print(ans+1)
