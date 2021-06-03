N, K = map(int, input().split())
ans = "YNEOS"
print(ans[(N+1)//2 < K::2])
