from math import ceil
N,A=map(int,input().split())
#N/3 チーム
minx=ceil(A/3)
maxx=min(N//3,A)
print(minx,maxx)