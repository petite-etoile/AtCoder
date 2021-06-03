A, B = map(int, input().split())
ans = 0
for i in range(A, B + 1):
    para = True
    for j in range(len(str(i))//2):
        if str(i)[j] != str(i)[-j - 1]:
            para = False
            break
    if para:
        ans += 1
print(ans)
