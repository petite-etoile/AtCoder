S = list(input())
AC = True
if S[0] != "A" or S.count("C") != 1 or not 2 <= S.index("C") <= len(S)-2:
    AC = False
else:
    count = 0
    for i in range(1, len(S)):
        if "A" < S[i] < "Z":
            count += 1
            if count == 2:
                AC = False

if AC:
    print("AC")
else:
    print("WA")
