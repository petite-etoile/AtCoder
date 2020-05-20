N = int(input())
b = [int(i) for i in input().split()]
ans = []
for i in range(len(b)):
    removed = False
    for j in reversed(range(len(b))):
        if b[j] == j + 1:
            ans.append(b.pop(j))
            removed = True
            break
    if not removed:
        print(-1)
        exit()
print('\n'.join(map(str, reversed(ans))))
"""
N = int(input())
b = [int(i) for i in input().split()]
if N < len(b):
    print(-1)
    exit()
for i in range(len(b)):
    if i + 1 < b[i]:
        print(-1)
        exit()
print(b.pop(0))
length = 1
skip = []
# 後ろにある自分より小さい数
smaller = [0]*len(b)
for i in range(len(b)):
    for j in range(i, len(b)):
        if b[i] > b[j]:
            smaller[i] += 1
# print(smaller)
for i in reversed(range(len(b))):
    # print(i, length-b[i]+1, len(b)-i-1)
    #print(i, b[i], b[i] > i, length - b[i]+1 >= smaller[i], length,)
    if length - b[i]+1 >= smaller[i]:  # len(b) - i-1-len(skip):
        print(b[i])
        length += 1
        while skip and length - skip[0][0]+1 >= skip[0][1]:
            print(skip.pop(0)[0])
            length += 1
    else:
        skip.append([b[i], len(b) - i - 1])
    # if i == 0:
    #    print(i, length-b[i]+1, len(b)-i-1)

# print(skip)
"""
