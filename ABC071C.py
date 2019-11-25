N = int(input())
A = [int(i) for i in input().split()]
A.sort(reverse=True)
prev = -1
ans = []
for i, a in enumerate(A):
    if prev == a:
        ans.append(a)
        prev = -1
        if len(ans) == 2:
            break
    else:
        prev = a
if len(ans) == 2:
    print(ans[0] * ans[1])
else:
    print(0)
