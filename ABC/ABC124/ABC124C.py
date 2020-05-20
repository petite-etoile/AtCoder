S = input()
even_1 = 0
odd_1 = 0
even_2 = 0
odd_2 = 0
for i in range(len(S)):
    if i % 2 == 0:
        if S[i] == "1":
            even_1 += 1
        else:
            even_2 += 1
    else:
        if S[i] == "0":
            odd_1 += 1
        else:
            odd_2 += 1
print(min(even_1+odd_1, even_2+odd_2))
