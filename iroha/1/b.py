S = input()
K = int(input())
ans = S[K % len(S):]+S[:K % len(S)]
print(ans)
