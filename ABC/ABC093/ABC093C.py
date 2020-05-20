A = [int(i) for i in input().split()]
A.sort()
ans = A[2] - A[1]
A[0] += ans
ans += (A[2] - A[0])//2 + ((A[2] - A[0]) % 2 == 1)*2
print(ans)
