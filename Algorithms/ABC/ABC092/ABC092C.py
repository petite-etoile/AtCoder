from numpy import cumsum
N, *A = map(int, open(0).read().split())
A_dif = [abs(A[i] - A[i - 1]) if i != 0 else abs(A[i]) for i in range(N)]
cum_A = cumsum(A_dif)


for i in range(N):
    # ans=iの一つ前までの経路
    # ans+= i-1からi+1までの距離
    # ans+= i+1から最後の観光地までの経路
    # ans+= 最後の観光地から0への距離
    if i == 0:
        ans = 0
        ans += abs(A[i + 1] - 0)
        ans += (cum_A[-1] - cum_A[i + 1])
        ans += abs(A[-1])
    elif i == N - 1:
        ans = cum_A[i-1]
        ans += 0
        ans += 0
        ans += abs(A[-2])
    else:
        ans = cum_A[i-1]
        ans += abs(A[i + 1] - A[i-1])
        ans += (cum_A[-1] - cum_A[i + 1])
        ans += abs(A[-1])
    print(ans)
