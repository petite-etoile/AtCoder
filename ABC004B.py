c = [["0" for i in range(4)] for j in range(4)]
for i in range(4):
    c[3-i] = [j for j in input().split()]
for i in range(4):
    print(" ".join(reversed(c[i])))
