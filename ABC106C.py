S = input()
K = int(input())
for s in S:
    if int(s) == 1:
        K -= 1
        if K == 0:
            print(s)
            exit()
    else:
        print(s)
        exit()
