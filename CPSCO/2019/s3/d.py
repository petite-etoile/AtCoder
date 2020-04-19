N = int(input())
S = input()
ok = -1
for i in range(N - 2):

    if S[i:i + 3] == "RGB":
        for j in range(1, i + 1):
            if ok >= i-j:
                break
            else:
                if S[i-j] == "R":
                    continue
                elif S[i - j] == "G":
                    if i - j - 1 < 0 or (S[i - j - 1] != "R" and i-j-1 != ok):
                        print("No")
                        exit()
                else:
                    print("No")
                    exit()
        ok = i + 2
        for j in range(3, N-i):
            if S[i+j] == "R":
                break
            elif S[i+j] == "G":
                if i + j + 1 >= N or S[i + j + 1] != "B":
                    break
            else:
                pass
            ok += 1
if ok != N - 1:
    print("No")
else:
    print("Yes")

"""正しい貪欲法
N = int(input())
S=input()
if S[-1]!="B" or S[0]!="R" or "GG" in S or "RB" in S:
    print("No")
else:
    print("Yes")


N = int(input())
S=input()
if S[-1]!="B" or S[0]!="R":
    print("No")
else:
    prev="R"
    for i in range(N):
        if prev==S[i]=="G":
            print("No")
            exit()
        elif prev=="R" and S[i]=="B":
            print("No")
            exit()
        prev=S[i]
    print("Yes")
"""
"""嘘開放
N = int(input())
S=input()
for i in reversed(range(N)):
    print(S[i])
    if S[i]=="B":
        continue
    elif S[i]=="G":
        if i+1>N-1 or S[i+1]!="B":
            print("No")
            exit()
    else:
        if i+2>N-1 or S[i+1]!="G":
            print("No")
            exit()
print("Yes")
"""
