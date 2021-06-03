M, K = map(int, input().split())
if K == 0:
    l = [i // 2 for i in range(2 ** (M + 1))]
    print(*l)
elif K >= 2 ** M:
    print(-1)
else:
    if M == 1:
        # K==1のときしかここに入ってきてないので
        print(-1)
    else:
        left = [i for i in range(2 ** M) if i != K]
        right = [i for i in reversed(range(2 ** M)) if i != K]
        ans = left + [K] + right + [K]
        print(*ans)
