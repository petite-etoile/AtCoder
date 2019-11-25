N = int(input())
s=[input() for i in range(N)]
ans=0
for st in s:
    ans+= st.count("AB")

a_cnt=0
b_cnt=0
ab_cnt=0
for i in range(N):
    if s[i][-1]=="A":
        a_cnt+=1
    if s[i][0]=="B":
        b_cnt+=1
    if s[i][-1]=="A" and s[i][0]=="B":
        ab_cnt+=1
ans+=min(a_cnt,b_cnt)
if ab_cnt==b_cnt==a_cnt:
    if ab_cnt!=0:
        ans-=1

print(ans)



