import math
N = int(input())
ans=0
for i in range(1,int(math.sqrt(N)+1)):
    if i==N:
        continue
    if N//(N//i-1)!=N%((N//i-1)):
        continue
    else:
        #print(i,N//i-1,N//(N//i-1),N%((N//i-1)))
        ans+=N//i-1
print(ans)
