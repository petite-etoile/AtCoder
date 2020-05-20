N, K = map(int, input().split())
ans = 0
if K == 0:
    print(N**2)
else:
    for b in range(K, N + 1):
        ans += ((N // b) * (b - K)) + max(0, (N-((N//b)*b+K)+1))
    print(ans)
