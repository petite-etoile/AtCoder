A,B,C,K = map(int,input().split())
ans = (A-B) * pow(-1,K&1)
print(ans)