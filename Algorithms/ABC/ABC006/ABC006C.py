N, M = map(int, input().split())
ans = [0, N, 0]
sum = N*3
if abs(sum - M) > N:
    print("-1 -1 -1")
else:
    if sum - M > 0:
        ans[0] = abs(sum - M)
        ans[1] -= abs(sum - M)
    elif sum - M == 0:
        pass
    else:
        ans[2] = abs(sum - M)
        ans[1] -= abs(sum - M)
    print(' '.join(map(str, ans)))
