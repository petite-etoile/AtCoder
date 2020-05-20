N, K = map(int, input().split())
k_n = N // K

sum = k_n*k_n*k_n
if K % 2 == 0:
    if K * (N // K) + K // 2 <= N:
        sum += (k_n + 1) ** 3
    else:
        sum *= 2

print(sum)
