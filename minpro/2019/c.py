K, A, B = map(int, input().split())
if K <= A:
    ans = K+1
elif A+1 < B:
    K -= A - 1  # A-1回叩く
    ans = A
    ans += (K // 2) * (B - A)
    if K % 2 == 1:
        ans += 1

else:
    ans = K+1
print(ans)
