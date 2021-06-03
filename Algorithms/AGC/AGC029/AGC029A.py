N = list(input())
b_n = N.count("B")
point = 0
for i in range(len(N)):
    if N[i] == "B":
        point += i
future_point = (b_n * (len(N) - 1 - b_n + 1 + len(N) - 1)) // 2
print(future_point - point)


"""
N = list(input())
stack = []
count = 0
while N:
    stack.append(N.pop(0))
    i = 0
    while len(stack) >= 2:
        #print(stack, i)
        if stack[-2 - i] != stack[-1 - i]:
            count += 1
            tmp = stack[-2 - i]
            stack[-2 - i] = stack[-1 - i]
            stack[-1 - i] = tmp
            i += 1
            if i == len(stack)-1:
                break
        else:
            break
print(count)
"""

"""
問題勘違いおじさん
N = input()
left_color = N[0]
current_color = N[0]
count1 = 0
for i in range(len(N)):
    if current_color == N[i]:
        continue
    else:
        if left_color == N[i]:
            count1 += 1
        current_color = N[i]
right_color = N[-1]
current_color = N[-1]
count2 = 0
for i in reversed(range(len(N))):
    if current_color == N[i]:
        continue
    else:
        if left_color == N[i]:
            count2 += 1
        current_color = N[i]
print(max(count1, count2))
"""
