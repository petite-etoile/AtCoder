S = input()
chokudai = 753
minValue = abs(chokudai-int(S[0:3]))
for i in range(len(S) - 2):
    if minValue > abs(chokudai-int(S[i:i+3])):
        minValue = abs(chokudai - int(S[i:i + 3]))
print(minValue)
