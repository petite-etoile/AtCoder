
N,K=map(int,input().split())
S=input()
shakutori_mushi=[]
now = 0
for s in S:
    if s=="(":
        now+=1
    else:
        now-=1
    shakutori_mushi.append(now)
shakutori_mushi.sort(reverse=True)
ans=0
for i in range(K):
    ans+=shakutori_mushi[i]
print(ans)
