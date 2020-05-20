s = input()
S = [int(s[i]) for i in range(len(s))]
# print(S)
count = 0
before = 0
while 1:
    #print("S:", S)
    is_continue = False
    # print(len(S))
    #deleted = False
    for i in range(max([before, 0]), len(S) - 1):
        #print(before, i)
        #print(S[i], S[i + 1])
        # print(S)
        if S[i] != S[i + 1]:
            # print(count)
            del S[i]
            del S[i]
            count += 2
            is_continue = True
            before = i - 2
            #deleted = True
            break
    if not is_continue:
        break
print(count)
