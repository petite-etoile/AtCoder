N,M,*a=map(int,open(0).read().split())
a.sort(reverse=True)
cnt=0
for i in range(N):
    M-=a[i]
    cnt+=1
    if M<=0:
        break
print(cnt)