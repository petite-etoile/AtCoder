N = int(input())
AB = []
for i in range(N):
    a, b = map(int, input().split())
    AB.append([min(a, b), max(a, b)])
depend_A = sorted(AB, key=lambda x: x[0])
depend_B = sorted(AB, key=lambda x: x[1])
ans_in = depend_A[N // 2][0]
ans_out = depend_B[N // 2][1]
ans = 0
for i in range(len(AB)):
    ans += AB[i][1]-AB[i][0]+abs(AB[i][0]-ans_in)+abs(AB[i][1]-ans_out)
print(ans)
